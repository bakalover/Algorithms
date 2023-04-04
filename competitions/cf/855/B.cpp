#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t t, n, k, add_cur, all_cur;
    string s;

    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        cin >> n >> k >> s;
        map<char, int32_t> map;
        add_cur = 0;
        all_cur = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (map.find(s[i]) == map.end())
            {
                if (islower(s[i]))
                {
                    map.insert(make_pair(s[i], 1));
                    map.insert(make_pair(toupper(s[i]), 0));
                }
                else
                {
                    map.insert(make_pair(s[i], 1));
                    map.insert(make_pair(tolower(s[i]), 0));
                }
            }
            else
            {
                ++map[s[i]];
            }
        }
        for (auto &el : map)
        {
            if (isupper(el.first))
            {
                all_cur += min(el.second, map[tolower(el.first)]);
                add_cur += abs(el.second - map[tolower(el.first)]) / 2;
            }
            else{
                cout << all_cur + min(k, add_cur) << endl;
                break;
            }
            
        }
    }

    return 0;
}