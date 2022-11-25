#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_VALUE = 100000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;

    auto dp = vector<int>(d + 1, MAX_VALUE);
    dp[0] = 0;

    map<int, map<int, int>> shortcuts;
    for (int i = 0; i < n; ++i)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

    	auto iter = shortcuts.find(end);
        if (iter != shortcuts.end())
        {
            auto iter2 = iter->second.find(start);
	        if (iter2 != iter->second.end())
	        {
                // 기존 지름길과 비교
                shortcuts[end][start] = min(iter2->second, weight);
	        }
            else
            {
                shortcuts[end][start] = weight;
            }
        }
        else
        {
            shortcuts[end][start] = weight;
        }
    }

    for (int i = 1; i <= d; ++i)
    {
        // 기본 도로 달리기
        dp[i] = min(dp[i - 1] + 1, dp[i]);
        auto iter = shortcuts.find(i);
        if (iter != shortcuts.end())
        {
	        for (const auto & load : iter->second)
	        {
                dp[i] = min(dp[i], dp[load.first] + load.second);
	        }
        }
    }

    cout << dp[d];

    return 0;
}