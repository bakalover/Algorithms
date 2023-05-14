#include <iostream>
#include <vector>
using std::cin, std::cout, std::endl;
using std::vector;

struct edge
{
    int32_t u, v, cost;
};

int32_t
main()
{
    int32_t n, m, a, b, c, f, s;
    cin >> n >> m;

    vector<edge> E(m);
    vector<int32_t> path(n + 1, INT32_MIN);

    for (size_t i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        E[i] = (edge){.u = a, .v = b, .cost = c};
    }

    cin >> s >> f;

    path[s] = 0;

    for (;;)
    {
        bool check = false;
        for (size_t i = 0; i < m; i++)
        {
            if (path[E[i].u] > INT32_MIN && path[E[i].v] < path[E[i].u] + E[i].cost)
            {
                path[E[i].v] = path[E[i].u] + E[i].cost;
                check = true;
            }
        }
        if (!check)
        {
            break;
        }
    }
    if (path[f] == INT32_MIN)
    {
        cout << "No solution" << endl;
        return 0;
    }
    cout << path[f] << endl;
    return 0;
}