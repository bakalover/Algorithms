#include <iostream>
#include <set>
#include <queue>
using namespace std;

class Comp
{
public:
    bool operator()(pair<int32_t, int32_t> x, pair<int32_t, int32_t> y)
    {
        return x.second < y.second;
    }
};

class Game
{
private:
    int32_t n, k, p;
    size_t energy;
    set<int32_t> window;
    vector<int32_t> game_prefer;
    vector<deque<int32_t>> positions;
    priority_queue<pair<int32_t, int32_t>, vector<pair<int32_t, int32_t>>, Comp> which_pick;

    // void create_queue_of_cars()
    // {
    //     int32_t car, car_pos;
    //     vector<deque<int32_t>> pos_for_queue(positions);
    //     for (size_t i = 0; i < p; i++)
    //     {
    //         car = game_prefer[i];
    //         if (pos_for_queue[car].empty())
    //         {
    //             which_pick.push(make_pair(car, INT32_MAX));
    //         }
    //         else
    //         {
    //             car_pos = pos_for_queue[car].front();
    //             which_pick.push(make_pair(car, car_pos));
    //             pos_for_queue[car].pop_front();
    //         }
    //     }
    // }

public:
    Game(int32_t n, int32_t k, int32_t p) : positions(n + 1, deque<int32_t>()), window(), which_pick(), game_prefer()
    {
        this->n = n;
        this->k = k;
        this->p = p;
        energy = 0;
    }

    void set_future_position(int32_t car, int32_t pos)
    {
        game_prefer.push_back(car);
        positions[car].push_back(pos);
    }
    size_t max_chill()
    {
        // create_queue_of_cars();
        int32_t car, car_pos;
        for (size_t i = 0; i < p; i++)
        {
            car = game_prefer[i];
            if (window.find(car) == window.end())
            {
                if (window.size() == k)
                {
                    positions[car].pop_front();
                    window.erase(which_pick.top().first);
                    which_pick.pop();
                }
                window.insert(car);
                ++this->energy;
            }
            if (positions[car].empty())
            {
                which_pick.push(make_pair(car, INT32_MAX));
            }
            else
            {
                car_pos = positions[car].front();
                which_pick.push(make_pair(car, car_pos));
                // positions[car].pop_front();
            }
        }
        return this->energy;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t n, k, p, car;

    cin >> n >> k >> p;

    Game game(n, k, p);

    for (size_t i = 0; i < p; i++)
    {
        cin >> car;
        game.set_future_position(car, i);
    }

    cout << game.max_chill() << endl;

    return 0;
}