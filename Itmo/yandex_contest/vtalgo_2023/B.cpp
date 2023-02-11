#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);                         
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    for (size_t i = 0; i < s.size()/2; i++)
    {
        if(abs((int)s[i] - (int)s[s.size()-1-i]) != 32 && abs((int)s[i] - (int)s[s.size()-1-i]) != 0) {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    for (size_t i = 0; i < s.size()/2; i++)
    {
        cout<<s.size()/2 - i<<" ";
    }
    
    return 0;
}