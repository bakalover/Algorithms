#include <vector>
#include <iostream>
#include <stdint.h>
#include <cmath>
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
        for (size_t i = 0; i < arr.size(); i++)
        {
            set(i,arr[i]);
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
        if(lx>=l&&rx<=r&&rx-lx==1){
            return data[x]*pow(-1,l-lx);
        }
        return sum(l,r,2*x+1,lx,(lx+rx)/2)+sum(l,r,2*x+2,(lx+rx)/2,rx);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t n,m,type,u,v;

    cin>>n;

    vector<int64_t> data(n);

    for (size_t i = 0; i < n; i++)
    {
        cin>>data[i];
    }
    
    segtree tree;
    tree.construct(data);
    cin>>m;
    for (size_t i = 0; i < m; i++)
    {
        cin>>type>>u>>v;
        if(type==0){
            tree.set(u-1,v);
        }
        else{
            cout<<tree.sum(u-1,v)<<'\n';
        }
    }
    
    return 0;
}