#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> trees(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> trees[i];
    }

    int left = 0;
    int right = *max_element(trees.begin(), trees.end());
    int height = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long total = 0;
        for (int i = 0; i < N; ++i)
        {
            int cut = trees[i] - mid;   // 해당 높이로 나무 자르기
            if (cut > 0)     // 0 이상일 때만 자를 수 있음
            {
                total += cut;
            }
        }
        if (total >= M)
        {
            left = mid + 1;
            height = mid;
        }
        else if (total < M) // 나무 자르는게 부족하다
        {
            right = mid - 1;
        }
    }
    cout << height << '\n';

    return 0;
}