#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t t, n;
    string s, d;

    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        string mx = "0";
        cin >> n >> d >> s;
        for (size_t i = 0; i <= n; i++)
        {
            if (s.substr(0, i) + d + s.substr(i, n - i) > mx)
            {
                mx = s.substr(0, i) + d + s.substr(i, n - i);
            }
        }
        cout << mx << endl;
    }

    return 0;
}