#include <iostream>
#include <vector>
using namespace std;
int n, q, t, x, y;
 
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
 
void binUnion(int l, int r, int* p, int* rank){  
    if(l!=r){
        binUnion(l, (l+r)/2, p, rank);
        binUnion((l+r)/2+1, r, p, rank);
        unionSet(l, (l+r)/2 + 1, p, rank);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    int p[n+1] = {0};
    int rank[n+1] = {0};
    for (int i = 0; i < n+1; i++) {
        p[i] = i;
    }
    for (int i = 0; i < q; i++) {
        cin >> t >> x >> y;
        if(t==1){
            unionSet(x,y,p,rank);
        }
        if(t==2){ // union by binary tree
            binUnion(x,y,p,rank);
        }
        if(t==3){
            if(get(x,p)==get(y,p)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    
}
 
 