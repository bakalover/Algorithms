#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;
int main(){
    int64_t k,n,a_i,l,r,m,slice,slices;
    cin>>n>>k;
    vector <int64_t> arr;
    for (size_t i = 0; i < n; i++)
    {
        cin>>a_i;
        arr.push_back(a_i);
    }

    l = 0;
    r = LONG_LONG_MAX;
    while(r>l+1){
        m = (r+l)/2;
        slice=0;
        slices=0;
        for (size_t j = 0; j < arr.size(); j++)
        {
            slice += arr.at(j);
            if(slice>=m){
                slice = 0;
                if(slice!=m){
                    slice+=arr.at(j);
                }
                ++slices;
            }
        }
        if(slice!=0){
            ++slices;
        }
        if(slices>k){
            l = m;
        }
        else{
            r = m;
        }
    }
    cout<<m;
}