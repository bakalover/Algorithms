#include <iostream>
using namespace std;
int n, m, v;
char req;

 
int get(int v, int* parent){
    return parent[v]=(v==parent[v]?v:get(parent[v],parent));
}
 
void unionSet(int v, int u, int* parent)
{
    v = get(v, parent);
    u = get(u, parent);
    parent[v] = u;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int parent[n+2] = {0};
    for (int i = 0; i < n+2; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> req >> v;
        if(req=='-'){
            unionSet(v,v+1, parent);
        }
        else{
            v = get(v,parent);
            if(v==n+1){
                cout<<-1<<'\n';
            }
            else{
                cout<<v<<'\n';
            }
        }
    }
    
}
 
 