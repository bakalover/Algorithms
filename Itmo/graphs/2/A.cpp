#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(int64_t ans,int64_t n){
    return ans*(ans-1)/2>=n;
}
int main(){
    int64_t t,m;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (int64_t i = 0; i < t; i++)
    {
        cin>>m;
        cout<< ceil(0.5 * (sqrt(8*m+1)+1))<<'\n';
    }
    
    return 0;
}