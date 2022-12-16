#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int64_t t, n, sum, d_i;
    bool check_invalid_deg;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n;
        sum=0;
        check_invalid_deg=false;
        for (size_t j = 0; j < n; j++)
        {
            cin>>d_i;
            if(d_i==0 && n!=1){
                check_invalid_deg = true;
            }
            sum+=d_i;
        }
        if(sum == 2*n - 2 && !check_invalid_deg){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}