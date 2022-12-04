#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    auto sensors = vector<int>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> sensors[i];
    }
    sort(sensors.begin(), sensors.end());

    auto diffs = vector<int>(N - 1);
    for (int i = 0; i < N - 1; ++i)
    {
        diffs[i] = sensors[i + 1] - sensors[i];
    }
    sort(diffs.begin(), diffs.end());

    int ans = 0;
    for (int i = 0; i < N - K; ++i)
    {
        ans += diffs[i];
    }
    cout << ans;
    
    return 0;
}