#include <iostream>
#include <queue>

using namespace std;

const int MAX_TOWER = 500000;

int towers[MAX_TOWER];
int ans[MAX_TOWER];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> towers[i];
    }

    // 탑의 높이, 탑 인덱스
    auto pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>();
    for (int i = N - 1; i >= 0; --i)
    {
	    // 힙에서 먼저 꺼내서 비교
	    while (!pq.empty())
	    {
            int height = pq.top().first;
            if (towers[i] >= height)
            {
                int idx = pq.top().second;
                pq.pop();
                ans[idx] = i + 1;
            }
            else
            {
                break;
            }
	    }

        // 힙에 넣기
        pq.push({ towers[i], i });
    }

    // 힙에 있는 것들 전부 비우기 - 이것들은 레이저 맞아줄 탑이 없음
    while (!pq.empty())
    {
        int idx = pq.top().second;
        pq.pop();
        ans[idx] = 0;
    }

    for (int i = 0; i < N; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}