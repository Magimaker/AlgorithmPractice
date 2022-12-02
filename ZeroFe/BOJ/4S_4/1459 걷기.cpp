#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long X, Y, W, S;
    cin >> X >> Y >> W >> S;
    
    long long minTime = 0;
    if (S < W)
    {
        // 대각선으로만 이동하는 경우
        // 홀수인지 짝수인지 판별해야함
        if ((X + Y) % 2 == 0)
        {
            minTime = max(X, Y) * S;
        }
        else
        {
            minTime = (max(X, Y) - 1) * S + W;
        }
    }
    else if (S < 2 * W)
    {
        long long diagonal = min(X, Y);
        long long remain = (X + Y) - 2 * diagonal;
        minTime = diagonal * S + remain * W;
    }
    else
    {
        long long sum = X + Y;
        minTime = sum * W;
    }

    cout << minTime;
    
    return 0;
}