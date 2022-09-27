#include <iostream>
using namespace std;

int n, v;
int Get(int v, int* p);
int Union(int v, int u, int* p);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int p[n+2] = {0};
    int ans[n+1] = {0};
    for (size_t i = 0; i < n+1; i++)
    {
        p[i] = i;
    }
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> v;
        ans[i] = Union(v,v+1,p);
    }
    for (size_t i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
}

int Get(int v, int* p){
    return p[v] = (v==p[v]?v:Get(p[v],p));
}

int Union(int v, int u, int* p){
    v = Get(v,p);
    u = Get(u,p);
    cout<<v<<u<<endl;
    p[v] = u;
    return u;
}
