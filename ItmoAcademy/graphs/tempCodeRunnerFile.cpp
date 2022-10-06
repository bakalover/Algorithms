#include<iostream>
#include<array>
#include<cstring>
using namespace std;

int main(){
    size_t t,n,m,u,v;
    bool check;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n>>m;
        int arr[n][n];
        memset(arr,0,sizeof arr);
        check = true;
        for (size_t  k = 0; k < m; k++)
        {
            cin>>u>>v;
            if ((u==v||arr[u][v]!=0)&&check!=false)
            {
            cout<<"NO"<<endl;
            check = false;
            }
            ++arr[u][v];
        }
        if (check)
        {
            cout<<"YES"<<endl;
        }
        
    }
    
}