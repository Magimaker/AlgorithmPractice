#include <iostream>
#include <vector>

using namespace std;

int dist[200][200];
int pathes[1000];

const int INF = 10000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    // Floyd
    for (int i = 0; i < N; ++i)
    {
	    for (int j = 0; j < N; ++j)
	    {
            cin >> dist[i][j];
            if (j != i && dist[i][j] == 0)
            {
                dist[i][j] = INF;
            }
	    }
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> pathes[i];
    }

    for (int i = 0; i < N; ++i)
    {
	    for (int j = 0; j < N; ++j)
	    {
		    for (int x = 0; x < N; ++x)
		    {
			    if (dist[j][x] > dist[j][i] + dist[i][x])
			    {
                    dist[j][x] = dist[j][i] + dist[i][x];
			    }
		    }
	    }
    }

    bool canVisit = true;
    for (int i = 0; i < M - 1; ++i)
    {
	    if (dist[pathes[i] - 1][pathes[i+1] - 1] == INF)
	    {
            canVisit = false;
            break;
	    }
    }
    cout << (canVisit ? "YES" : "NO");
    
    return 0;
}