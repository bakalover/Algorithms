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

    int64_t t,n,m,k,a_i,u,v;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n>>m>>k;
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

        set<int64_t> checking_set;
        for (size_t j = 0; j < k; j++)
        {
            cin>>a_i;
            checking_set.insert(a_i);
        }
        for (size_t j = 0; j < m; j++)
        {
            cin>>u>>v;
            union_vertex(u,v,parent,rank);
        }
        
        set<int64_t> leaders;
        for (int64_t el : checking_set)
        {
            leaders.insert(get_leader(el,parent));
            --rank[get_leader(el,parent)];
        }
        
        bool check = true;
        for(int64_t el : leaders){
            if(rank[el]>0){
                cout<<"NO"<<endl;
                check = false;
                break;
            }
        }
        if(check){
            cout<<"YES"<<endl;
        }
        
    }
    
    return 0;
}