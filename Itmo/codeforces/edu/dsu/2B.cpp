#include <iostream>
using namespace std;
 
long n;
long p[300500];
long Get(long v);
long Union(long v, long u);
 
int main(){
    long v;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    //long p[n+1] = {0};
    long ans[n+1] = {0};
    for (size_t i = 0; i < n+1; i++)
    {
        p[i] = i;
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> v;
        if(v==n){ans[i] = Union(v,1);}
        else{ans[i] = Union(v,v+1);}
    }
    for (size_t i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
 
long Get(long v){
    return p[v] = (v==p[v]?v:Get(p[v]));
}
 
long Union(long v, long u){
    v = Get(v);
    u = Get(u);
    if(u==v){
        if(u==n){
            u = Get(1);
        }
        else{
            u = Get(u+1);
        }
    }
    p[v] = u;
    return v;
}