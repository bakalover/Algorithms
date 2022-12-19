#include <vector>
#include <iostream>
#include <stdint.h>
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
            data[x] = data[2*x+1]<data[2*x+2]?data[2*x+1]:data[2*x+2];
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
        data[x] = data[2*x+1]<data[2*x+2]?data[2*x+1]:data[2*x+2];
    }

    int64_t min(int64_t l, int64_t r){
        return min(l,r,0,0,size);
    }

    int64_t min(int64_t l, int64_t r, int64_t x, int64_t lx, int64_t rx){
        if(l>=rx||r<=lx){
            return 100000000000;
        }
        if(lx>=l&&rx<=r){
            return data[x];
        }
        int64_t m = (lx+rx)/2;
        int64_t min1 = min(l,r,2*x+1,lx,m);
        int64_t min2 = min(l,r,2*x+2,m,rx);
        return min1<min2?min1:min2;
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t n,m,type,u,v;

    cin>>n>>m;

    vector<int64_t> data(n);

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
            cout<<tree.min(u,v)<<endl;
        }
    }
    
    return 0;
}