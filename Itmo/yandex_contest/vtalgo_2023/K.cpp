#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

struct Header
{
    Header *prev;
    Header *next;
    int64_t start_pos;
    size_t cap;
    size_t heap_index;
    bool free;
};

class BinHeap
{
private:
    vector<Header *> elements;
    size_t n = 0;

public:
    size_t size()
    {
        return elements.size();
    }

    void push(Header *const el)
    {
        el->heap_index = n;
        elements.push_back(el);
        siftup(n++);
    }

    Header *&operator[](const int index)
    {
        return elements[index];
    }

    Header *extract_max()
    {
        --n;
        swap(elements[0], elements[n]);
        Header *el = elements.back();
        elements.pop_back();
        siftdown(0);
        return el;
    }

    void update(Header *const el)
    {
        siftup(el->heap_index);
    }

    void siftup(int32_t i)
    {
        while (i > 0 && elements[parent(i)]->cap < elements[i]->cap)
        {
            size_t heap_index_temp = elements[parent(i)]->heap_index;
            elements[parent(i)]->heap_index = elements[i]->heap_index;
            elements[i]->heap_index = heap_index_temp;

            swap(elements[i], elements[parent(i)]);
            i = parent(i);
        }
    }

    void siftdown(int32_t i)
    {
        int32_t j = i;
        while (true)
        {

            if (left(i) < n && elements[j]->cap < elements[left(i)]->cap)
            {
                j = left(i);
            }
            if (right(i) < n && elements[j]->cap < elements[right(i)]->cap)
            {
                j = right(i);
            }
            if (i == j)
                break;
            size_t heap_index_temp = elements[j]->heap_index;
            elements[j]->heap_index = elements[i]->heap_index;
            elements[i]->heap_index = heap_index_temp;
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

class Comp
{
public:
    bool operator()(Header *x, Header *y)
    {
        return x->cap > y->cap;
    }
};

class Allocator
{
private:
    list<Header> blocks;
    vector<Header *> requests;
    BinHeap free;

public:
    Allocator(int64_t n)
    {
        blocks.push_back((struct Header){.prev = nullptr, .next = nullptr, .start_pos = 1, .cap = n, .free = true});
        free.push(&blocks.front());
    }

    int64_t allocate(int64_t k)
    {
        Header *top_el = free.extract_max();
        if (k > top_el->cap)
        {
            return -1;
        }
        else
        {
            Header new_block = (struct Header){.prev = top_el->prev, .next = top_el, .start_pos = top_el->start_pos, .cap = k, .free = false};

            blocks.push_back(new_block);

            if (top_el->prev != nullptr)
            {
                top_el->prev->next = &blocks.back();
            }

            top_el->cap -= k;
            top_el->prev = &blocks.back();
            top_el->start_pos += k;

            free.push(top_el);

            requests.push_back(&blocks.back());

            return new_block.start_pos;
        }
    }

    void deallocate(int64_t i)
    {
        Header *cur = requests[i - 1];
        requests.push_back(cur);
        cur->free = true;
        if (cur->prev == nullptr && cur->next == nullptr)
        {
            free.push(cur);
            return;
        }
        if (cur->prev == nullptr && cur->next != nullptr && cur->next->free)
        {
            cur->next->cap += cur->cap;
            cur->next->prev = cur->prev;
            cur->next->start_pos = cur->start_pos;
            free.update(cur->next);
            return;
        }
        if (cur->prev != nullptr && cur->next == nullptr && cur->prev->free)
        {
            cur->prev->cap += cur->cap;
            cur->prev->next = cur->next;
            free.update(cur->prev);
            return;
        }
        if (cur->prev != nullptr && cur->next != nullptr)
        {
            if (cur->next->free && !cur->prev->free)
            {
                cur->next->cap += cur->cap;
                cur->next->prev = cur->prev;
                cur->next->start_pos = cur->start_pos;
                free.update(cur->next);
                return;
            }
            if (!cur->next->free && cur->prev->free)
            {
                cur->prev->cap += cur->cap;
                cur->prev->next = cur->next;
                free.update(cur->prev);
                return;
            }
            if (cur->next->free && cur->prev->free)
            {
                cur->prev->cap += (cur->cap + cur->next->cap);
                cur->prev->next = cur->next->next;
                cur->next->cap = 0;
                free.update(cur->prev);
                return;
            }
            if (!cur->next->free && !cur->prev->free)
            {
                free.push(cur);
                return;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t n, m, req;

    cin >> n >> m;

    Allocator allocator(n);

    for (size_t i = 0; i < m; i++)
    {
        cin >> req;
        if (req > 0)
        {
            cout << allocator.allocate(req) << endl;
        }
        else
        {
            allocator.deallocate(-req);
        }
    }

    return 0;
}
