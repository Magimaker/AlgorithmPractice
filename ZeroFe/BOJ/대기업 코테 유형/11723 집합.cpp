#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M;
    cin >> M;

    string op;
    int x;
    int S = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> op;
        if (op == "add")
        {
            cin >> x;
            S |= 1 << x;
        }
        else if (op == "remove")
        {
            cin >> x;
            S &= ~(1 << x);
        }
        else if (op == "check")
        {
            cin >> x;
            int result = (S & (1 << x)) ? 1 : 0;
            cout << result << '\n';
        }
        else if (op == "toggle")
        {
            cin >> x;
            S ^= 1 << x;
        }
        else if (op == "all")
        {
            // 전체 비트에 들어온다
            S |= (1 << 21) - 1;
        }
        else if (op == "empty")
        {
            S = 0;
        }
    }

    return 0;
}