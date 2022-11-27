#include <iostream>

long long dp[101];

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 먼저 파도반 수열 구하기
    dp[0] = dp[1] = dp[2] = 1;
    for (int i = 3; i < 100; ++i)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;
        cout << dp[n-1] << '\n';
    }

    return 0;
}