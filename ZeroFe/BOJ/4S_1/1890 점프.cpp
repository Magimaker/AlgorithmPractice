#include <iostream>

int board[100][100];
long long dp[110][110];

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
	    for (int j = 0; j < n; ++j)
	    {
            cin >> board[i][j];
	    }
    }

    dp[0][0] = 1;
    for (int y = 0; y < n; ++y)
    {
	    for (int x = 0; x < n; ++x)
	    {
            int move = board[y][x];
		    if (move != 0)
		    {
                dp[y + move][x] += dp[y][x];
                dp[y][x + move] += dp[y][x];
		    }
	    }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}