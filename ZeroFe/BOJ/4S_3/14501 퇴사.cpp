#include <iostream>

using namespace std;

int dp[16];
int t[16];
int p[16];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] >> p[i];
    }

    int result = 0;
    // dp[n] = n일 때까지 얻은 수익
    for (int i = 0; i < n; ++i)
    {
        // i번째 날에 일을 한 경우
        if (i + t[i] <= n)
        {
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
            result = max(result, dp[i + t[i]]);
        }
        // i번째 날에 일을 하지 않는 경우
        dp[i + 1] = max(dp[i + 1], dp[i]);
        result = max(result, dp[i + 1]);
    }

    cout << result;
    
    return 0;
}