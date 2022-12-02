#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    auto map = vector<vector<int>>(n, vector<int>(m));
    string line;
    for (int y = 0; y < n; ++y)
    {
        cin >> line;
	    for (int x = 0; x < m; ++x)
	    {
            map[y][x] = line[x] == '1' ? 0 : -1;
	    }
    }

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    map[0][0] = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == n-1 && x == m-1)
        {
            break;
        }

        for (int d = 0; d < 4; ++d)
        {
            int newY = y + dy[d];
            int newX = x + dx[d];

            if (newY < 0 || newY >= n || newX < 0 || newX >= m)
            {
                continue;
            }

            // 지나갔거나 갈 수 없는 곳
            if (map[newY][newX] != 0)
            {
                continue;
            }

            map[newY][newX] = map[y][x] + 1;
            q.push({ newY, newX });
        }
    }

    cout << map[n - 1][m - 1];
    
    return 0;
}