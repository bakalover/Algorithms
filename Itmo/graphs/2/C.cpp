#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

 
void union_vertex(int64_t v, int64_t u,int64_t* degs)
{
    ++degs[v];
    ++degs[u];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t t,n,m,u,v;
    int64_t full,blank;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n>>m;
        int64_t degs[n+1];
        for (size_t j = 0; j < n+1; j++)
        {
            degs[j]=0;
        }
        for (size_t j = 0; j < m; j++)
        {
            cin>>u>>v;
            union_vertex(u,v,degs);
        }
        full=0;
        blank=0;
        for (size_t j = 1; j < n+1; j++)
        {
            if(degs[j]==0){++blank;}
        }
        for (size_t j = 1; j < n+1; j++)
        {
             if(degs[j]==n-blank-1){++full;}
        }
        
        if(full+blank==n){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
        
        
    }
    
    return 0;
}