#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    dp[0] = 1;
    vector<int> coins = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    for (int coin : coins)
    {
	    for (int i = coin; i <= k; ++i)
	    {
            dp[i] += dp[i - coin];
	    }
    }

    cout << dp[k];
    
    return 0;
}