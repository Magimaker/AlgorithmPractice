#include <iostream>

using namespace std;

int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
 
    int prevMax = 3;
    for (int i = 0; i < num; i++)
    {
        int count;
        cin >> count;
        if (prevMax >= count)
        {
            cout << dp[count] << '\n';
            continue;
        }

        // dp(n, k) : n을 1 ... k를 이용해서 구성하는 방법의 수
        // dp(n, k) = dp(n-1, 1) + dp(n-2, 2) + dp(n-3, 3)
        // - dp(n-1, 1) = 1. 경우의 수가 하나밖에 없다
        // - dp(n-2, 2) = floor(n/2) (2의 개수만큼 있을 것이므로)
        // - dp(n-3, 3)의 경우 앞에 전부 3을 붙여준다고 생각하면 됨
        for (int j = 4; j <= count; j++)
        {
            dp[j] = dp[j - 3] + (j / 2) + 1;
        }
        cout << dp[count] << '\n';
        prevMax = count;
    }

    return 0;
}