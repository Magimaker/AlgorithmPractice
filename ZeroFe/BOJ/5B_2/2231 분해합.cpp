#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 999999의 경우 자릿수 다 더하면 54가 됨
    // 이 경우가 최대고, 이보다 작은 수는 각 자릿수 합이 54보다 작다
    for (int n = N - 54; n < N; ++n)
    {
        int tmp = n;
        int ctor = tmp;
        // 각 자릿수 더하기
        while (tmp > 0)
        {
            ctor += tmp % 10;
            tmp /= 10;
        }
        if (ctor == N)
        {
            cout << n;
            return 0;
        }
    }

    cout << 0;

    return 0;
}