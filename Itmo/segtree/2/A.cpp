#include <vector>
#include <iostream>
#include <stdint.h>
using namespace std;

struct info{
    int64_t seg;
    int64_t pref;
    int64_t suf;
    int64_t sum;
};

struct segtree{
    vector <info> data;
    int64_t size;

    void init(int64_t n){
        size = 1;
        while (size<n)
        {
            size*=2;
        }
        data.assign(2*size, (struct info){.seg=0,.pref=0,.suf=0,.sum=0});
    }

    void construct(vector<int64_t> &arr){
        init(arr.size());
        construct(arr,0,0,size);
    }
    
    void construct(vector<int64_t> &arr,int64_t x,int64_t l,int64_t r){
        if(r-l==1){
            if(l<arr.size()){
                data[x].seg = arr[l];
                data[x].sum = arr[l];
                data[x].pref = arr[l];
                data[x].suf = arr[l];
            }
        }
        else{
            int64_t m = (l+r)/2;
            construct(arr,2*x+1,l,m);
            construct(arr,2*x+2,m,r);
            data[x].seg = max(max(data[2*x+1].seg,data[2*x+2].seg),data[2*x+1].suf+data[2*x+2].pref);
            data[x].pref = max(data[2*x+1].pref, data[2*x+1].sum+data[2*x+2].pref);
            data[x].suf = max(data[2*x+2].suf,data[2*x+2].sum+data[2*x+1].suf);
            data[x].sum = data[2*x+1].sum + data[2*x+2].sum;
        }
    }

    void set(int64_t i, int64_t v){
        set(i,v,0,0,size);
    }

    void set(int64_t i, int64_t v, int64_t x, int64_t l, int64_t r){
        if(r-l==1){
            data[x].seg = v;
            data[x].sum = v;
            data[x].pref = v;
            data[x].suf = v;
            return;
        }
        int64_t m = (l+r)/2;
        if(i<m){
            set(i,v,2*x+1,l,m);
        }
        else{
            set(i,v,2*x+2,m,r);
        }
        data[x].seg = max(max(data[2*x+1].seg,data[2*x+2].seg),data[2*x+1].suf+data[2*x+2].pref);
        data[x].pref = max(data[2*x+1].pref, data[2*x+1].sum+data[2*x+2].pref);
        data[x].suf = max(data[2*x+2].suf,data[2*x+2].sum+data[2*x+1].suf);
        data[x].sum = data[2*x+1].sum + data[2*x+2].sum;
    }

};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t n,m,u,v;

    cin>>n>>m;

    vector<int64_t> data(n);

    for (size_t i = 0; i < n; i++)
    {
        cin>>data[i];
    }
    
    segtree tree;
    tree.construct(data);
    if(tree.data[0].seg<0){
        cout<<0<<endl;
    }
    else{
        cout<<tree.data[0].seg<<endl;
    }
    for (size_t i = 0; i < m; i++)
    {
        cin>>u>>v;
        tree.set(u,v);
        if(tree.data[0].seg<0){
            cout<<0<<endl;
        }
        else{
            cout<<tree.data[0].seg<<endl;
        }
    }
    
    return 0;
}