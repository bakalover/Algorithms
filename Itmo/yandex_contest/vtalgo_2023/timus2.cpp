#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int16_t T, k, n, small_count, big_count, small, big;

    cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        cin >> n >> k;
        big_count = n % k;
        small_count = k - big_count;
        small = n / k;
        big = small + 1;
        cout << (small_count * (small * small * (small_count - 1) + small * big * big_count) + big_count * (big * big * (big_count - 1) + big * small * small_count)) / 2
             << endl;
    }

    return 0;
}