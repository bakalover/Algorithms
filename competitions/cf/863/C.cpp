#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t t, n;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        cin >> n;
        vector<int32_t> arr(n);
        vector<int32_t> ans(n);
        for (size_t i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
        }
        ans[0] = arr[0];
        for (size_t i = 1; i < n - 1; i++)
        {
            ans[i] = min(arr[i - 1], arr[i]);
        }
        ans[n - 1] = arr[n - 2];
        for (size_t i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}