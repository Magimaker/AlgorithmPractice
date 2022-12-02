#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    vector<int> floor = vector<int>(F + 1, -1);
    floor[S] = 0;
    auto func = [U, D](int curr, int up) { return up ? curr + U : curr - D; };
    queue<int> q;
    q.push(S);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == G)
        {
            break;
        }

        for (int i = 0; i < 2; ++i)
        {
            int next = func(curr, i);
            // 갈 수 없는 경우 혹은 이미 이동한 경우
            if (next < 1 || next > F || floor[next] != -1)
            {
                continue;
            }

            floor[next] = floor[curr] + 1;
            q.push(next);
        }
    }

    if (floor[G] != -1)
    {
        cout << floor[G];
    }
    else
    {
        cout << "use the stairs";
    }

    return 0;
}