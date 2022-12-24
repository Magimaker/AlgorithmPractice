#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, W;
    cin >> H >> W;

    vector<int> heights(W + 2);
    for (int i = 1; i <= W; ++i)
    {
        cin >> heights[i];
    }

    int total = 0;
    int left = 1, right = W;
    int leftHeight = heights[left], rightHeight = heights[right];
    while (left <= right)
    {
	    if (leftHeight <= rightHeight)
	    {
            total += leftHeight - heights[left];
            leftHeight = max(leftHeight, heights[++left]);
	    }
        else
        {
            total += rightHeight - heights[right];
            rightHeight = max(rightHeight, heights[--right]);
        }
    }

    cout << total;

    return 0;
}