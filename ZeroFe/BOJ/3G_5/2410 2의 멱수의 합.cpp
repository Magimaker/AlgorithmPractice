#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 1000000000;

int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // 2^19까지가 1000000에 포함됨
    vector<int> twoPower = vector<int>(20);
    for (int i = 0; i < twoPower.size(); ++i)
    {
        twoPower[i] = 1 << i;
    }
    dp[0] = 1;

    for (int t : twoPower)
    {
	    for (int i = t; i <= n; ++i)
	    {
            dp[i] = (dp[i] + dp[i - t]) % MOD;
	    }
    }

    cout << dp[n];
    
    return 0;
}