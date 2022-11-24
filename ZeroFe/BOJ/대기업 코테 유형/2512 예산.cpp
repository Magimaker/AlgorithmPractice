#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, total;
    cin >> n;

    auto cities = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> cities[i];
    }
    cin >> total;

    sort(cities.begin(), cities.end());

    int curr = 0;
    int avg;
    while (curr < n)
    {
        int prev = curr;
        avg = total / (n - curr);

        while (curr < n && cities[curr] <= avg)
        {
            total -= cities[curr++];
        }

	    if (prev == curr)
	    {
            break;
	    }
    }

    avg = min(avg, cities[n - 1]);

    cout << avg;

    return 0;
}