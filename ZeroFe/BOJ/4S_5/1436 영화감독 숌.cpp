#include <iostream>

using namespace std;

bool Has666(int val)
{
    int continuous6 = 0;
    while (val)
    {
        int num = val % 10;
        if (num == 6)
        {
            continuous6++;
            if (continuous6 == 3)
            {
                return true;
            }
        }
        else
        {
            continuous6 = 0;
        }
        val /= 10;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 무지성 666 찾기
    int count666 = 0;
    int n = 666;
    while (count666 < N)
    {
        if (Has666(n))
        {
            count666++;
        }

        if (count666 == N)
        {
            break;
        }
        ++n;
    }

    cout << n;

    return 0;
}