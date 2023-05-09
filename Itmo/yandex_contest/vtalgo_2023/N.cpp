#include <iostream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::vector, std::queue;

void search(uint16_t v, vector<vector<uint16_t>> &G, vector<uint8_t> &V, uint16_t &count)
{
    V[v] = 1;
    for (auto el : G[v])
    {
        if (V[el] == 1)
        {
            ++count;
        }
        if (V[el] == 0)
        {
            search(el, G, V, count);
        }
    }
    V[v] = UINT8_MAX;
}

int main()
{
    uint16_t n, v, count = 0;
    cin >> n;

    vector<vector<uint16_t>> G(n + 1);
    vector<uint8_t> V(n + 1, 0);
    for (size_t i = 1; i <= n; i++)
    {
        cin >> v;
        G[v].push_back(i);
    }

    for (size_t i = 1; i <= n; i++)
    {
        search(i, G, V, count);
    }
    cout << count << endl;
}