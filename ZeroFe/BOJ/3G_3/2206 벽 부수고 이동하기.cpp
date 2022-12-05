#include <iostream>
#include <queue>

using namespace std;

struct info
{
    int y;
    int x;
    // 벽 얼마나 더 부술 수 있는지
    int breakCount;
};

bool walls[1000][1000];
int map[2][1000][1000];

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
            walls[y][x] = line[x] == '1' ? true : false;
        }
    }

    const int dy[4] = {-1, 1, 0, 0};
    const int dx[4] = {0, 0, -1, 1};

    queue<info> q;
    q.push({ 0, 0, 1 });
    map[1][0][0] = 1;
    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int breakCount = q.front().breakCount;
        q.pop();

        // 찾음 - 더 탐색할 필요 없다
        if (y == N - 1 && x == M - 1)
        {
            break;
        }

        for (int d = 0; d < 4; ++d)
        {
            int newY = y + dy[d];
            int newX = x + dx[d];
            int newBreakCount = breakCount;

            if (newY < 0 || newY >= N || newX < 0 || newX >= M || map[newBreakCount][newY][newX] > 0)
            {
                continue;
            }

            // 벽으로 막힌 경우
            if (walls[newY][newX])
            {
                // 카운트 소모해서 뚫기
	            if (newBreakCount > 0)
	            {
                    newBreakCount--;
	            }
                else
                {
                    continue;
                }
            }
            map[newBreakCount][newY][newX] = map[breakCount][y][x] + 1;
            q.push({ newY, newX, newBreakCount });
        }
    }

    const int INF = 1000001;
    int res = INF;
    for (int i = 0; i < 2; ++i)
    {
        if (map[i][N-1][M-1] > 0)
        {
            res = min(res, map[i][N - 1][M - 1]);
        }
    }
    if (res != INF)
    {
        cout << res;
    }
    else
    {
        cout << -1;
    }

    return 0;
}