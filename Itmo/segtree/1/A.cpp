#include <vector>
#include <iostream>
#include <stdint.h>
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

    uint32_t n,m,type,u,v;

    cin>>n>>m;

    vector<uint32_t> data(n);

    for (size_t i = 0; i < n; i++)
    {
        cin>>data[i];
    }
    
    segtree tree;
    tree.construct(data);

    for (size_t i = 0; i < m; i++)
    {
        cin>>type>>u>>v;
        if(type==1){
            tree.set(u,v);
        }
        else{
            cout<<tree.sum(u,v)<<'\n';
        }
    }
    
    return 0;
}