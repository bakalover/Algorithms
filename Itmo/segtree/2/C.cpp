#include <vector>
#include <iostream>
#include <stdint.h>
using namespace std;


struct segtree{
    vector <int32_t> data;
    int32_t size;

    void init(int32_t n){
        size = 1;
        while (size<n)
        {
            size*=2;
        }
        data.assign(2*size,0);
    }

    void construct(vector<int32_t> &arr){
        init(arr.size());
        construct(arr,0,0,size);
    }
    
    void construct(vector<int32_t> &arr,int32_t x,int32_t l,int32_t r){
        if(r-l==1){
            if(l<arr.size()){
                data[x] = arr[l];
            }
            else{
                data[x] = 0;
            }
        }
        else{
            int32_t m = (l+r)/2;
            construct(arr,2*x+1,l,m);
            construct(arr,2*x+2,m,r);
            data[x] = max(data[2*x+1],data[2*x+2]);
        }
    }

    void set(int32_t i,int32_t v){
        set(i,v,0,0,size);
    }

    void set(int32_t i,int32_t v, int32_t x, int32_t l, int32_t r){
        if(r-l==1){
            data[x] = v;
            return;
        }
        int32_t m = (l+r)/2;
        if(i<m){
            set(i,v,2*x+1,l,m);
        }
        else{
            set(i,v,2*x+2,m,r);
        }
        data[x] = max(data[2*x+1],data[2*x+2]);
    }

    int32_t find(int32_t i){
        return find(i,0,0,size);
    }

    int32_t find(int32_t i, int32_t x, int32_t lx, int32_t rx){
        if(data[x]<i){return -1;}
        if(rx-lx==1){
            return lx;
        }
        int32_t m = (lx+rx)/2;
        int32_t res = find(i,2*x+1,lx,m);
        if(res==-1){
            return find(i,2*x+2,m,rx);
        }
        return res;
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t n,m,type,u,v;

    cin>>n>>m;

    vector<int32_t> data(n);

    for (size_t i = 0; i < n; i++)
    {
        cin>>data[i];
    }
    
    segtree tree;
    tree.construct(data);

    for (size_t i = 0; i < m; i++)
    {
        cin>>type;
        if(type==1){
            cin>>u>>v;
            tree.set(u,v);
        }
        else{
            cin>>u;
            cout<<tree.find(u)<<endl;
        }
    }
    
    return 0;
}