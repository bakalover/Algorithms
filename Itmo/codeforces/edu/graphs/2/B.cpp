#include<iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
int main(){
    int64_t n,k,t;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (int64_t i = 0; i < t; i++)
    {
        cin>>n>>k;
        if(n*k%2==1||k>n-1){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
            cout<<n*k/2<<'\n';
            set<pair<int64_t,int64_t>> edges;
            vector<int64_t> degs(n+1);
            for (size_t j = 1; j < n; j++)
            {
                for (size_t k = j+1; k <= n; k++)
                {
                    edges.insert(make_pair(j,k));
                }
                
            }
            for (size_t j = 1; j < degs.size(); j++)
            {
                degs[j] = n-1;
            }
            for (auto it = edges.begin(); it!= edges.end();)
            {
                if(degs[(*it).first]==k||degs[(*it).second]==k){
                    ++it;
                    continue;
                }
                --degs[(*it).first];
                --degs[(*it).second];
                it = edges.erase(it);
            }
            for( auto edge : edges){
                cout<<edge.first<<" "<<edge.second<<'\n';
            }
            
        }
    }
    
    return 0;
}