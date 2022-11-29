#include <iostream>

using namespace std;

int dp[2][100001];

const int MOD = 9901;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[0][0] = 1;
    dp[1][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = (dp[0][i - 1] + 2 * dp[1][i - 1]) % MOD;
        dp[1][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
    }
    
    cout << dp[0][n];

    return 0;
}