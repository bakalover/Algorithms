#include<iostream>
#include<array>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
int main(){
    int t,n,m,k,u,v;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        bool check = true;
        cin>>n>>m>>k;
        int degs[n+1][n+1];
        int count[n+1];
        memset(count,0,sizeof count);
        memset(degs,0,sizeof degs);
        vector<int> vertex;
        for(size_t j = 0; j < k; j++){
            cin>>u;
            ++count[u];
            vertex.push_back(u);
        }
        for (size_t j = 0; j < m; j++)
        {
            cin>>u>>v;
            ++degs[u][v];
            ++degs[v][u];            
        }
        for (size_t j = 1; j < k; j++)
        {
            if(degs[vertex.at(j)][vertex.at(j-1)]==0){
                check = false;
                break;
            }
        }
        if(!check){
            cout<<"none"<<endl;
        }
        else{
            bool checkSimple = true;
            if((vertex.at(0)==vertex.at(vertex.size()-1)) && k>2){
                for (size_t j = 0; j < n+1; j++)
                {
                    if(count[j]>1&&j!=vertex.at(0)){
                        checkSimple = false;
                    }
                }
                if(checkSimple){
                    cout<<"simple cycle"<<endl;
                }
                else{
                    cout<<"cycle"<<endl;
                }
                
            }
            else{
                for (size_t j = 0; j < n+1; j++)
                {
                    if(count[j]>1){
                        checkSimple = false;
                    }
                }
                if(checkSimple){
                    cout<<"simple path"<<endl;
                }
                else{
                    cout<<"path"<<endl;
                }
            }
        }
        
    }
    return 0;
}