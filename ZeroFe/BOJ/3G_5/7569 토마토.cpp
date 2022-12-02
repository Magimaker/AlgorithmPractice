#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vec3
{
    int x;
    int y;
    int z;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 가로, 세로, 높이
    int M, N, H;
    cin >> M >> N >> H;

    // 가로 세로 높이는 각각 X, Z, Y에 대응됨
    auto map = vector<vector<vector<int>>>(H, vector<vector<int>>(N, vector<int>(M)));
    for (int y = 0; y < H; ++y)
    {
	    for (int z = 0; z < N; ++z)
	    {
		    for (int x = 0; x < M; ++x)
		    {
                cin >> map[y][z][x];
		    }
	    }
    }

    // 초기 큐에 다 집어넣기
    queue<Vec3> q;
    for (int y = 0; y < H; ++y)
    {
        for (int z = 0; z < N; ++z)
        {
            for (int x = 0; x < M; ++x)
            {
                if(map[y][z][x] == 1)
                {
                    q.push({ x, y, z });
                }
            }
        }
    }

    const int dx[6] = { 0, 0, -1, 1, 0, 0 };
    const int dy[6] = { 0, 0, 0, 0, -1, 1 };
    const int dz[6] = { -1, 1, 0, 0, 0, 0 };
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        for (int d = 0; d < 6; ++d)
        {
            int newX = x + dx[d];
            int newY = y + dy[d];
            int newZ = z + dz[d];

            if (newX < 0 || newX >= M || newY < 0 || newY >= H || newZ < 0 || newZ >= N)
            {
	            continue;
            }

            if (map[newY][newZ][newX] != 0)
            {
                continue;
            }

            map[newY][newZ][newX] = map[y][z][x] + 1;
            q.push({ newX, newY, newZ });
        }
    }

    // 익지 않은 토마토 있는지 탐색
    int day = 0;
    bool notFinished = false;
    for (int y = 0; y < H && !notFinished; ++y)
    {
        for (int z = 0; z < N && !notFinished; ++z)
        {
            for (int x = 0; x < M && !notFinished; ++x)
            {
                if (map[y][z][x] == 0)
                {
                    notFinished = true;
                }
                else if (map[y][z][x] > 0)
                {
                    day = max(day, map[y][z][x]);
                }
            }
        }
    }

    if (notFinished)
    {
        cout << -1;
    }
    else
    {
        cout << day - 1;
    }

    return 0;
}