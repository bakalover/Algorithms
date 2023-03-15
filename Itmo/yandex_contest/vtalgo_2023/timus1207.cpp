#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct dot
{
    size_t i;
    double x;
    double y;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t n;
    double x, y;
    double x_min = 10000000000, y_min = 1000000000000;
    size_t i_min;
    vector<pair<uint16_t, double>> arr;
    vector<struct dot> coord;

    cin >> n;

    for (size_t i = 1; i <= n; i++)
    {
        cin >> x >> y;
        coord.push_back((struct dot){.i = i, .x = x, .y = y});
        if (x < x_min && y < y_min)
        {
            i_min = i;
            x_min = x;
            y_min = y;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        auto p = coord[i];
        if (p.x != x_min || p.y != y_min)
        {
            arr.push_back(make_pair(p.i, (p.y - y_min + 0.5) / (p.x - x_min + 0.5)));
        }
    }

    sort(arr.begin(), arr.end(), [](auto &p1, auto &p2)
         { return p1.second > p2.second; });

    cout << i_min << " " << arr[(arr.size() - 1) / 2].first << endl;

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