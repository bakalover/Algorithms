#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t t,n;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n;
        if(n%2==0){
            cout<<"YES"<<'\n';
            for(size_t j = 0; j < n; j++)
            {
                cout<<pow(-1,j)<<" ";
            }
            cout<<'\n';
        }
        else{
            if(n==3){
                cout<<"NO"<<'\n';
            }
            else{
                cout<<"YES"<<'\n';
                for (size_t j = 0; j < n; j++)
                {
                    if(j%2==0){
                        cout<<3-n<<" ";
                    }
                    else{
                        cout<<n-1<<" ";
                    }
                }
                cout<<'\n';
            }
        }
    }
    
    
    
}