#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> connected;
vector<bool> visited;
int infected = 0;

void DFS(int curr)
{
	if (visited[curr])
	{
        return;
	}

    visited[curr] = true;
    infected++;

	for (int idx : connected[curr])
	{
        DFS(idx);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;

     visited = vector<bool>(n + 1, false);
     connected = vector<vector<int>>(n + 1, vector<int>());

    for (int i = 0; i < c; ++i)
    {
        int start, end;
        cin >> start >> end;

        connected[start].push_back(end);
        connected[end].push_back(start);
    }

    DFS(1);

    // 1번 컴퓨터 제외
    cout << infected - 1;
    
    return 0;
}