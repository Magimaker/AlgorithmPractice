#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_SIZE = 50;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

vector<vector<int>> regions;
vector<int> sums;

int N;
int L, R;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

bool Travel(int y, int x, int num)
{
	if (visited[y][x])
	{
        return false;
	}
    visited[y][x] = true;
	if (regions.size() <= num)
	{
        regions.emplace_back();
        sums.push_back(0);
	}
    regions[num].push_back(y * N + x);
    sums[num] += map[y][x];

    for (int d = 0; d < 4; ++d)
    {
        int newY = y + dy[d];
        int newX = x + dx[d];

        if (newY < 0 || newY >= N || newX < 0 || newX >= N)
        {
            continue;
        }

        int diff = abs(map[newY][newX] - map[y][x]);
        if (diff >= L && diff <= R)
        {
            Travel(newY, newX, num);
        }
    }

    return true;
}

bool MovePeople(vector<int>& region, int avg)
{
	for (int i = 0; i < region.size(); ++i)
	{
        int y = region[i] / N;
        int x = region[i] % N;
        map[y][x] = avg;
	}

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    cin >> N >> L >> R;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> map[y][x];
        }
    }

    int day = 0;
    bool moved;
    do
    {
        // 초기화
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < regions.size(); ++i)
        {
            regions[i].clear();
            sums[i] = 0;
        }

        // 탐색
        int idx = 0;
        for (int y = 0; y < N; ++y)
        {
	        for (int x = 0; x < N; ++x)
	        {
                idx += Travel(y, x, idx);
	        }
        }

        // 인구 이동 시도
        moved = false;
        for (int i = 0; i < regions.size(); ++i)
        {
	        if (regions[i].size() > 1)
	        {
                int avg = sums[i] / regions[i].size();
                moved |= MovePeople(regions[i], avg);
	        }
        }

        if (!moved)
        {
            break;
        }
        day++;
    }
    while (true);

    cout << day;
    
    return 0;
}