#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    int last = 2;
    int multiple = 1;
    while (n > 2)
    {
        int isOdd = n % 2;
        n = (n >> 1) + isOdd;
        multiple <<= 1;
        if (!isOdd)
        {
            last += multiple;
        }
    }

    cout << last;

    return 0;
}