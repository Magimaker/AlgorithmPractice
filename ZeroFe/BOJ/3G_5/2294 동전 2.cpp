#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001];

const int IMPASSIBLE = 10001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    // 처음엔 다 불가능하고, 이후엔 가능한거로 생각하기
    std::fill(dp, dp + 10001, IMPASSIBLE);
    // 0원은 동전 0개 필요하다
    dp[0] = 0;

    vector<int> coins = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    for (int coin : coins)
    {
	    for (int i = coin; i <= k; ++i)
	    {
            // 동전 최소 개수 = 현재 동전 개수 혹은 동전 추가했을 때의 개수가 최소
            dp[i] = min(dp[i], dp[i - coin] + 1);
	    }
    }

    cout << (dp[k] != IMPASSIBLE ? dp[k] : -1);
    
    return 0;
}