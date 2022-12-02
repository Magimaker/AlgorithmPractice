#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<bool>> visited;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int DFS(int y, int x)
{
	if (visited[y][x])
	{
        return 0;
	}

    // 자기 위치 방문했음
    int res = 1;
    visited[y][x] = true;

	for (int d = 0; d < 4; ++d)
	{
        int newY = y + dy[d];
        int newX = x + dx[d];

        if (newY < 0 || newY >= n || newX < 0 || newX >= n)
        {
            continue;
        }

        res += DFS(newY, newX);
	}

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    visited = vector<vector<bool>>(n, vector<bool>(n));

    string line;
    for (int y = 0; y < n; ++y)
    {
        cin >> line;
        for (int x = 0; x < n; ++x)
        {
            // 못 지나가는 곳 = 방문했다 처리하기
            visited[y][x] = line[x] == '0';
        }
    }

    vector<int> houses;
    for (int y = 0; y < n; ++y)
    {
	    for (int x = 0; x < n; ++x)
	    {
            int res = DFS(y, x);
            if (res)
            {
                houses.push_back(res);
            }
	    }
    }
    sort(houses.begin(), houses.end());

    cout << houses.size() << '\n';
    for (int house : houses)
    {
        cout << house << '\n';
    }

    return 0;
}