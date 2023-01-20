#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double a,b,c,v0,v1,v2;
    vector<double> options;
    cin>>a>>b>>c>>v0>>v1>>v2;
    options.push_back(a/v0 + a/v1 + b/v0 + b/v1);
    options.push_back(a/v0 + c/v1 + b/v2);
    options.push_back(a/v0 + c/v1 + c/v2 + a/v2);
    options.push_back(b/v0 + c/v1 + a/v2);
    options.push_back(b/v0 + c/v1 + c/v2 + b/v2);
    options.push_back(a/v0 + c/v0 + c/v1 + a/v2);
    options.push_back(b/v0 + c/v0 + c/v1 + b/v2);
    options.push_back(a/v0 + c/v0 + b/v1 + a/v0 + a/v1);
    options.push_back(b/v0 + c/v0 + a/v1 + b/v0 + b/v1);
    cout<<options[min_element(options.begin(), options.end()) - options.begin()]<<endl;
    return 0;

}