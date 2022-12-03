#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    int y, x, sd;
    cin >> y >> x >> sd;
    // 회전은 북 -> 서 -> 남 -> 동 순인데 입력은 북->동->남->서 이므로 변환
    int currD = (4 - sd) % 4;

    auto map = vector<vector<int>>(N, vector<int>(M));
    for (int y = 0; y < N; ++y)
    {
	    for (int x = 0; x < M; ++x)
	    {
            cin >> map[y][x];
	    }
    }

    // Up, Left, Down, Right
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, -1, 0, 1 };

    // 벽 : 1, 빈 칸 : 0, 청소된 구역 : -1
    int res = 0;
    while (true)
    {
        // 현재 위치 청소
        if (map[y][x] == 0)
        {
            map[y][x] = -1;
            res++;
        }

        bool canMove = false;
	    for (int d = 1; d <= 4; ++d)
	    {
            currD = (currD + 1) % 4;
            int newY = y + dy[currD];
            int newX = x + dx[currD];

            // 범위 벗어났는지?
            if (newY < 0 || newY >= N || newX < 0 || newX >= M)
            {
                continue;
            }
            // 벽이거나 청소한 구역인지?
            if (map[newY][newX] != 0)
            {
                continue;
            }

            // 이동할 수 있으므로 이동
            y = newY;
            x = newX;
            canMove = true;
            break;
	    }

        // 청소 다 되어있거나 벽인 경우
        if (!canMove)
        {
            // 후진 시도
            int newY = y - dy[currD];
            int newX = x - dx[currD];

            // 후진 가능한지?
            if (newY < 0 || newY >= N || newX < 0 || newX >= M || map[newY][newX] == 1)
            {
                break;
            }

            // 후진 가능하면 후진
            y = newY;
            x = newX;
        }
    }

    cout << res;

    return 0;
}