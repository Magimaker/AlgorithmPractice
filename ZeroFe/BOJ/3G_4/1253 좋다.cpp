#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int count = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int target = nums[i];
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
            {
                if (left != i && right != i) {
                    count++;
                    break;
                }
                else if (left == i) left++;
                else if (right == i) right--;
            }
            else if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
        }
    }

    cout << count;

    return 0;
}