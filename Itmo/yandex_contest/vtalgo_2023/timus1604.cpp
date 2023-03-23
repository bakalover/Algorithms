#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

template <typename T>
class BinHeap
{
private:
    vector<T> elements;
    size_t n = 0;

public:
    size_t size()
    {
        return elements.size();
    }

    void push(const T el)
    {
        elements.push_back(el);
        siftup(n++);
    }

    T &operator[](const int index)
    {
        return elements[index];
    }

    T extract_max()
    {
        --n;
        swap(elements[0], elements[n]);
        T el = elements.back();
        elements.pop_back();
        siftdown(0);
        return el;
    }

    void siftup(int32_t i)
    {
        while (i > 0 && elements[parent(i)].second < elements[i].second)
        {
            swap(elements[i], elements[parent(i)]);
            i = parent(i);
        }
    }

    void siftdown(int32_t i)
    {
        int32_t j = i;
        while (true)
        {
            if (left(i) < n && elements[j].second <= elements[left(i)].second)
            {
                j = left(i);
            }
            if (right(i) < n && elements[j].second <= elements[right(i)].second)
            {
                j = right(i);
            }
            if (i == j)
                break;
            swap(elements[i], elements[j]);
            i = j;
        }
    }

    int32_t parent(int32_t i)
    {
        return (i - 1) / 2;
    }

    int32_t left(int32_t i)
    {
        return 2 * i + 1;
    }

    int32_t right(int32_t i)
    {
        return 2 * i + 2;
    };
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t k, n_i;

    BinHeap<pair<int32_t, int32_t>> arr;

    cin >> k;

    for (uint16_t i = 0; i < k; i++)
    {
        cin >> n_i;
        arr.push(make_pair(i + 1, n_i));
    }
    if (arr.size() >= 2)
    {
        while (true)
        {
            auto max_1 = arr.extract_max();
            auto max_2 = arr.extract_max();

            if (max_1.second == 0)
            {
                break;
            }
            if (max_2.second == 0)
            {
                cout << max_1.first << " ";
                --max_1.second;
                arr.push(max_1);
                arr.push(max_2);
            }
            else
            {
                cout << max_1.first << " " << max_2.first << " ";
                --max_1.second;
                --max_2.second;
                arr.push(max_1);
                arr.push(max_2);
            }
        }
    }
    else
    {
        auto max_1 = arr.extract_max();
        for (size_t i = 0; i < max_1.second; i++)
        {
            cout << max_1.first << " ";
        }
    }
    return 0;
}