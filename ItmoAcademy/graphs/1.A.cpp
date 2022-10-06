#include<iostream>
#include<array>
using namespace std;

int main(){
    size_t t,n,m;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        int arr[n][m] = {0};
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<'\n';
        }
        
    }
    
}