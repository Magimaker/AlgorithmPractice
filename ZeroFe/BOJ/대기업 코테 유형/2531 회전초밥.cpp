#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    // 각각 초밥 번호, (같은 종류의) 개수
    auto map = unordered_map<int, int>();
    // 초밥은 회전하므로 앞의 k - 1개를 뒤에서도 넣을 수 있게 보정해야 한다
    vector<int> sushi = vector<int>(n + k - 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> sushi[i];
    }
    for (int i = n; i < n + k - 1; ++i)
    {
        sushi[i] = sushi[i - n];
    }

    int ans = 0;
    // 쿠폰 어차피 쓸거니까 쿠폰 선 사용
    map[c]++;
    // 처음 k개 연속도 먹어볼거니 추가
    for (int i = 0; i < k; ++i)
    {
        map[sushi[i]]++;
    }
    ans = map.size();
    for (int i = k; i < n + k - 1; ++i)
    {
        // 이전꺼 빼주고 새거 넣기
        map[sushi[i - k]]--;
        if (map[sushi[i - k]] == 0)
        {
            map.erase(sushi[i - k]);
        }
        map[sushi[i]]++;
        ans = max(ans, static_cast<int>(map.size()));
    }

    cout << ans;

    return 0;
}