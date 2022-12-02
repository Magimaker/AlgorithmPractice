#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, L;
    cin >> N >> L;

    // first : 시작 위치, second : 끝 위치
    using puddle = pair<int, int>;
    vector<puddle> starts = vector<puddle>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> starts[i].first >> starts[i].second;
    }

    sort(starts.begin(), starts.end());

    int currPos = 0;
    int s = 0;
    int total = 0;
    while (s < N)
    {
        // 널빤지 까는 위치 = 웅덩이 시작점
        // 이미 깔려 있으면 중복해서 깔 필요 없다
	    if (currPos < starts[s].first)
	    {
            currPos = starts[s].first;
	    }

        // 널판지 깔아야하는 너비
        int width = starts[s].second - currPos;
        int count = 0;
        if (width > 0)
        {
            count = (width / L) + (width % L ? 1 : 0);
        }
        currPos += count * L;
        total += count;

        s++;
    }

    cout << total;
    
    return 0;
}