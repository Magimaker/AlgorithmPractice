#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, X;
    cin >> N >> X;

    vector<int> days(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> days[i];
    }

    int currVisitor = 0;
    int maxVisitor = 0;
    int times = 1;
    // 1일차부터 X일차까지 방문자 수
    for (int i = 0; i < X; ++i)
    {
        currVisitor += days[i];
    }
    maxVisitor = currVisitor;

    for (int i = X; i < N; ++i)
    {
        currVisitor -= days[i - X];
        currVisitor += days[i];
        if (currVisitor > maxVisitor)
        {
            maxVisitor = currVisitor;
            times = 1;
        }
        else if (currVisitor == maxVisitor)
        {
            times++;
        }
    }

    if (maxVisitor == 0)
    {
        cout << "SAD";
    }
    else
    {
        cout << maxVisitor << '\n' << times;
    }

    return 0;
}