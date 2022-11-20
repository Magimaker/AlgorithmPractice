#include <iostream>
#include <vector>

using namespace std;

const int VALUE_MIN = -1000000001;

int alphabets[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    auto table = vector<vector<int>>(n, vector<int>(n));
    for (int y = 0; y < n; ++y)
    {
	    for (int x = 0; x < n; ++x)
	    {
            cin >> table[y][x];
	    }
    }

    int rank = 0;
    int current = 0;
    auto orders = vector<int>(n, n - 1);
    while (rank < n)
    {
        int maxNum = VALUE_MIN;
        int maxIdx = 0;
	    for (int i = 0; i < n; ++i)
	    {
            int num = table[orders[i]][i];
            if (num > maxNum)
		    {
                maxNum = num;
                maxIdx = i;
		    }
	    }
        current = maxNum;
        rank++;
        orders[maxIdx]--;
    }

    cout << current;

    return 0;
}