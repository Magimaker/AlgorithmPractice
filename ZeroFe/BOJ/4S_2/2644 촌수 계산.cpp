#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t1, t2, m;
    cin >> n >> t1 >> t2 >> m;

    vector<bool> visited = vector<bool>(n + 1);
    vector<vector<int>> connected = vector<vector<int>>(n + 1, vector<int>());
    for (int i = 0; i < m; ++i)
    {
        int start, end;
        cin >> start >> end;

        connected[start].push_back(end);
        connected[end].push_back(start);
    }

    // 탐색 위치, 현재 촌수
    int targetDepth = -1;
    stack<pair<int, int>> st;
    st.push({t1, 0});
    while (!st.empty())
    {
        int curr = st.top().first;
        int depth = st.top().second;
        st.pop();

        // 찾음
        if (curr == t2)
        {
            targetDepth = depth;
            break;
        }

        // 이미 방문함
        if (visited[curr])
        {
            continue;
        }
        visited[curr] = true;

        for (int idx : connected[curr])
        {
            st.push({ idx, depth + 1 });
        }
    }

    cout << targetDepth;

    return 0;
}