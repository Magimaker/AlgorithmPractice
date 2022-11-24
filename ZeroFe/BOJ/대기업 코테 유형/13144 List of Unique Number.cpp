#include <iostream>
#include <cassert>

using namespace std;

// 수열에 저장된 값
int nums[100001];
// 수열의 중복 개수 확인하는 용도
int memo[100001];

long long GetCases(int n)
{
    assert(n >= 0);

	if (n == 0)
	{
        return 0;
	}

	auto ll = static_cast<long long>(n);
    return (ll * (ll + 1)) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    long long total = 0;
    int end = 0;
    int prevEnd = 0;
    for (int curr = 0; curr < n; ++curr)
    {
        // 처음 탐색
	    while (end < n && memo[nums[end]] == 0)
	    {
            memo[nums[end]]++;
            end++;
	    }

        total += GetCases(end - curr) - GetCases(prevEnd - curr);

        prevEnd = end;
        memo[nums[curr]]--;
    }

    cout << total;

    return 0;
}