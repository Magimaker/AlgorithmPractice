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

    int end = 0;
    vector<pair<int, int>> inputs(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> inputs[i].first >> inputs[i].second;
        end = max(end, inputs[i].first + 1);
    }

    vector<int> heights(end);
    for (const auto& input : inputs)
    {
        heights[input.first] = input.second;
    }
    
    int left = 0;
    int right = end - 1;
    int leftHeight = heights[left];
    int rightHeight = heights[right];
    int sum = 0;
    while (left <= right)
    {
	    if (leftHeight <= rightHeight)
	    {
            sum += leftHeight;
            leftHeight = max(leftHeight, heights[++left]);
	    }
        else
        {
            sum += rightHeight;
            rightHeight = max(rightHeight, heights[--right]);
        }
    }

    cout << sum;

    return 0;
}