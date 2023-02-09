#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Абсолютно неоптимальное (можно юыло просто проверить число рёбер), но красивое решение ))


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int16_t n{};
    cin>>n;
    if(n==1){cout<<"YES"<<endl;return 0;}
    // Для n>=2 воспользуемся матричной теоремой о деревьях
    // st(G) = det(L_i_i) (L_i_i - лапласиан графа с вычеркнутыми i-ми столбцами и строками)
    // YES <=> st(G) == 1

    // Лапласиан Графа
    vector<vector<signed char>> L (n, vector<signed char> (n));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if(i!=j){cin>>L[i][j]; L[i][j] = -L[i][j];}
            else{cin>>L[i][j];}
        }
        
    }
    
    return 0;
}