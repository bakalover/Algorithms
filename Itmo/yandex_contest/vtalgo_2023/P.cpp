#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef vector<vector<int32_t>> Gr;

void search(int64_t u, vector<bool> &V, Gr &H);
void search_op(int64_t u, vector<bool> &V, Gr &H);

void fill(Gr &src, Gr &out, int64_t tank)
{
    for (size_t i = 0; i < src.size(); i++)
    {
        for (size_t j = 0; j < src[i].size(); j++)
        {
            if (src[i][j] <= tank)
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
    vector<bool> V_op(H.size(), false);
    search(0, V, H);
    search_op(0, V_op, H);
    for (bool el : V)
    {
        if (el == false)
        {
            return false;
        }
    }
    for (bool el : V_op)
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

void search_op(int64_t u, vector<bool> &V, Gr &H)
{
    V[u] = true;
    for (int64_t i = 0; i < H[u].size(); i++)
    {
        if (!V[i] && H[i][u] > 0)
        {
            search_op(i, V, H);
        }
    }
}

int main()
{
    uint32_t n;
    cin >> n;
    Gr G(n, vector<int32_t>(n, -1));
    Gr H(n, vector<int32_t>(n, -1));
    int64_t l = 0, r = 2 * (10e9 + 1), m;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }

    while (r > l)
    {
        m = (r + l) / 2;
        fill(G, H, m);
        if (check(H))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << l << endl;
}