#include <iostream>
#include <map>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);                         
    cin.tie(0);
    cout.tie(0);

    unordered_map<string,stack<pair<uint_fast16_t,int_fast32_t>>> memory; // (var name, (№ of level, value))
    unordered_map<string,stack<pair<uint_fast16_t,int_fast32_t>>>::iterator it_l, it_r;
    stack<string> check;
    string s, l, r, delim = "="; 
    int_fast32_t r_prs{};
    uint_fast16_t level_counter{};


    while(cin>>s){

        if(s=="{"){
            ++level_counter;
            continue;

        }

        if(s=="}"){

            for(auto& el: memory){
                if(!el.second.empty() && el.second.top().first==level_counter){
                    el.second.pop();
                }
            }
            --level_counter;
            continue;

        }

        l = s.substr(0, s.find(delim));
        l = l+"#$%^&*(";
        r = s.substr(s.find(delim)+1, s.size()-1);
        r = r+"#$%^&*(";
            //it_r->second.top().second

        try{
            r_prs = stoi(r);
            it_l = memory.find(l);

            if(it_l==memory.end()){

                stack<pair<uint_fast16_t,int_fast32_t>> stack;
                stack.push(make_pair(level_counter,r_prs));
                memory.insert(pair(l,stack));

            }

            else{

                if(!it_l->second.empty() && it_l->second.top().first==level_counter){
                    it_l->second.top().second = r_prs;
                }

                else{
                    it_l->second.push(make_pair(level_counter,r_prs));
                }

            }
        }

        catch(invalid_argument const& ex){

            it_l = memory.find(l);
            it_r = memory.find(r);
            stack<pair<uint_fast16_t,int_fast32_t>>& l_st = it_l->second;

            if(it_l==memory.end()){

                stack<pair<uint_fast16_t,int_fast32_t>> stack;

                if(it_r==memory.end()){
                    stack.push(make_pair(level_counter,0));
                }

                else{
                    
                    if(it_r->second.empty()){
                        stack.push(make_pair(level_counter,0));
                    }
                    else{
                        stack.push(make_pair(level_counter,it_r->second.top().second));
                    }
                }

                memory.insert(pair(l,stack));

            }

            else{

                if(it_r==memory.end()){

                    if(l_st.empty()){
                        l_st.push(make_pair(level_counter,0));
                    }

                    else{
                        if(l_st.top().first==level_counter){
                            l_st.top().second = 0;
                        }
                        else{
                            l_st.push(make_pair(level_counter,0));
                        }
                    }

                }

                else{

                    if(l_st.empty()){

                        if(it_r->second.empty()){
                            l_st.push(make_pair(level_counter,0));
                        }

                        else{
                            l_st.push(make_pair(level_counter,it_r->second.top().second));
                        }

                    }

                    else{

                        if(it_r->second.empty()){

                            if(l_st.top().first==level_counter){
                                l_st.top().second=0;
                            }

                            else{
                                l_st.push(make_pair(level_counter,0));
                            }

                        }

                        else{
                            if(l_st.top().first==level_counter){
                                l_st.top().second=it_r->second.top().second;
                            }
                            else{
                                l_st.push(make_pair(level_counter,it_r->second.top().second));
                            }
                        }
                        
                    }
                }

            }
            cout <<  memory.find(l)->second.top().second << endl; 
        }
    }


    return 0;
}