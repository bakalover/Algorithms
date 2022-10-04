#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct edge{
    int u;
    int v;
    int w;
};


int get(int v, int* p){
    return p[v]=(v==p[v]?v:get(p[v],p));
}
 
void unionSet(int v, int u, int* p, int* rank)
{
    v = get(v, p);
    u = get(u, p);
    if (rank[v]==rank[u]){
        ++rank[v];
    }
    if(rank[v]>rank[u]){
        p[u] = v;
    }
    else{
        p[v] = u;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    long long weight = 0;
    cin >> n >> m;
    int p[n+1] = {0};
    int rank[n+1] = {0};
    vector<edge> edges;

    for (int i = 0; i < n+1; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }
   sort(edges.begin(),edges.end(),[](edge a, edge b){return a.w < b.w;});
    for(edge e: edges){
        if(get(e.u,p)!=get(e.v,p)){
            unionSet(e.u,e.v,p,rank);
            weight+=e.w;
        }
    }
    cout<<weight<<endl;
}