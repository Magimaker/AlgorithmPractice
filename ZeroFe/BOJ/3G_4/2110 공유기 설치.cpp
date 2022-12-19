#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, C;
    cin >> N >> C;
    vector<int> houses(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> houses[i];
    }
    sort(houses.begin(), houses.end());

    int start = 1;
    int end = houses[N - 1] - houses[0];
    int result = 0;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        int cnt = 1;
        int prevHouse = houses[0];
        // 최대 몇 개의 집을 넣을 수 있는지 구한다
        for (int i = 1; i < N; ++i)
        {
	        if (houses[i] - prevHouse >= mid)
	        {
                cnt++;
                prevHouse = houses[i];
	        }
        }

        // 만약 해당 거리로 전부 넣을 수 있다면 가능한 거리이다
        if (cnt >= C)
        {
            result = max(result, mid);
            start = mid + 1;
        }
        // 불가능한 경우 간격을 줄이고 다시 시도한다
        else
        {
            end = mid - 1;
        }
    }

    cout << result;

    return 0;
}