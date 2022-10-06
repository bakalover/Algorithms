#include<iostream>
#include<array>
#include<cstring>
using namespace std;

int main(){
    short int t,n,m,u,v;
    bool check;
    cin>>t;
    for (short int i = 0; i < t; i++)
    {
        cin>>n>>m;
        short int arr[n+1][n+1];
        memset(arr,0,sizeof arr);
        check = true;
        for (short int k = 0; k < m; k++)
        {
            cin>>u>>v;
            if (u==v||arr[u][v]!=0)
            {
            check = false;
            }
            ++arr[u][v];
            ++arr[v][u];
        }
        if (check)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        free(arr);
    }
    
}