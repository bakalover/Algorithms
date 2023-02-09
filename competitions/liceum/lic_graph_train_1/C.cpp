#include<bits/stdc++.h>
using namespace std;

void jump(vector<bool> &visited,vector<int32_t> &likes, int32_t v, int32_t &cnt, int32_t start){ 
    if(v==start) return;
    ++cnt;
    visited[v]=true;
    jump(visited,likes,likes[v],cnt,start);
}

int main(){
    int32_t n,cnt;
    cin>>n;
    vector<bool> visited(n+1);
    vector<int32_t> likes(n+1);
    for (size_t i = 1; i <= n; i++)
    {
        cin>>likes[i];
    }
    for (size_t i = 1; i <= n; i++)
    {
        cnt = 1;
        if(!visited[i]){
            jump(visited,likes,likes[i],cnt,i); // Группа перестановок конечна (ord!=inf) -> гарантия завершения рекурсии
        }
        if(cnt==3){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    
    cout<<"NO"<<endl;
    return 0;
}
