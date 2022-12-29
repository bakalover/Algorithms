#include <vector>
#include <iostream>
#include <stdint.h>
#include <algorithm>
using namespace std;


struct segtree{
    vector <uint32_t> data;
    uint32_t size;

    void init(uint32_t n){
        size = 1;
        while (size<n)
        {
            size*=2;
        }
        data.assign(2*size,0);
    }

    void construct(vector<uint32_t> &arr){
        init(arr.size());
        for (size_t i = 0; i < arr.size(); i++)
        {
            set(i,arr[i]);
        }
        
    }
    
    void set(uint32_t i, uint32_t v){
        set(i,v,0,0,size);
    }

    void set(uint32_t i, uint32_t v, uint32_t x, uint32_t l, uint32_t r){
        if(r-l==1){
            data[x] = v;
            return;
        }
        uint32_t m = (l+r)/2;
        if(i<m){
            set(i,v,2*x+1,l,m);
        }
        else{
            set(i,v,2*x+2,m,r);
        }
        data[x] = data[2*x+1] + data[2*x+2];
    }

    uint32_t sum(uint32_t l, uint32_t r){
        return sum(l,r,0,0,size);
    }

    uint32_t sum(uint32_t l, uint32_t r, uint32_t x, uint32_t lx, uint32_t rx){
        if(l>=rx||r<=lx){
            return 0;
        }
        if(lx>=l&&rx<=r){
            return data[x];
        }
        return sum(l,r,2*x+1,lx,(lx+rx)/2)+sum(l,r,2*x+2,(lx+rx)/2,rx);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    uint32_t n;

    cin>>n;

    vector<uint32_t> data(2*n);
    vector<uint32_t> l_borders(n+1,-1);
    vector<pair<uint32_t,uint32_t>> ans;
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
            ans.push_back(make_pair(data[i],(i-1-l_borders[data[i]]) - 2*tree.sum(l_borders[data[i]],i)));
            tree.set(l_borders[data[i]],1);
        }
    }
    sort(ans.begin(),ans.end(),[](pair<uint32_t,uint32_t> x, pair<uint32_t,uint32_t> y){return x.first<y.first;});
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout<<ans[i].second<<" ";
    }
    
    return 0;
}