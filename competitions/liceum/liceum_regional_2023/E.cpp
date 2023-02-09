#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t n,k,ans,all;
    cin>>n>>k;
    vector<int64_t> arr(n + 2*k +2); 

    cin>>arr[k+1];

    for (size_t i = k+2; i <= n+2*k; i++)
    {
        if(i<=n+k){
           cin>>arr[i];
        }
        arr[i] += arr[i-1];
    }
    all = arr[n+2*k];
    ans = arr[n+2*k];
    for (int64_t i = k+1; i <= n+k; i++)
    {
        if(i-k<=k){
            if(arr[i+k] - arr[i-k-1] < (i-k+1)*(arr[i] - arr[i-1]) && all + ((i-k+1)*(arr[i] - arr[i-1]) - (arr[i+k] - arr[i-k-1])) > ans){
                ans = all + ((i-k+1)*(arr[i] - arr[i-1]) - (arr[i+k] - arr[i-k-1]));
            }
        }
        else{
            if(n+k-i+1<=k){
                if(arr[i+k] - arr[i-k-1] < (n+k-i+2)*(arr[i] - arr[i-1]) && all + ((n+k-i+2)*(arr[i] - arr[i-1]) - (arr[i+k] - arr[i-k-1])) > ans){
                    ans = all + ((n+k-i+1)*(arr[i] - arr[i-1]) - (arr[i+k] - arr[i-k-1]));
                }
            }
            else{
                if(arr[i+k] - arr[i-k-1] < (2*k + 1)*(arr[i] - arr[i-1]) && all + ((2*k+1)*(arr[i] - arr[i-1]) - (arr[i+k] - arr[i-k-1])) > ans){
                    ans = all + ((2*k + 1)*(arr[i] - arr[i-1]) - (arr[i+k] - arr[i-k-1]));
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}