#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

template <typename T>
class GoblinQueue
{
private:
    deque<T> l, r;
    int a, b, c;
    void rebalance()
    {
        if (r.size() < l.size())
        {
            r.push_back(l.front());
            l.pop_front();
        }
    }

public:
    GoblinQueue()
    {
    }

    void insert_common(const T el)
    {
        l.push_back(el);
        this->rebalance();
    }

    void insert_loyal(const T el)
    {
        l.push_front(el);
        this->rebalance();
    }

    T get_next()
    {
        if (r.size() == 0)
        {
            T gob = l.front();
            l.pop_front();
            return gob;
        }
        else
        {
            T gob = r.front();
            r.pop_front();
            this->rebalance();
            return gob;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    uint32_t n, gob_numb;
    char type;

    GoblinQueue<uint32_t> queue;

    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> type;
        switch (type)
        {
        case '-':
            cout << queue.get_next() << endl;
            break;
        case '*':
            cin >> gob_numb;
            queue.insert_loyal(gob_numb);
            break;
        case '+':
            cin >> gob_numb;
            queue.insert_common(gob_numb);
            break;
        default:
            break;
        }
    }

    return 0;
}