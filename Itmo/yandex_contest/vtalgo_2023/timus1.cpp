#include <iostream>
#include <vector>
using namespace std;


struct info{
    int32_t seg;
    int32_t pref;
    int32_t suf;
    int32_t sum;
};

void construct(vector<int64_t> &arr, vector<info>& data,int64_t x,int64_t l,int64_t r){
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
            construct(arr,data,2*x+1,l,m);
            construct(arr,data,2*x+2,m,r);
            data[x].seg = max(max(data[2*x+1].seg,data[2*x+2].seg),data[2*x+1].suf+data[2*x+2].pref);
            data[x].pref = max(data[2*x+1].pref, data[2*x+1].sum+data[2*x+2].pref);
            data[x].suf = max(data[2*x+2].suf,data[2*x+2].sum+data[2*x+1].suf);
            data[x].sum = data[2*x+1].sum + data[2*x+2].sum;
        }
    }

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    uint32_t n;

    cin>>n;
    
    vector<int64_t> arr (n);

    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    vector <info> data;
    int64_t size = 1;
    while (size<n)
    {
        size*=2;
    }
    data.assign(2*size, (struct info){.seg=0,.pref=0,.suf=0,.sum=0});
    construct(arr, data, 0, 0, size);
    
    cout << max((int32_t)0, data[0].seg) << endl;

    return 0;

}