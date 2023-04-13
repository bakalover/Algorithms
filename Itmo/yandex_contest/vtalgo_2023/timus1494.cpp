#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t n, b, last;

    stack<int32_t> game;

    cin >> n;

    cin >> b;
    last = b;

    for (size_t i = 1; i < last; i++)
    {
        game.push(i);
    }

    for (size_t i = 1; i < n; i++)
    {
        cin >> b;
        if (b > last)
        {
            for (size_t i = last + 1; i < b; i++)
            {
                game.push(i);
            }
            last = b;
        }
        else
        {
            if (b != game.top())
            {
                cout << "Cheater" << endl;
                return 0;
            }
            game.pop();
        }
    }
    cout << "Not a proof" << endl;
    return 0;
}
