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
        if (n == 0)
        {
            return nullptr;
        }
        --n;
        swap(elements[0], elements[n]);
        Header *el = elements.back();
        elements.pop_back();
        siftdown(0);
        return el;
    }

    void update(Header *el)
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

    void del(Header *el)
    {
        el->cap = SIZE_MAX;
        siftup(el->heap_index);
        this->extract_max();
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
    Header *blocks;
    vector<pair<Header *, bool>> requests; // true - Проблемы с аллоцированием были (нехватка памяти или уже хотя бы раз деаллоцировали)
    BinHeap free_queue;

    void fill_block(Header *block, Header *prev, Header *next, int64_t start_pos, size_t cap, size_t heap_index, bool free)
    {
        block->prev = prev;
        block->next = next;
        block->start_pos = start_pos;
        block->cap = cap;
        block->heap_index = heap_index;
        block->free = free;
    }

public:
    Allocator(size_t n)
    {
        blocks = (Header *)malloc(sizeof(Header));
        fill_block(blocks, nullptr, nullptr, 1, n, 0, true);
        free_queue.push(blocks);
    }

    int64_t allocate(size_t k)
    {
        Header *top_el = free_queue.extract_max();
        if (top_el == nullptr)
        {
            requests.push_back(make_pair(top_el, true));
            return -1;
        }
        if (k > top_el->cap)
        {
            requests.push_back(make_pair(top_el, true));
            free_queue.push(top_el);
            return -1;
        }
        else
        {
            if (k == top_el->cap)
            {
                fill_block(top_el, top_el->prev, top_el->next, top_el->start_pos, k, 0, false);
                requests.push_back(make_pair(top_el, false));
                return top_el->start_pos;
            }
            else
            {
                Header *new_block = (Header *)malloc(sizeof(Header));
                fill_block(new_block, top_el->prev, top_el, top_el->start_pos, k, 0, false);
                if (top_el->prev != nullptr)
                {
                    top_el->prev->next = new_block;
                }

                top_el->cap -= k;
                top_el->prev = new_block;
                top_el->start_pos += k;

                free_queue.push(top_el);

                requests.push_back(make_pair(new_block, false));
                return new_block->start_pos;
            }
        }
    }

    void deallocate(int64_t i)
    {
        pair<Header *, bool> cur_pair = requests[i - 1];

        Header *cur = cur_pair.first;
        requests.push_back(make_pair(nullptr, false)); // Заполняем мусором (запросы на деаллоцирование учитываются в нумерации)

        if (cur_pair.second) // Не аллоцировано -> делаем ничего
        {
            return;
        }

        requests[i - 1].second = true;

        cur->free = true;

        if (cur->prev == nullptr && cur->next == nullptr)
        {
            fill_block(cur, cur->prev, cur->next, cur->start_pos, cur->cap, 0, true);
            free_queue.push(cur);
            return;
        }

        if (cur->prev == nullptr && cur->next != nullptr)
        {
            if (cur->next->free)
            {
                fill_block(cur->next, cur->prev, cur->next->next, cur->start_pos, cur->cap + cur->next->cap, cur->next->heap_index, true);
                free_queue.update(cur);
                // free(cur);
                cur = nullptr;
                return;
            }
            else
            {
                fill_block(cur, cur->prev, cur->next, cur->start_pos, cur->cap, 0, true);
                free_queue.push(cur);
                return;
            }
        }

        if (cur->prev != nullptr && cur->next == nullptr)
        {
            if (cur->prev->free)
            {
                fill_block(cur->prev, cur->prev->prev, cur->next, cur->prev->start_pos, cur->prev->cap + cur->cap, cur->prev->heap_index, free);
                blocks = cur->prev;
                free_queue.update(cur->prev);
                // free(cur);
                cur = nullptr;
                return;
            }
            else
            {
                fill_block(cur, cur->prev, cur->next, cur->start_pos, cur->cap, 0, true);
                free_queue.push(cur);
                return;
            }
        }

        if (cur->prev != nullptr && cur->next != nullptr)
        {
            if (cur->next->free && !cur->prev->free)
            {
                fill_block(cur->next, cur->prev, cur->next->next, cur->start_pos, cur->cap + cur->next->cap, cur->next->heap_index, true);
                fill_block(cur->prev, cur->prev->prev, cur->next, cur->prev->start_pos, cur->prev->cap, 0, false);
                free_queue.update(cur->next);
                // free(cur);
                return;
            }

            if (!cur->next->free && cur->prev->free)
            {
                fill_block(cur->prev, cur->prev->prev, cur->next, cur->prev->start_pos, cur->cap + cur->prev->cap, cur->prev->heap_index, true);
                fill_block(cur->next, cur->prev, cur->next->next, cur->next->start_pos, cur->next->cap, 0, false);
                free_queue.update(cur->prev);
                // free(cur);
                cur = nullptr;
                return;
            }

            if (cur->next->free && cur->prev->free)
            {
                fill_block(cur->next, cur->prev->prev, cur->next->next, cur->prev->start_pos, cur->cap + cur->prev->cap + cur->next->cap, cur->next->heap_index, true);
                if (cur->prev->prev != nullptr)
                {
                    cur->prev->prev->next = cur->next;
                }
                free_queue.del(cur->prev);
                free_queue.update(cur->next);
                // free(cur);
                // free(cur->prev);
                return;
            }

            if (!cur->next->free && !cur->prev->free)
            {
                fill_block(cur, cur->prev, cur->next, cur->start_pos, cur->cap, 0, true);
                free_queue.push(cur);
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

// 5 100
// 2
// 2
// 1
// -1
// -2
// -3
// 5
// 4
// -7
// 2
// 2
// 1
// -10
// -10

// 16 40
// 4
// 4
// 4
// 4
// 4
// 4
// -1
// -2
// 1
// -9
// -3
// -4
// -5
// -6
// 15
// -15
// 16
// -17
// 10
// -19
// 12
// 4
// -21
// 12
// -22
// -24
// 3
// 5
// 8
// -28
// -27
// -29
// 3
// 5
// 7
// -33
// -35
// -34
// 16
// -39