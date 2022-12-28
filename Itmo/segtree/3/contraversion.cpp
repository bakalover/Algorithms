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
            data[x] = data[2*x+1] + data[2*x+2];
        }
    }

    void set(int32_t i){
        set(i,0,0,size);
    }

    void set(int32_t i, int32_t x, int32_t l, int32_t r){
        if(r-l==1){
            data[x] = 1 - data[x];
            return;
        }
        int32_t m = (l+r)/2;
        if(i<m){
            set(i,2*x+1,l,m);
        }
        else{
            set(i,2*x+2,m,r);
        }
        data[x] = data[2*x+1] + data[2*x+2];
    }

    int32_t find(int32_t i){
        return find(i,0,0,size);
    }

    int32_t find(int32_t i, int32_t x, int32_t lx, int32_t rx){
        if(rx-lx==1){
            return rx;
        }
        int32_t m = (lx+rx)/2;
        if(i>=data[2*x+2]){
            return find(i-data[2*x+2],2*x+1,lx,m);
        }
        else{
            return find(i,2*x+2,m,rx);
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t n;

    cin>>n;

    vector<int32_t> data(n,1);
    vector<int32_t> req(n);
    vector<int32_t> ans;
    
    segtree tree;
    tree.construct(data);
    for (size_t i = 0; i < n; i++)
    {
        cin>>req[i];
    }

    for (size_t i = req.size()-1; i < req.size(); --i) //fun with numbers
    {
        ans.push_back(tree.find(req[i]));
        tree.set(tree.find(req[i])-1);
    }
    for (size_t i = ans.size()-1; i < ans.size(); --i)
    {
        cout<<ans[i]<<" ";
    }
    
    
    return 0;
}