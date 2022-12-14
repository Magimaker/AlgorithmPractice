#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    // Floyd
    // 초기화
    auto paths = vector<vector<int>>(N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i)
    {
        paths[i][i] = 0;
    }

    for (int i = 0; i < M; ++i)
    {
        int start, end, distance;
        cin >> start >> end >> distance;
        paths[start - 1][end - 1] = distance;
    }

    for (int k = 0; k < N; ++k)
    {
	    for (int i = 0; i < N; ++i)
	    {
		    for (int j = 0; j < N; ++j)
		    {
                paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
		    }
	    }
    }

    // 각 학생 별로 최다시간 구하기
    int maxVal = 0;
    for (int i = 0; i < N; ++i)
    {
        maxVal = max(maxVal, paths[i][X - 1] + paths[X - 1][i]);
    }

    cout << maxVal;

    return 0;
}