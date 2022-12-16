#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 1000;

int N, M;
int arr[6][6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; ++y)
    {
	    for (int x = 0; x < M; ++x)
	    {
            cin >> arr[y][x];
	    }
    }

    // 어디 방향에서 왔는지 기록

    const int dx[3] = { 1, 0, -1 };
    
    vector<vector<int>> prevs(M, vector<int>(3));
    for (int y = 0; y < N; ++y)
    {
        vector<vector<int>> currs(M, vector<int>(3, MAX_VAL));

	    for (int x = 0; x < M; ++x)
	    {
            for (int i = 0; i < 3; ++i)
            {
                for (int d = 0; d < 3; ++d)
                {
                    int newX = x + dx[d];
                    if (newX < 0 || newX >= M)
                    {
                        continue;
                    }

                    if (i != d)
                    {
                        currs[x][i] = min(currs[x][i], prevs[newX][d] + arr[y][x]);
                    }
                }
            }
	    }

        swap(currs, prevs);
    }

    int minVal = MAX_VAL;
    for (int x = 0; x < M; ++x)
    {
	    for (int d = 0; d < 3; ++d)
	    {
            minVal = min(minVal, prevs[x][d]);
	    }
    }
    cout << minVal;
    
    return 0;
}