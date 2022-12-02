#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> rooms = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> rooms[i];
    }

    int man, sub;
    cin >> man >> sub;
    long long total = 0;
    for (int i = 0; i < n; ++i)
    {
        int remain = rooms[i] - man;
        total += 1;
        if (remain > 0)
        {
            total += remain / sub;
            total += remain % sub ? 1 : 0;
        }
    }

    cout << total;
    
    return 0;
}