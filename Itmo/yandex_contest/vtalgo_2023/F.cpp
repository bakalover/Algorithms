#include <iostream>
#include <vector>
using namespace std;

void merge(vector<string> &arr, vector<string> &help, size_t l, size_t m, size_t r, bool (*func)(string &p1, string &p2))
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

void merge_sort(vector<string> &arr, vector<string> &help, size_t l, size_t r, bool (*func)(string &p1, string &p2))
{
    if (l < r)
    {
        size_t m = (l + r) / 2;
        merge_sort(help, arr, l, m, func);
        merge_sort(help, arr, m + 1, r, func);
        merge(arr, help, l, m, r, func);
    }
}

void sort(vector<string> &arr, bool (*func)(string &p1, string &p2))
{
    vector<string> help(arr);
    merge_sort(arr, help, 0, arr.size() - 1, func);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> arr;
    string s;

    while (cin >> s)
    {
        arr.push_back(s);
    }

    sort(arr, [](string &s1, string &s2){ return s1 + s2 > s2 + s1; });

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }

    return 0;
}