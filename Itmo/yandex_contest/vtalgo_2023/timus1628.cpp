#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int32_t find(vector<int32_t> &arr, int32_t x)
{
    int32_t l = -1, r = arr.size();
    while (r > l + 1)
    {
        int32_t mid = (l + r) / 2;
        if (arr[mid] <= x)
            l = mid;
        if (arr[mid] > x)
            r = mid;
    }
    return arr[l];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t n, m, k, x, y, delta;
    size_t all = 0, isolated_squares = 0;

    cin >> m >> n >> k;

    vector<vector<int32_t>> Rows(m + 2, vector<int32_t>());
    vector<vector<int32_t>> Columns(n + 2, vector<int32_t>());

    for (size_t i = 0; i < Rows.size(); i++)
    {
        Rows[i].push_back(0);
        Rows[i].push_back(n + 1);
    }

    for (size_t i = 0; i < Columns.size(); i++)
    {
        Columns[i].push_back(0);
        Columns[i].push_back(m + 1);
    }

    for (size_t i = 0; i < k; i++)
    {
        cin >> x >> y;
        Rows[x].push_back(y);
        Columns[y].push_back(x);
    }

    for (size_t i = 0; i < Rows.size(); i++)
    {
        sort(Rows[i].begin(), Rows[i].end());
    }

    for (size_t i = 0; i < Columns.size(); i++)
    {
        sort(Columns[i].begin(), Columns[i].end());
    }

    for (size_t i = 1; i <= m; i++)
    {
        for (size_t j = 1; j < Rows[i].size(); j++)
        {
            delta = Rows[i][j] - Rows[i][j - 1];
            if (delta == 1)
            {
                continue;
            }
            if (delta == 2)
            {
                if ((find(Rows[i - 1], Rows[i][j - 1] + 1) == Rows[i][j - 1] + 1 || i - 1 == 0) && (find(Rows[i + 1], Rows[i][j - 1] + 1) == Rows[i][j - 1] + 1 || i + 1 == m + 1))
                {
                    ++all;
                    ++isolated_squares;
                }
                continue;
            }
            ++all;
        }
    }

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j < Columns[i].size(); j++)
        {
            delta = Columns[i][j] - Columns[i][j - 1];
            if (delta == 1)
            {
                continue;
            }
            if (delta == 2)
            {
                if ((find(Columns[i - 1], Columns[i][j - 1] + 1) == Columns[i][j - 1] + 1 || i - 1 == 0) && (find(Columns[i + 1], Columns[i][j - 1] + 1) == Columns[i][j - 1] + 1 || i + 1 == n + 1))
                {
                    ++all;
                    ++isolated_squares;
                }
                continue;
            }
            ++all;
        }
    }
    cout << all - isolated_squares / 2 << endl;

    return 0;
}
// 3 5 5
// 1 1
// 1 5
// 2 2
// 3 3
// 3 1