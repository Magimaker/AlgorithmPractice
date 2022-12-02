#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    const int maxSize = 100000;

    auto map = vector<int>(maxSize + 1, -1);
    // 수빈이 위치
    map[n] = 0;
	queue<int> q;
    q.push(n);

    // 이동 어떻게 할지
    function<int(int)> moveFuncs[] = {
        [](int x) {return x - 1; },
        [](int x) {return x + 1; },
        [](int x) {return 2 * x; }
    };
    
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        // 찾았음
        if (curr == k)
        {
            break;
        }

        // 각 이동 방식에 대해
        for (int i = 0; i < 3; ++i)
        {
            int x = moveFuncs[i](curr);
            // 갈 수 없는 곳 혹은 이미 탐색한 곳
            if (x < 0 || x > maxSize || map[x] != -1)
            {
	            continue;
            }

            map[x] = map[curr] + 1;
            q.push(x);
        }
    }

    cout << map[k];
    
    return 0;
}