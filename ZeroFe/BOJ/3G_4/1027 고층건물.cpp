#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int N;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> heights[i];
    }

    int maxCount = 0;
    for (int i = 0; i < N; ++i)
    {
        int leftCount = 0;
        double leftSlope = MAX_VAL;
        for (int l = i - 1; l >= 0; --l)
        {
            double slope = static_cast<double>(heights[i] - heights[l]) / static_cast<double>(i - l);
	        if (slope < leftSlope)
	        {
                leftCount++;
                leftSlope = slope;
	        }
        }

        int rightCount = 0;
        double rightSlope = -MAX_VAL;
	    for (int r = i + 1; r < N; ++r)
	    {
            double slope = static_cast<double>(heights[r] - heights[i]) / static_cast<double>(r - i);
            if (rightSlope < slope)
            {
                rightCount++;
                rightSlope = slope;
            }
	    }

        maxCount = max(maxCount, leftCount + rightCount);
    }

    cout << maxCount;
    
    return 0;
}