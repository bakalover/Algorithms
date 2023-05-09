#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

bool paint(uint16_t v, vector<vector<uint32_t>> &G, vector<pair<int8_t, bool>> &C)
{

    queue<uint32_t> Q;
    C[v].first = 0; // Покраска первой вершины
    Q.push(v);

    while (!Q.empty())
    {
        uint32_t u = Q.front();
        Q.pop();
        C[u].second = true;
        for (uint32_t v : G[u])
        {
            if (C[v].second)
            {
                if (C[v].first == C[u].first)
                {
                    return false;
                }
            }
            else
            {
                C[v].first = (C[u].first + 1) % 2;
                Q.push(v);
            }
        }
    }
    return true;
}

int main()
{
    uint32_t n, m, u, v;
    cin >> n >> m;
    vector<vector<uint32_t>> G(n + 1);
    vector<pair<int8_t, bool>> C(n + 1, make_pair(3, false));

    for (size_t i = 0; i < m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (size_t i = 1; i <= n; i++)
    {
        if (!C[i].second && !paint(i, G, C))
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}