#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    string line;
    cin >> line;

	int total = 0;
    for (int i = 0; i < N; ++i)
    {
	    if (line[i] == 'P')
	    {
		    for (int j = i - K; j <= i + K; ++j)
		    {
			    if (j < 0 || j >= N)
			    {
					continue;
			    }

			    if (line[j] == 'H')
			    {
					line[j] = ' ';
					total++;
					break;
			    }
		    }
	    }
    }

	cout << total;
}