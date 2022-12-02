#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Pos
{
    int x;
    int y;
    int idx;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;
        vector<bool> visited = vector<bool>(n + 2);
        vector<Pos> poses = vector<Pos>(n + 2);
        for (int i = 0; i < n + 2; ++i)
        {
            poses[i].idx = i;
            cin >> poses[i].x >> poses[i].y;
        }
        sort(poses.begin(), poses.end(), [](const Pos& lhs, const Pos& rhs) {
            return lhs.x < rhs.x;
        });

        vector<vector<int>> graph = vector<vector<int>>(n + 2, vector<int>());
        for (int i = 0; i < n + 2; ++i)
        {
            int end;
            for (end = i; end < n + 2 && poses[end].x <= poses[i].x + 1000; ++end);

            // 그래프 연결하기
            for (int j = i + 1; j < end; ++j)
            {
                int diff = abs(poses[i].x - poses[j].x) + abs(poses[i].y - poses[j].y);
	            if (diff <= 1000)
	            {
		            // 갈 수 있는 곳
                    graph[poses[i].idx].push_back(poses[j].idx);
                    graph[poses[j].idx].push_back(poses[i].idx);
	            }
            }
        }

        // 탐색
        stack<int> st;
        st.push(0);
        while (!st.empty())
        {
            int curr = st.top();
            st.pop();

            if (visited[curr])
            {
                continue;
            }
            visited[curr] = true;

            for (auto next : graph[curr])
            {
                st.push(next);
            }
        }

        cout << (visited[n + 1] ? "happy" : "sad") << '\n';
    }
    
    return 0;
}