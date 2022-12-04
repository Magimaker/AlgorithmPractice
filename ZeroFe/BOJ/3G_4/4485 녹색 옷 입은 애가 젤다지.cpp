#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_VALUE = 10000;

struct edge
{
    int weight;
    int endX;
    int endY;
};

struct compare
{
	bool operator()(edge& lhs, edge& rhs)
	{
        return lhs.weight < rhs.weight;
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 0;
    int N = 1;
    while (N > 0)
    {
        T++;
        cin >> N;
        if (N == 0)
        {
            break;
        }

        const int dy[4] = { -1, 1, 0, 0 };
        const int dx[4] = { 0, 0, -1, 1 };
        auto edges = vector<vector<vector<edge>>>(N, vector<vector<edge>>(N, vector<edge>()));
        int startWeight;
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < N; ++x)
            {
                int weight;
                cin >> weight;
                if (y == 0 && x == 0)
                {
                    startWeight = weight;
                }
                for (int d = 0; d < 4; ++d)
                {
                    int newY = y + dy[d];
                    int newX = x + dx[d];

                    if (newY < 0 || newY >= N || newX < 0 || newX >= N)
                    {
                        continue;
                    }

                    edges[newY][newX].push_back({ weight, x, y });
                }
            }
        }

        priority_queue<edge, vector<edge>, compare> pq;
        auto dist = vector<vector<int>>(N, vector<int>(N, -MAX_VALUE));
        pq.push({ -startWeight, 0, 0});
        dist[0][0] = -startWeight;

        while (!pq.empty())
        {
            auto weight = pq.top().weight;
            auto y = pq.top().endY;
            auto x = pq.top().endX;
            pq.pop();

            for (const auto& e : edges[y][x])
            {
                if (dist[e.endY][e.endX] < weight - e.weight)
                {
                    dist[e.endY][e.endX] = weight - e.weight;
                    pq.push({ dist[e.endY][e.endX], e.endX, e.endY });
                }
            }
        }

        cout << "Problem " << T << ": " << -dist[N - 1][N - 1] << '\n';
    }
    
    return 0;
}