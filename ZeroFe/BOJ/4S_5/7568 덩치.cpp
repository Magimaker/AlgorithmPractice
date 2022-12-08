#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> heights(N);
    vector<int> weights(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> weights[i] >> heights[i];
    }

    for (int i = 0; i < N; ++i)
    {
        int rank = 1;
	    for (int j = 0; j < N; ++j)
	    {
		    if (weights[i] < weights[j] && heights[i] < heights[j])
		    {
                rank++;
		    }
	    }
        cout << rank << " ";
    }

    return 0;
}