#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_VALUE = 301;

int N, M;
vector<vector<int>> map;
bool visited[MAX_VALUE][MAX_VALUE];

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

inline int Compress(int y, int x)
{
    return y * MAX_VALUE + x;
}

bool Find(int y, int x)
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

        if (map[newY][newX] == 0)
        {
            continue;
        }

        Find(newY, newX);
	}

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    map = vector<vector<int>>(N, vector<int>(M));
    for (int y = 0; y < N; ++y)
    {
	    for (int x = 0; x < M; ++x)
	    {
            cin >> map[y][x];
	    }
    }

    queue<int> ices;
    for (int y = 0; y < N; ++y)
    {
	    for (int x = 0; x < M; ++x)
	    {
		    if (map[y][x] != 0)
		    {
                ices.push(Compress(y, x));
		    }
	    }
    }

    // 녹는 얼음 처리
    queue<int> melt;
    int turn = 0;
    int remain = 1;
    while (remain == 1)
    {
        turn++;

        queue<int> tmp;
        while (!ices.empty())
        {
            int val = ices.front();
            ices.pop();
            int y = val / MAX_VALUE;
            int x = val % MAX_VALUE;

            for (int d = 0; d < 4; ++d)
            {
                int newY = y + dy[d];
                int newX = x + dx[d];

                if (map[newY][newX] == 0)
                {
                    map[y][x]--;
                }
            }

            // 녹았어도 지금 바로 녹은거로 처리하면 안 된다
            // (다른 얼음에 영향갈 수 있으므로)
            if (map[y][x] <= 0)
            {
                map[y][x] = -1;
                melt.push(Compress(y, x));
            }
            else
            {
	            // 아직 안 녹았으므로 다음 턴에 녹인다
                tmp.push(Compress(y, x));
            }
        }

        // 녹은 얼음 처리
        while (!melt.empty())
        {
            int val = melt.front();
            melt.pop();
            int y = val / MAX_VALUE;
            int x = val % MAX_VALUE;

            map[y][x] = 0;
        }
        
        // 개수 세기 - 빙산 있는거만 탐색하면 된다
        remain = 0;
        memset(visited, false, sizeof(visited));
        while (!tmp.empty())
        {
            int val = tmp.front();
            tmp.pop();
            int y = val / MAX_VALUE;
            int x = val % MAX_VALUE;

            if (Find(y, x))
            {
                remain++;
            }

            // 좌표 같으므로 다시 압축할 필요 없음
            ices.push(val);
        }
    }

    cout << (remain != 0 ? turn : 0);
    
    return 0;
}