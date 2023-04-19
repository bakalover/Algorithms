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

public:
    Game(int32_t n, int32_t k, int32_t p) : positions(n + 1, deque<int32_t>()), window(), which_pick(), game_prefer()
    {
        this->n = n;
        this->k = k;
        this->p = p;
        energy = 0;
    }
    ~Game() {}

    void set_future_position(int32_t car, int32_t pos)
    {
        game_prefer.push_back(car);
        positions[car].push_back(pos);
    }
    size_t max_chill()
    {
        int32_t car, car_pos;
        for (size_t i = 0; i < game_prefer.size(); i++)
        {
            car = game_prefer[i];
            positions[car].pop_front();
            if (window.find(car) == window.end())
            {
                if (window.size() == k)
                {
                    window.erase(which_pick.top().first);
                    which_pick.pop();
                    window.insert(car);
                    ++this->energy;
                }
                else
                {
                    window.insert(car);
                    ++this->energy;
                }
            }
            if (!positions[car].empty())
            {
                car_pos = positions[car].front();
                which_pick.push(make_pair(car, car_pos));
            }
            else
            {
                which_pick.push(make_pair(car, 10000000));
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