#include <iostream>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t t,n,index;
    bool r=false,seq=false;
    string s;
    cin>>t;
    for (size_t i = 0; i < t; i++)
    {
        cin>>n;
        cin>>s;

        index = 0;
        r=false,seq=false;
        for (size_t j = 0; j < s.size(); j++)
        {
            if(s[j]=='R'){r=true;}
            if(s[j]=='L'&&r){seq==true;break;}
            if(s[j]=='L'&&s[i+1]=='R'){index = j;}
        }
        if(!seq){
            cout<<-1<<'\n';
        }
        else{
            cout<<index<<'\n';
        }
        
    }
    
    
}