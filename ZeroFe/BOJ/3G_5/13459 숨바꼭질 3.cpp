#include <iostream>
#include <queue>

using namespace std;

const int MAX_VAL = 100001;

int N, K;
vector<bool> visited(MAX_VAL);

int Find()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, N});
    visited[N] = true;

    while (!pq.empty())
    {
        int time = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if (x == K) return time;

        int teleport = x << 1;
        if (teleport < MAX_VAL && !visited[teleport]) {
            pq.push({time, teleport});
            visited[teleport] = true;
        }

        int up = x + 1;
        if (up < MAX_VAL && !visited[up]) {
            pq.push({ time + 1, up });
            visited[up] = true;
        }

        int down = x - 1;
        if (down >= 0 && !visited[down]) {
            pq.push({ time + 1 , down });
            visited[down] = true;
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    cin >> N >> K;

    cout << Find();

    return 0;
}