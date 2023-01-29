#include<bits/stdc++.h>
using namespace std;

int main(){
    int16_t n,e,ans=0;
    cin>>n;
    for (size_t i = 0; i < n*n; i++)
    {
        cin>>e;
        if(e) ++ans;
    }
    cout<<ans/2;
    return 0;
}