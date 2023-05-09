#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); // Gotta go fast
    cin.tie(0);
    cout.tie(0);

    uint32_t n,
        l = 1, r = 0, c_1{}, c_2{}, c_3{};               // Number and variables to store current 3 el
    uint32_t cur_count{}, max_count{}, l_ans{}, r_ans{}; // Current counter, maximum counter and answer borders
    cin >> n;

    if (n == 1)
    {
        cin >> c_1;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    if (n == 2)
    {
        cin >> c_2 >> c_1;
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    for (size_t i = 0; i < n; i++)
    {
        c_3 = c_2;
        c_2 = c_1;
        cin >> c_1;
        if (c_3 == c_2 && c_2 == c_1)
        {
            if (cur_count > max_count)
            {
                max_count = cur_count;
                l_ans = l;
                r_ans = r;
            }
            cur_count = 2;
            l = r;
            ++r;
        }
        else
        {
            ++r;
            ++cur_count;
        }
    }
    if (cur_count > max_count)
    {
        l_ans = l;
        r_ans = r;
    }
    cout << l_ans << " " << r_ans << endl;
    return 0;
}