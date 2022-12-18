#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int N, M;
    cin >> N >> M;

    auto map = vector<vector<int>>(N, vector<int>(M));
    auto visited = vector<vector<bool>>(N, vector<bool>(M));
    using Point = pair<int, int>;
    queue<Point> q;

    for (int y = 0; y < N; ++y)
    {
	    for (int x = 0; x < M; ++x)
	    {
            int num;
            cin >> num;
            if (num == 0)
            {
                map[y][x] = -1;
            }
            else if (num == 2)
            {
                q.push({ y, x });
                visited[y][x] = true;
            }
	    }
    }

    const int dy[4] = {-1, 1, 0, 0};
    const int dx[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int newY = y + dy[d];
            int newX = x + dx[d];
            if (newY < 0 || newY >= N || newX < 0 || newX >= M || map[newY][newX] == -1 || visited[newY][newX])
            {
                continue;
            }

            visited[newY][newX] = true;
            map[newY][newX] = map[y][x] + 1;
            q.push({ newY, newX });
        }
    }

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            int print = visited[y][x] ? map[y][x] : (map[y][x] == -1 ? 0 : -1);
            cout << print << " ";
        }
        cout << '\n';
    }

    return 0;
}