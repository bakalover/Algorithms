#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t t,n,m,mn,id=1,count=0;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        count=0;
        cin>>n>>m;
        vector<int64_t> pref(n+1);
        cin>>pref[1];
        mn=pref[1];
        for (size_t j = 2; j <= n; j++)
        {
            cin>>pref[i];
            pref[i]+=pref[i-1];
            if(pref[i]<mn){
                mn = pref[i];
                id = i;
            }
        }
        if(i==m){
            cout<<0<<'\n';
        }
        else{
            if(i<m){
                vector<int64_t> prefx(m-id);
                for (size_t j = id+1; j <= m; j++)
                {
                    prefx[j-id-1]=pref[j]-pref[j-1];
                }
                sort(prefx.begin(),prefx.end(),[](int64_t a, int64_t b){return a > b;});
                int64_t delta = 0;
                int64_t k = 0;
                while(delta<=abs(mn-pref[m])){
                    if(prefx[k]>0){
                        ++count;
                        delta += (2*prefx[k]);
                    }
                }
                cout<<count<<'\n';
            }
            else{
                vector<int64_t> prefx(-m+id);
                for (size_t j = m+1; j <= id; j++)
                {
                    prefx[j-m-1]=pref[j]-pref[j-1];
                }
                sort(prefx.begin(),prefx.end(),[](int64_t a, int64_t b){return a > b;});
                int64_t delta = 0;
                int64_t k = 0;
                while(delta<=abs(mn-pref[m])){
                    if(prefx[k]>0){
                        ++count;
                        delta += (2*prefx[k]);
                    }
                }
                cout<<count<<'\n';
            }
        }
    }  
}