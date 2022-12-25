#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    // 가장 큰 부분 증가 수열로 배치된 아이들을 기준으로 옮겨야 이동 수가 최소가 된다
    // 고로, 전체 크기에서 부분 증가 수열의 크기만큼 빼면 된다
    vector<int> orders;
    for (int num : nums)
    {
        auto iter = upper_bound(orders.begin(), orders.end(), num);
        if (iter == orders.end())
        {
            orders.push_back(num);
        }
        else
        {
            *iter = num;
        }
    }

    cout << N - orders.size();

    return 0;
}