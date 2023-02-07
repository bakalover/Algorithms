#include<iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int64_t t,n,m,u,v;
    int64_t delta;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (int64_t i = 0; i < t; i++)
    {
        cin>>n>>m;
        int64_t out[n+1];
        memset(out,0,sizeof(out));
        for (size_t j = 0; j < m; j++)
        {
            cin>>u>>v;
            ++out[u];
        }
        delta = 0;
        for (size_t j = 1; j < n+1; j++)
        {
            delta += abs(out[j]-1);   
        }
        cout<<delta<<'\n';
        
    }
    
    return 0;
}