#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int stickers[100000][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> stickers[i][0];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> stickers[i][1];
        }

        // 첫 열 n번 줄 떼는 경우 계산
        int prev[3] = { 0,stickers[0][0],stickers[0][1] };

        for (int i = 1; i < n; ++i)
        {
            int curr[3];
            // n번 줄 안 떼는 경우
            curr[0] = max(prev[1], prev[2]);
            curr[1] = max(prev[0], prev[2]) + stickers[i][0];
            curr[2] = max(prev[0], prev[1]) + stickers[i][1];

            // 갱신
            prev[0] = curr[0];
            prev[1] = curr[1];
            prev[2] = curr[2];
        }

        cout << max(prev[1], prev[2]) << '\n';
    }

    return 0;
}