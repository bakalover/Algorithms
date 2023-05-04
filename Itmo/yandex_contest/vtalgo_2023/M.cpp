#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct pt
{
    int32_t x;
    int32_t y;
};

struct info
{
    struct pt pt;
    string path;
    size_t cost;
    size_t count;
};

char get_tp(vector<vector<char>> &G, pt pt)
{
    return G[pt.x][pt.y];
}

int32_t get_cost(vector<vector<char>> &G, pt pt)
{
    if (get_tp(G, pt) == '.')
    {
        return 1;
    }
    if (get_tp(G, pt) == 'W')
    {
        return 2;
    }
    return 0;
}

info kBFS(vector<vector<char>> &G, pt st, pt ed)
{
    vector<vector<bool>> vis(G.size(), vector<bool>(G[0].size(), false));
    vis[st.x][st.y] = true;
    queue<info> Q;
    Q.push((info){.pt = (pt){.x = st.x, .y = st.y}, .path = "", .cost = 0, .count = 0});

    while (!Q.empty())
    {
        info u = Q.front();
        Q.pop();

        if (u.pt.x == ed.x && u.pt.y == ed.y)
        {
            return u;
        }

        char tp = get_tp(G, u.pt);
        if (tp == '#')
        {
            continue;
        }
        if (tp == 'W')
        {
            if (u.count < 2)
            {
                ++u.count;
                Q.push(u); // Имитация подразбиения графа
                continue;
            }
        }

        if (u.pt.x + 1 < G.size() && vis[u.pt.x + 1][u.pt.y] == false && get_tp(G, (pt){.x = u.pt.x + 1, .y = u.pt.y}) != '#')
        {
            vis[u.pt.x + 1][u.pt.y] = true;
            Q.push((info){.pt = (pt){.x = u.pt.x + 1, .y = u.pt.y}, .path = u.path + 'S', .cost = u.cost + get_cost(G, (pt){.x = u.pt.x + 1, .y = u.pt.y}), .count = 1});
        }
        if (u.pt.y + 1 < G[0].size() && vis[u.pt.x][u.pt.y + 1] == false && get_tp(G, (pt){.x = u.pt.x, .y = u.pt.y + 1}) != '#')
        {
            vis[u.pt.x][u.pt.y + 1] = true;
            Q.push((info){.pt = (pt){.x = u.pt.x, .y = u.pt.y + 1}, .path = u.path + 'E', .cost = u.cost + get_cost(G, (pt){.x = u.pt.x, .y = u.pt.y + 1}), .count = 1});
        }
        if (u.pt.x - 1 > 0 && vis[u.pt.x - 1][u.pt.y] == false && get_tp(G, (pt){.x = u.pt.x - 1, .y = u.pt.y}) != '#')
        {
            vis[u.pt.x - 1][u.pt.y] = true;
            Q.push((info){.pt = (pt){.x = u.pt.x - 1, .y = u.pt.y}, .path = u.path + 'N', .cost = u.cost + get_cost(G, (pt){.x = u.pt.x - 1, .y = u.pt.y}), .count = 1});
        }
        if (u.pt.y - 1 > 0 && vis[u.pt.x][u.pt.y - 1] == false && get_tp(G, (pt){.x = u.pt.x, .y = u.pt.y - 1}) != '#')
        {
            vis[u.pt.x][u.pt.y - 1] = true;
            Q.push((info){.pt = (pt){.x = u.pt.x, .y = u.pt.y - 1}, .path = u.path + 'W', .cost = u.cost + get_cost(G, (pt){.x = u.pt.x, .y = u.pt.y - 1}), .count = 1});
        }
    }
    return (info){.pt = (pt){.x = 0, .y = 0}, .path = "", .cost = 0, .count = 0};
}
int main()
{
    int32_t n, m, x_st, y_st, x_ed, y_ed;
    cin >> n >> m >> x_st >> y_st >> x_ed >> y_ed;
    vector<vector<char>> G(n + 1, vector<char>(m + 1, 0));

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= m; j++)
        {
            cin >> G[i][j];
        }
    }
    auto ans = kBFS(G, (pt){.x = x_st, .y = y_st}, (pt){.x = x_ed, .y = y_ed});
    if (ans.path == "")
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans.cost << endl;
    cout << ans.path << endl;
    return 0;
}