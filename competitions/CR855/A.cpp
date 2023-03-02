#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool check(string s, size_t i)
{
    return tolower(s[i]) != 'm' && tolower(s[i]) != 'e' && tolower(s[i]) != 'o' && tolower(s[i]) != 'w';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int32_t n, t;
    bool inner = false;
    cin >> t;
    for (size_t j = 0; j < t; j++)
    {

        cin >> n;
        cin >> s;
        inner = false;
        vector<char> arr;
        if (check(s, 0))
        {
            cout << "NO"
                 << endl;
            continue;
        }
        arr.push_back(tolower(s[0]));
        for (size_t i = 1; i < n; i++)
        {
            if (check(s, i))
            {
                inner = true;
                break;
            }
            if (tolower(s[i]) != tolower(s[i - 1]))
            {
                arr.push_back(tolower(s[i]));
            }
        }
        if (!inner && arr.size() == 4 && arr[0] == 'm' && arr[1] == 'e' && arr[2] == 'o' && arr[3] == 'w')
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}