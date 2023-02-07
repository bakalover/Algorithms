#include<iostream>
#include<array>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
int main(){
    int t,n,m,u,v;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n>>m;
        vector<set<int>> degs;
        degs.resize(n+1);
        for (size_t j = 0; j < m; j++)
        {
            cin>>u>>v;
            degs.at(u).insert(v);
            degs.at(v).insert(u);
            
        }
        for (size_t i = 1; i < degs.size(); i++)
        {
            cout<<degs.at(i).size()<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}