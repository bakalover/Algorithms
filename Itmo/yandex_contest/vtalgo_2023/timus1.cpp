#include <iostream>
#include <vector>
using namespace std;


struct info{
    int64_t seg;
    int64_t pref;
    int64_t suf;
    int64_t sum;
};

struct info find(vector<int64_t>& arr, int64_t l, int64_t r){
    if(r-l==1){
        return (struct info){.seg=arr[l],.pref=arr[l],.suf=arr[l],.sum=arr[l]};
    }
    int64_t m = (l+r)/2;
    struct info info_l = find(arr,l,m);
    struct info info_r = find(arr,m,r);
    return (struct info){
        .seg = max(max(info_l.seg, info_r.seg), info_l.suf + info_r.pref),
        .pref = max(info_l.pref, info_l.sum + info_r.pref),
        .suf = max(info_r.suf, info_r.sum + info_l.suf),
        .sum = info_l.sum + info_r.sum
    };
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
    
    cout << max((int64_t)0, find(arr, 0, arr.size()-1).seg) << endl;

    return 0;

}