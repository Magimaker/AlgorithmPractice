#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    int minValue = INT_MAX;
    int ans1, ans2;
    int start = 0;
	int end = n - 1;
    while (start < end)
    {
        int val = nums[start] + nums[end];
        int absVal = abs(val);
	    if (absVal <= minValue)
	    {
            minValue = absVal;
            ans1 = nums[start];
            ans2 = nums[end];
	    }

        if (val < 0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    cout << ans1 << " " << ans2;

    return 0;
}