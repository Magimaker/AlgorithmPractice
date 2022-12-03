#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> edges;
bool visited[1001];

void DFS(int v)
{
    if (visited[v])
    {
        return;
    }
    visited[v] = true;
    cout << v << " ";

    for (int e : edges[v])
    {
        DFS(e);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> V;

    edges = vector<vector<int>>(N + 1, vector<int>());

    for (int i = 0; i < M; ++i)
    {
        int start, end;
        cin >> start >> end;

        edges[start].push_back(end);
        edges[end].push_back(start);
    }
    for (int i = 1; i <= N; ++i)
    {
	    // 정점별로 소트
        sort(edges[i].begin(), edges[i].end());
    }

    // DFS
    memset(visited, false, sizeof(visited));
    DFS(V);
    cout << endl;

    // BFS
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(V);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (visited[v])
        {
            continue;
        }
        visited[v] = true;
        cout << v << " ";

        for (int e : edges[v])
        {
            q.push(e);
        }
    }
    
    return 0;
}