#include <iostream>
#include <vector>
using namespace std;
 
int get(int v, int* parent,int* relation){
    return relation[v] + (v==parent[v]?0:get(parent[v],parent,relation));
}
 
void unionSet(int v, int u, int* parent,int* relation)
{
    parent[v]=u;
    ++relation[v];
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    vector<int> ans;
    cin >> n >> m;
    int parent[n+1] = {0};
    int relation[n+1] = {0};
    for (int i = 0; i < n+1; i++) {
        parent[i] = i;
    }
    int t,a,b;
    for (int i = 0; i < m; i++) {
        cin >> t;
        if(t==1){
            cin>>a>>b;
            unionSet(a,b,parent,relation);
        }
        else{
            cin>>a;
            ans.push_back(get(a,parent,relation));
        }
    }
    for(int x: ans){
            cout<<x<<endl;
    }
    
}