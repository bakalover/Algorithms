#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t t, n;
    float x_1, y_1, x_2, y_2, r_1, r_2;

    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        cin >> n >> x_1 >> y_1 >> x_2 >> y_2;
        x_1 = abs(x_1 - ((float)n / 2.0));
        y_1 = abs(y_1 - ((float)n / 2.0));
        x_2 = abs(x_2 - ((float)n / 2.0));
        y_2 = abs(y_2 - ((float)n / 2.0));
        cout << min(abs(x_1 - x_2),min(abs(y_1 - y_2),min( abs(y_1 - x_2), abs(x_1 - y_2)))) << endl;
    }

    return 0;
}
