#include<iostream>
#include<array>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    short int t,n,m,u,v;
    bool check;
    cin>>t;
    for (short int i = 0; i < t; i++)
    {
        cin>>n>>m;
        //vector<pair<short int, char>> degs[n+1];
        byte degs[n][m];
        memset(degs,0,sizeof degs);
        check = true;
        for (short int k = 0; k < m; k++)
        {
            cin>>u>>v;
            if (u==v||degs[u][v]==(byte)1)
            {
            check = false;
            }
           // degs[u].push_back(make_pair(v,(char)1));
            // degs[v].push_back(make_pair(u,(char)1));
            degs[v][u]=(byte)1;
            degs[v][u]=(byte)1;
        }
        if (check)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
}