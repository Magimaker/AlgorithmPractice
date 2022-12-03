#include <iostream>

using namespace std;

int FindMines(string nums)
{
    int currMine = 0;
    int n = nums.size();

    for (int i = 1; i < n; ++i)
    {
        // 지뢰 설치할 수 없는 케이스
        if (nums[i - 1] < '0' || nums[i - 1] > '1')
        {
            return -1;
        }

        if (nums[i - 1] == '1')
        {
            nums[i - 1]--;
            nums[i]--;
            if (i + 1 < n)
            {
                nums[i + 1]--;
            }
            currMine++;
        }
    }

    return currMine;
}

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

        string nums, mines;
        cin >> nums >> mines;

        // 지뢰가 깔리는 경우 크게 2가지
        // 1. 첫 번째에 지뢰가 깔리지 않은 경우
        int maxMine = 0;
        maxMine = max(maxMine, FindMines(nums));

        // 2. 첫 번째에 지뢰가 깔린 경우
        nums[0]--;
        if (n > 1)
        {
            nums[1]--;
        }
        maxMine = max(maxMine, FindMines(nums) + 1);

        cout << maxMine << '\n';
    }
    
    return 0;
}