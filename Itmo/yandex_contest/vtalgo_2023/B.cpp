#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);                         
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    
    stack<size_t> an, tr;                             // Stack storing indexes of animals and traps
    stack<char> all;                                  // Stack for checking intersections (hhhhGGGGggHHhhggHHHH - example for fail without this stack)
    vector<size_t> indexes((size_t)(s.size()/2));     // Indexes of animals, if answer is "Possible"
    size_t tr_id{1}, an_id{1};                        // Counters for traps and animals

    for(size_t i = 0; i<s.size();++i){
        if(all.empty()){
            all.push(s[i]);
        }

        if(isupper(s[i])){
            tr.push(tr_id);
            ++tr_id;
        }
        else{
            an.push(an_id);
            ++an_id;
        }
        if(!an.empty() && !tr.empty() && tr.top() == toupper(an.top()) && abs((int)all.top() - (int)s[i])==32){
            indexes[tr.top()-1] = an.top();
            all.pop();
            an.pop();
            tr.pop();
        }
        else{
            all.push(s[i]);
        }
    }
    if(an.empty() && tr.empty()){
        cout<<"Possible"<<endl;
        for(auto& index: indexes){
            cout<<index<<" ";
        }
    }
    else{
        cout<<"Impossible"<<endl;
    }

    return 0;
}
//ABcCCcbBbbbBBAfffFFFa 
//hhhhGGGGggHHhhggHHHH

