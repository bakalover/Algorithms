#include <iostream>
#include <cstring>
#include <set>
#include <functional>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t t, n;
    hash<string> hash;
    string s;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        set<size_t> set;
        cin >> n;
        cin >> s;
        for (size_t j = 0; j <= n-2; j++)
        {
            set.insert(hash(s.substr(0,j) + s.substr(j + 2, s.size())));
        }
        cout << set.size() << '\n';
    }
    return 0;
}