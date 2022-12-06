#include <iostream>
#include <queue>

using namespace std;

int numCounts[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    int maxLength = 0;
    queue<int> q;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        q.push(num);
        numCounts[num]++;
        while (numCounts[num] > K)
        {
            int f = q.front();
            q.pop();
            numCounts[f]--;
        }
        maxLength = max(maxLength, static_cast<int>(q.size()));
    }

    cout << maxLength;

    return 0;
}