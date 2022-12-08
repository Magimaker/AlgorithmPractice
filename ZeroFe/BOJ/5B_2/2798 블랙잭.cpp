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

    vector<int> cards(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> cards[i];
    }

    int maxValue = 0;
    for (int i = 0; i < N; ++i)
    {
	    for (int j = i + 1; j < N; ++j)
	    {
		    for (int k = j + 1; k < N; ++k)
		    {
                int sum = cards[i] + cards[j] + cards[k];
			    if (sum <= M)
			    {
                    maxValue = max(maxValue, sum);
			    }
		    }
	    }
    }

    cout << maxValue;

    return 0;
}