#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> arr;
    string s;

    while (cin >> s)
    {
        arr.push_back(s);
    }

    sort(arr.begin(), arr.end(), [](string s1, string s2)
         { return s1 + s2 > s2 + s1; });

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }

    return 0;
}
// 004
// 05
// 06
// 066
// 2
// 22
// 20
// 23
// 60
// 6
// 68
// 67