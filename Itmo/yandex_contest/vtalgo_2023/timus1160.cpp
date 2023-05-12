#include <iostream>
#include <vector>

using std::cout, std::cin, std::endl;
using std::vector;

typedef vector<vector<int32_t>> Gr;

struct edge
{
    int32_t u;
    int32_t v;
};

void search(int64_t u, vector<bool> &V, Gr &H);

int32_t calc(Gr &H)
{
    int32_t count = 0;
    for (size_t i = 0; i < H.size(); i++)
    {
        for (size_t j = 0; j < H[i].size(); j++)
        {
            if (H[i][j] != -1)
            {
                ++count;
            }
        }
    }
    return count;
}

void fill(Gr &src, Gr &out, int64_t cost)
{
    for (size_t i = 0; i < src.size(); i++)
    {
        for (size_t j = 0; j < src[i].size(); j++)
        {
            if (src[i][j] <= cost)
            {
                out[i][j] = src[i][j];
            }
            else
            {
                out[i][j] = -1;
            }
        }
    }
}

bool check(Gr &H)
{
    vector<bool> V(H.size(), false);
    search(0, V, H);
    for (bool el : V)
    {
        if (el == false)
        {
            return false;
        }
    }
    return true;
}

void search(int64_t u, vector<bool> &V, Gr &H)
{
    V[u] = true;
    for (int64_t i = 0; i < H[u].size(); i++)
    {
        if (!V[i] && H[u][i] > 0)
        {
            search(i, V, H);
        }
    }
}

int32_t main()
{
    int32_t n, m, u, v, cost;
    cin >> n >> m;

    Gr G(n, vector<int32_t>(n, -1));
    Gr H(n, vector<int32_t>(n, -1));
    vector<edge> edges;

    int64_t l = 0, r = 2 * (10e9 + 1), mid;

    for (size_t i = 0; i < m; i++)
    {
        cin >> u >> v >> cost;
        edges.push_back((edge){.u = u, .v = v});
        G[u - 1][v - 1] = cost;
        G[v - 1][u - 1] = cost;
    }

    while (r > l)
    {
        mid = (r + l) / 2;
        fill(G, H, mid);
        if (check(H))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
    fill(G, H, l);
    cout << calc(H) / 2 << endl;

    for (size_t i = 0; i < edges.size(); i++)
    {
        if (H[edges[i].u - 1][edges[i].v - 1] > -1)
        {
            cout << edges[i].u << " " << edges[i].v << endl;
        }
    }
}