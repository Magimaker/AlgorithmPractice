#include <iostream>
#include <vector>

using namespace std;

int stairs[301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> dp = vector< vector<int>>(2, vector<int>(n+1));

    for (int i = 1; i <= n; ++i)
    {
        cin >> stairs[i];
    }

    dp[0][1] = stairs[1];
    dp[0][2] = stairs[2];
    // 연속 지났을 때
    dp[1][2] = dp[0][1] + stairs[2];

    for (int i = 3; i <= n; ++i)
    {
        // 연속해서 가지 않은 경우
        dp[0][i] = stairs[i] + max(dp[1][i-2], dp[0][i-2]);
        dp[1][i] = stairs[i] + dp[0][i - 1];
    }

    int ret = max(dp[0][n], dp[1][n]);
    cout << ret;

    return 0;
}