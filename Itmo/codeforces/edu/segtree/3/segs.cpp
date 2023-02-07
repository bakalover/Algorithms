#include <vector>
#include <iostream>
#include <stdint.h>
#include <algorithm>
using namespace std;


struct segtree{
    vector <int64_t> data;
    int64_t size;

    void init(int64_t n){
        size = 1;
        while (size<n)
        {
            size*=2;
        }
        data.assign(2*size,0);
    }

    void construct(vector<int64_t> &arr){
        init(arr.size());
        construct(arr,0,0,size);
    }
    
    void construct(vector<int64_t> &arr,int64_t x,int64_t l,int64_t r){
        if(r-l==1){
            if(l<arr.size()){
                data[x] = arr[l];
            }
            else{
                data[x] = 0;
            }
        }
        else{
            int64_t m = (l+r)/2;
            construct(arr,2*x+1,l,m);
            construct(arr,2*x+2,m,r);
            data[x] = data[2*x+1] + data[2*x+2];
        }
    }

    void set(int64_t i, int64_t v){
        set(i,v,0,0,size);
    }

    void set(int64_t i, int64_t v, int64_t x, int64_t l, int64_t r){
        if(r-l==1){
            data[x] = v;
            return;
        }
        int64_t m = (l+r)/2;
        if(i<m){
            set(i,v,2*x+1,l,m);
        }
        else{
            set(i,v,2*x+2,m,r);
        }
        data[x] = data[2*x+1] + data[2*x+2];
    }

    int64_t sum(int64_t l, int64_t r){
        return sum(l,r,0,0,size);
    }

    int64_t sum(int64_t l, int64_t r, int64_t x, int64_t lx, int64_t rx){
        if(l>=rx||r<=lx){
            return 0;
        }
        if(lx>=l&&rx<=r){
            return data[x];
        }
        int64_t m = (lx+rx)/2;
        return sum(l,r,2*x+1,lx,m)+sum(l,r,2*x+2,m,rx);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t n;

    cin>>n;

    vector<int64_t> data(2*n);
    vector<int64_t> l_borders(n+1,-1);
    vector<pair<int64_t,int64_t>> ans;
    segtree tree;
    tree.construct(data);

    for (size_t i = 0; i < 2*n; i++)
    {
        cin>>data[i];
    }
    

    for (size_t i = 0; i < 2*n; i++)
    {
        if(l_borders[data[i]]==-1){
            l_borders[data[i]]=i;
        }
        else{
            ans.push_back(make_pair(data[i],tree.sum(l_borders[data[i]],i)));
            tree.set(l_borders[data[i]],1);
        }
    }
    sort(ans.begin(),ans.end(),[](pair<int64_t,int64_t> x, pair<int64_t,int64_t> y){return x.first<y.first;});
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout<<ans[i].second<<" ";
    }
    
    return 0;
}