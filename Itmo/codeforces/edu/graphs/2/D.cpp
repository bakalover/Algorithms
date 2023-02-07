#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;


int64_t get_leader(int64_t v, int64_t* p){
    return p[v]=(v==p[v]?v:get_leader(p[v],p));
}
 
void union_vertex(int64_t v, int64_t u, int64_t* p, int64_t* rank)
{
    v = get_leader(v, p);
    u = get_leader(u, p);
    if(rank[v]>=rank[u]){
        if(u!=v){ rank[v] = rank[v] + rank[u];}
        p[u] = v;
    }
    else{
        if(u!=v){ rank[u] = rank[u] + rank[v];}
        p[v] = u;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t t,n,m,u,v,counter;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n>>m;
        int64_t parent[n+1];
        for (size_t j = 0; j < n+1; j++)
        {
            parent[j] = j;
        }
        int64_t rank[n+1];
        for (size_t j = 0; j < n+1; j++)
        {
            rank[j] = 1;
        }
        for (size_t j = 0; j < m; j++)
        {
            cin>>u>>v;
            union_vertex(u,v,parent,rank);
        }
        set<int64_t> clasters;
        for (size_t j = 1; j < n+1; j++)
        {
            clasters.insert(get_leader(j,parent));
        }
        cout<<clasters.size()<<'\n';
        
    }
    
    return 0;
}