#include <iostream>
#include <vector>
using namespace std;
int count = 0;

int get(int v, int* parent,int* relation){ //Using stack to store local on each level
    int local = count;
    count += relation[v];
    parent[v] = (v==parent[v]?v:get(parent[v],parent,relation));
    relation[v] = count - local;
    return parent[v];
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
    int relation[n+1]={0};
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
            count = 0;
            get(a,parent,relation);
            ans.push_back(relation[a]);
        }
    }
    for(int x: ans){
            cout<<x<<endl;
    }
    
}