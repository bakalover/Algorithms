#include<bits/stdc++.h>
using namespace std;

namespace generic {
    template <typename T>
    void calculate_c(vector<int32_t> &p,vector<int32_t> &c,vector<pair<T,int64_t>> &arr){
        for (size_t i = 1; i < c.size(); i++)
        {
            if(arr[i].first==arr[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = c[p[i-1]]+1;
            }
        }
    }
    template <typename T>
    void calculate_p(vector<int32_t> &p,vector<pair<T,int64_t>> &arr){
        for (size_t i = 0; i < p.size(); i++)
        {
            p[i] = arr[i].second;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    s+='$';

    int32_t n = s.size(),k=0;

    vector<pair<char,int64_t>> arr(n);
    vector<int32_t> p(n), c(n);


    for (size_t i = 0; i < n; i++)
    {
        arr[i] = {s[i],i};
    }

    sort(arr.begin(),arr.end());

    generic::calculate_p(p,arr);

    c[p[0]] = 0;

    generic::calculate_c(p,c,arr);

    while((1<<k)<n){
        vector<pair<pair<int64_t,int64_t>,int64_t>> ind_arr(n);

        for (size_t i = 0; i < ind_arr.size(); i++)
        {
            ind_arr[i] = {{c[i],c[(i+(1<<k))%n]},i};
        }

        sort(ind_arr.begin(),ind_arr.end());

        generic::calculate_p(p,ind_arr);

        generic::calculate_c(p,c,ind_arr);
        
        ++k;
    }

    for (size_t i = 0; i < p.size(); i++)
    {
        cout<<p[i]<<endl;
    }
    
    return 0;
}