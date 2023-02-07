#include<iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int64_t t,n,m,u,v,c_in,c_out;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (int64_t i = 0; i < t; i++)
    {
        cin>>n>>m;
        int64_t in[n+1];
        int64_t out[n+1];
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for (size_t j = 0; j < m; j++)
        {
            cin>>u>>v;
            ++out[u];
            ++in[v];
        }
        c_in=0;
        c_out=0;
        for (size_t j = 1; j < n+1; j++)
        {
            if(out[j]==0){++c_in;}
            if(in[j]==0){++c_out;}
        }
        cout<<c_out<<" "<<c_in<<'\n';
        
    }
    
    return 0;
}