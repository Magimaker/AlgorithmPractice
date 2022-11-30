#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int prevMins[3] = {};
    int prevMaxs[3] = {};
    int currMins[3] = {};
    int currMaxs[3] = {};
    int curr[3] = {};
    
	for (int i = 0; i < n; ++i)
    {
        cin >> curr[0] >> curr[1] >> curr[2];

        currMins[0] = min(prevMins[0], prevMins[1]) + curr[0];
        currMins[1] = min(prevMins[0], min(prevMins[1], prevMins[2])) + curr[1];
        currMins[2] = min(prevMins[1], prevMins[2]) + curr[2];

        currMaxs[0] = max(prevMaxs[0], prevMaxs[1]) + curr[0];
        currMaxs[1] = max(prevMaxs[0], max(prevMaxs[1], prevMaxs[2])) + curr[1];
        currMaxs[2] = max(prevMaxs[1], prevMaxs[2]) + curr[2];

        // 구했으니 prev에 적용시킨다
        for (int j = 0; j < 3; ++j)
        {
            prevMins[j] = currMins[j];
            prevMaxs[j] = currMaxs[j];
        }
    }

    int ansMin = min(prevMins[0], min(prevMins[1], prevMins[2]));
    int ansMax = max(prevMaxs[0], max(prevMaxs[1], prevMaxs[2]));

    cout << ansMax << " " << ansMin;
    
    return 0;
}