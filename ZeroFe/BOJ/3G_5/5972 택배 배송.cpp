#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX_VALUE = 2147483647;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    // 각각 끝점, 가중치
    using edge = std::pair<int, int>;
    auto edges = vector<vector<edge>>(n + 1, vector<edge>());
    for (int i = 0; i < m; ++i)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        edges[start].push_back({ end, weight });
        edges[end].push_back({ start, weight });
    }

    // 다익스트라
    auto dist = vector<int>(n + 1, MAX_VALUE);
    // 여기선 가중치, 시작점 순으로 사용한다
    priority_queue<pair<int, int>> pq;
	dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int start = pq.top().second;
        pq.pop();

        // 이미 도착했으면 갈 필요 없다
        if (start == n)
        {
            break;
        }

        for (auto& e : edges[start])
        {
	        if (dist[e.first] > dist[start] + e.second)
	        {
                dist[e.first] = dist[start] + e.second;
                pq.push({ -dist[e.first], e.first });
	        }
        }
    }

    cout << dist[n];

    return 0;
}