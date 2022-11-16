#include <iostream>

using namespace std;

const int MAX_COUNT = 100000;

int nums[MAX_COUNT];
int sums[MAX_COUNT];
int dp[MAX_COUNT];
int idxs[MAX_COUNT];

int MinPartSumLength(int N, int S)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        if (nums[i] >= S)
        {
            // 만약 수열의 수가 S 이상이라면 무조건 1이므로 더 계산할 필요가 없다
            return 1;
        }
        sum += nums[i];
        sums[i] = sum;
    }

    // 수열을 다 더해도 S를 못 만드는 경우 불가능하다
    if (sum < S)
    {
        return 0;
    }

    // dp 시작 - 첫 수는 다 더해도 S가 안 나온다
    // (수열 넣을 때 이미 확인함)
    dp[0] = MAX_COUNT;
    idxs[0] = -1;
    for (int i = 1; i < N; i++)
    {
        if (sums[i] < S)
        {
            dp[i] = MAX_COUNT;
            idxs[i] = -1;
            continue;
        }

    	// S 이상인 경우
        // 인덱싱 활용해서 이전에 뺄거 있나 확인하기
        int idx = idxs[i-1] != -1 ? idxs[i-1] : -1;
        sum = sums[i];
        if (idx != -1)
        {
            sum -= sums[idx];
        }

        // 더 뺄 수 있나 확인하기
        do {
            sum -= nums[++idx];
        } while (sum >= S);
        // idx 기록
        idxs[i] = idx - 1;

        // dp 기록
        dp[i] = min(dp[i - 1], i - idx + 1);
    }

    return dp[N - 1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    cin >> N >> S;

    cout << MinPartSumLength(N, S);
    
    return 0;
}