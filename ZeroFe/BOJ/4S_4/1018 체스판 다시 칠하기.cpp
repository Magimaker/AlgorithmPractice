#include <iostream>

using namespace std;

char board[50][50];

char color[2] = { 'W', 'B'};

int GetChangeCount(int startY, int startX, bool topLeftWhite)
{
    int changeCount = 0;
    for (int y = startY; y < startY + 8; ++y)
    {
	    for (int x = startX; x < startX + 8; ++x)
	    {
            int idx = ((y - startY) % 2 + (x - startX) % 2 + topLeftWhite) % 2;
            if (color[idx] != board[y][x])
            {
                changeCount++;
            }
	    }
    }

    return changeCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    string line;
    for (int y = 0; y < N; ++y)
    {
        cin >> line;
        for (int x = 0; x < M; ++x)
        {
            board[y][x] = line[x];
        }
    }

    int minValue = 32;
    for (int y = 0; y <= N - 8; ++y)
    {
	    for (int x = 0; x <= M - 8; ++x)
	    {
            minValue = min(minValue, GetChangeCount(y, x, true));
            minValue = min(minValue, GetChangeCount(y, x, false));
            if (minValue == 0)
            {
                cout << minValue;
                return 0;
            }
	    }
    }

    cout << minValue;

    return 0;
}