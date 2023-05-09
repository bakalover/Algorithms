#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int64_t n = 0, ans = 0;
    cin >> n;
    vector<vector<int64_t>> arr(n, vector<int64_t>(6, 0));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i != j)
            {
                for (size_t p = 0; p < 6; p++)
                {
                    for (size_t q = 0; q < 6; q++)
                    {
                        ans += max(arr[i][p], arr[j][q]) * max(arr[i][p], arr[j][q]) * max(arr[i][p], arr[j][q]);
                    }
                }
            }
        }
    }
    cout << ans / (n * 36.0 * (n - 1)) << endl;
    return 0;
}