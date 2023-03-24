#include <iostream>
#include <vector>
// #include <algorithm>
#include <set>
using namespace std;

void merge(vector<pair<char, uint32_t>> &arr, vector<pair<char, uint32_t>> &help, size_t l, size_t m, size_t r, bool (*func)(pair<char, uint32_t> &p1, pair<char, uint32_t> &p2))
{
    size_t i = l;
    size_t j = m + 1;
    for (size_t k = l; k <= r; k++)
    {
        if (i > m)
        {
            arr[k] = help[j++];
            continue;
        }
        if (j > r)
        {
            arr[k] = help[i++];
            continue;
        }
        if ((func)(help[j], help[i]))
        {
            arr[k] = help[j++];
        }
        else
        {
            arr[k] = help[i++];
        }
    }
}

void merge_sort(vector<pair<char, uint32_t>> &arr, vector<pair<char, uint32_t>> &help, size_t l, size_t r, bool (*func)(pair<char, uint32_t> &p1, pair<char, uint32_t> &p2))
{
    if (l < r)
    {
        size_t m = (l + r) / 2;
        merge_sort(help, arr, l, m, func);
        merge_sort(help, arr, m + 1, r, func);
        merge(arr, help, l, m, r, func);
    }
}

void sort(vector<pair<char, uint32_t>> &arr, bool (*func)(pair<char, uint32_t> &p1, pair<char, uint32_t> &p2))
{
    vector<pair<char, uint32_t>> help(arr);
    merge_sort(arr, help, 0, arr.size() - 1, func);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<uint32_t> weight(26);
    vector<uint32_t> count(26);
    vector<pair<char, uint32_t>> arr;
    set<char> help;
    string s, res_part1, res_part2, res_part3;

    cin >> s;

    for (auto c : s)
    {
        ++count[c - 'a'];
        help.insert(c);
    }

    for (size_t i = 0; i < weight.size(); i++)
    {
        cin >> weight[i];
    }

    for (auto c : help)
    {
        arr.push_back(make_pair(c, weight[c - 'a']));
    }

    sort(arr, [](pair<char, uint32_t> &x, pair<char, uint32_t> &y)
         { return x.second > y.second; });

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (count[arr[i].first - 'a'] >= 2)
        {
            res_part1 += arr[i].first;
        }
    }

    for (int32_t i = arr.size() - 1; i >= 0; i--)
    {
        if (count[arr[i].first - 'a'] >= 2)
        {
            res_part3 += arr[i].first;
            count[arr[i].first - 'a'] -= 2;
        }
    }

    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < count[arr[i].first - 'a']; j++)
        {
            res_part2 += arr[i].first;
        }
    }

    cout << res_part1 + res_part2 + res_part3 << endl;

    return 0;
}