#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<string>> arr(10, vector<string>(0));
    string s;

    while(cin>>s){
        arr[s[0]-'0'].push_back(s);       
    }
    cout<<"---------------"<<endl;
    for(auto& el : arr){
        sort(el.begin(), el.end());
        //sort(el.begin(), el.end(),[](string s1, string s2){return s1.length()>s2.length();});
    }
    
    for (int64_t i = arr.size()-1; i >= 0; --i)
    {
        for (int64_t j = arr[i].size()-1; j >=0; --j)
        {
            cout<<arr[i][j]<<endl;
        }
        
    }
    
    return 0;
}
// 004
// 05
// 06
// 066
// 2
// 22
// 20
// 23
// 60
// 6
// 68
// 67