#include <iostream>
#include <vector>

using namespace std;

int Knapsack(int idx, int maxWeight);

const int MAX_ITEMS = 100;

int weights[MAX_ITEMS + 1];
int values[MAX_ITEMS + 1];

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        // 입력 받기
        cin >> weights[i] >> values[i];
    }
    vector<int> dp = vector<int>(K + 1);

    for (int i = 0; i < N; i++)
    {
        // 각 무게에 대해 탐색 시도
	    for (int j = K; j - weights[i] >= 0; j--)
	    {
            // 같은 아이템을 넣는 문제가 생길 수 있나?
            // 없음 - j가 하향식으로 진행되기 때문에 아이템을 넣은 경우 계산은 다른 dp[j]에 영향 안 줌
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
	    }
    }

    cout << dp[K] << endl;
    return 0;
}