#include <iostream>
#include <vector>
//#include <algorithm>
#include <cmath>
using namespace std;


struct dot
{
    size_t i;
    double x;
    double y;
};

struct angdot
{
    size_t i;
    double ang;
};

void merge(vector<struct angdot> &arr, vector<struct angdot> &help, size_t l, size_t m, size_t r, bool (*func)(struct angdot &p1, struct angdot &p2))
{
    size_t i = l;
    size_t j = m + 1;
    for (size_t k = l; k <= r; k++)
    {
        if (i > m)
        {
            arr[k] = help[j++];
            continue;
        }
        if (j > r)
        {
            arr[k] = help[i++];
            continue;
        }
        if ((func)(help[j], help[i]))
        {
            arr[k] = help[j++];
        }
        else
        {
            arr[k] = help[i++];
        }
    }
}

void merge_sort(vector<struct angdot> &arr, vector<struct angdot> &help, size_t l, size_t r, bool (*func)(struct angdot &p1, struct angdot &p2))
{
    if (l < r)
    {
        size_t m = (l + r) / 2;
        merge_sort(help, arr, l, m, func);
        merge_sort(help, arr, m + 1, r, func);
        merge(arr, help, l, m, r, func);
    }
}

void sort(vector<struct angdot> &arr, bool (*func)(struct angdot &p1, struct angdot &p2))
{
    vector<struct angdot> help(arr);
    merge_sort(arr, help, 0, arr.size() - 1, func);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t n, i_min;
    double x, y, ang, x_min = 10e6 + 1, y_min = 10e6 + 1;
    vector<struct dot> coord;
    vector<struct angdot> coord_rel_min;

    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> x >> y;
        coord.push_back((struct dot){.i = i, .x = x, .y = y});

        if (y <= y_min)
        {
            i_min = i;
            x_min = x;
            y_min = y;
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        if (coord[i].x != x_min || coord[i].y != y_min)
        {

            ang = atan2(coord[i].y - y_min, coord[i].x - x_min);
            //ang *= 10e9;
            coord_rel_min.push_back((struct angdot){.i = coord[i].i, .ang = ang});
        }
    }
    // cout << x_min << " " << y_min << endl;
    // cout << "SIZE:: " << arr.size() << endl;
    sort(coord_rel_min, [](auto &p1, auto &p2){ return p1.ang < p2.ang; });

    cout << i_min << " " << coord_rel_min[(coord_rel_min.size() - 1) / 2].i << endl;

    return 0;
}
// 8
// -2 -3
// -2 -1
// 0 -2
// 1 -1
// 2 1
// 1 2
// -1 1
// 3 3

// 8
// -2 -3
// -2 -1
// 0 -26
// 1 -1
// 3 1
// 1 2
// -1 1
// 3 3