#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t ans, t, n, s_i;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        priority_queue<int32_t> spells;
        ans = 0;
        cin >> n;
        for (size_t j = 0; j < n; j++)
        {
            cin >> s_i;
            if(s_i>0){
                spells.push(s_i);
            }
            else{
                if(!spells.size()==0){
                    ans += spells.top();
                    spells.pop();
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}