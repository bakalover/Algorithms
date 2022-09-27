#include <iostream>
using namespace std;
int n, v;
 
int get(int v, int* parent){
    return parent[v]=(v==parent[v]?v:get(parent[v],parent));
}
 
int unionSet(int v, int u, int* parent)
{
    if(u==0) ++u;
    v = get(v, parent);
    u = get(u, parent);
    parent[v] = u;
    return v;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int parent[n+1] = {0};
    int ans[n+1] = {0};
    for (int i = 0; i < n+1; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> v;
        cout << unionSet(v,(v+1)%(n+1), parent) << " ";
    }
    
}
 
 