#include <iostream>
#include <vector>
using namespace std;
int n, q, t, x, y;
 
int get(int v, int* parent){
    return parent[v]=(v==parent[v]?v:get(parent[v],parent));
}
 
void unionSet(int v, int u, int* parent)
{
    v = get(v, parent);
    u = get(u, parent);
    parent[v] = u;
}
 
/*void binUnion(int v[], int u[], int* p){
    if(v.size()==1){
        
    }
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    int parent[n+1] = {0};
    for (int i = 0; i < n+1; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < q; i++) {
        cin >> t >> x >> y;
        if(t==1){
            unionSet(x,y,parent);
        }
        if(t==2){ // union by binary search
            for (size_t i = x; i < y; i=i+2)
            {
                unionSet(i,i+1,parent);
            }
        }
        if(t==3){
            if(get(x,parent)==get(y,parent)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    
}
 
 