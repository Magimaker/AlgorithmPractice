#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    cin >> M >> N;

    vector<int> snacks(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> snacks[i];
    }

    int left = 1;
    int right = *max_element(snacks.begin(), snacks.end());
    int snack = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int count = 0;
        for (int i = 0; i < N; ++i)
        {
            count += snacks[i] / mid; // mid 길이로 나눠줄 수 있는 과자 양
        }
        if (count >= M)
        {
            left = mid + 1;
            snack = mid;
        }
        else if (count < M) // 과자 나눠줄 수 없을 때
        {
            right = mid - 1;
        }
    }
    cout << snack << '\n';

    return 0;
}