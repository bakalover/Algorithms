#include<iostream>
#include<array>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
int main(){
    int t,n,m,u,v;
    bool check;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        check = true;
        cin>>n>>m;
        vector<set<int>> degs;
        degs.resize(n+1);
        for (size_t j = 0; j < m; j++)
        {
            cin>>u>>v;
            if(u==v){
                check=false;
            }
            size_t u_s = degs.at(u).size();
            degs.at(u).insert(v);
            degs.at(v).insert(u);
            if (u_s==degs.at(u).size())
            {
                check = false;
            }
            
        }
        
        if (check)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}