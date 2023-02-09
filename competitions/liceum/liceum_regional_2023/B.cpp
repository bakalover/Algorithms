#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n,k,ans=0;
    int64_t a_i;
    cin>>n>>k;
    vector<int16_t> Z_n(k);
    for (size_t i = 0; i < n; i++)
    {
        cin>>a_i;
        if(a_i<k){
            ++Z_n[a_i];
        }
    }
    for (int64_t i = 1; i <= k/2; i++)
    {
       // cout<<i<<" "<<k-i<<endl;
       if(k-i == i){
        ans+= Z_n[i]/2;
       }
       else{
        ans += min(Z_n[i],Z_n[k-i]);
       }
    }
    cout<<ans<<endl;
    
    
    return 0;
}