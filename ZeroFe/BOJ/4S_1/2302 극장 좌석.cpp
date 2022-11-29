#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[41];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> fixed = vector<int>(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> fixed[i];
    }

    // 고정석 없을 때의 가짓수
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 40; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int total = 1;
    int pos = 0;
    int end;

    for (int v : fixed)
    {
        total *= dp[(v - 1 - pos)];
        pos = v;
    }

    // 마지막에 고정석 없을 경우 보정
    total *= dp[n - pos];

    cout << total;

    return 0;
}