#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    uint32_t n, k, prev, counter;
    uint32_t l = 1, r = 1000000001, m;

    cin >> n >> k;

    vector<uint32_t> coord(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> coord[i];
    }

    while (r > l + 1)
    {
        m = (l + r) / 2;
        prev = coord[0];
        counter = 1;

        for (size_t i = 1; i < n; i++)
        {
            if (coord[i] - prev >= m)
            {
                ++counter;
                prev = coord[i];
            }
        }

        if (counter >= k)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l << endl;
    return 0;
}