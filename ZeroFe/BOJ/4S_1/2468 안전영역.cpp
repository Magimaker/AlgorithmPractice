#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
bool visited[100][100];
vector<vector<int>> map;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

bool Find(int y, int x, int height)
{
	if (visited[y][x])
	{
        return false;
	}
    visited[y][x] = true;

	for (int d = 0; d < 4; ++d)
	{
        int newY = y + dy[d];
        int newX = x + dx[d];

        if (newY < 0 || newY >= N || newX < 0 || newX >= N || map[newY][newX] <= height)
        {
            continue;
        }

        Find(newY, newX, height);
	}

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    map = vector<vector<int>>(N, vector<int>(N));
    int height = 100, maxHeight = 1;
    for (int y = 0; y < N; ++y)
    {
	    for (int x = 0; x < N; ++x)
	    {
            cin >> map[y][x];
            height = min(height, map[y][x]);
            maxHeight = max(maxHeight, map[y][x]);
	    }
    }

    int maxArea = 1;
    while (height < maxHeight)
    {
        int curr = 0;
        memset(visited, 0, sizeof(visited));
        for (int y = 0; y < N; ++y)
        {
	        for (int x = 0; x < N; ++x)
	        {
		        if (map[y][x] > height && Find(y, x, height))
		        {
                    curr++;
		        }
	        }
        }
        maxArea = max(maxArea, curr);
        height++;
    }

    cout << maxArea;

    return 0;
}