#include <iostream>
#include <queue>

using namespace std;

struct Point
{
    int y;
    int x;
    int dist;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    char map[1000][1001];

    int N, M;
    cin >> N >> M;

    queue<Point> jQ;
    queue<Point> fQ;
    for (int y = 0; y < N; ++y)
    {
        cin >> map[y];
        for (int x = 0; x < M; ++x)
        {
	        if (map[y][x] == 'J')
	        {
                jQ.push({ y, x, 1 });
	        }
            else if (map[y][x] == 'F')
            {
                fQ.push({ y, x, 1 });
            }
        }
    }

    int time = -1;
    const int dy[4] = { -1, 1, 0, 0 };
    const int dx[4] = { 0, 0, -1, 1 };
    int curr = 1;
    while (time == -1 && !jQ.empty())
    {
        // 선 불 전파
        while (!fQ.empty() && fQ.front().dist == curr)
        {
            int y = fQ.front().y;
            int x = fQ.front().x;
            int dist = fQ.front().dist;
            fQ.pop();

            for (int d = 0; d < 4; ++d)
            {
                int newY = y + dy[d];
                int newX = x + dx[d];

                if (newY < 0 || newY >= N || newX < 0 || newX >= M || map[newY][newX] == '#' || map[newY][newX] == 'F')
                {
                    continue;
                }

                map[newY][newX] = 'F';
                fQ.push({ newY, newX, dist + 1 });
            }
        }
        
        // 지훈이 탈출
        while (!jQ.empty() && jQ.front().dist == curr)
        {
            int y = jQ.front().y;
            int x = jQ.front().x;
            int dist = jQ.front().dist;
            jQ.pop();
            if (y == 0 || y == N - 1 || x == 0 || x == M - 1)
            {
                time = dist;
                break;
            }

            for (int d = 0; d < 4; ++d)
            {
                int newY = y + dy[d];
                int newX = x + dx[d];

                if (map[newY][newX] == '#' || map[newY][newX] == 'F' || map[newY][newX] == 'J')
                {
                    continue;
                }

                map[newY][newX] = 'J';
                jQ.push({ newY, newX, dist + 1 });
            }
        }

        curr++;
    }

    if (time == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << time;
    }

    return 0;
}