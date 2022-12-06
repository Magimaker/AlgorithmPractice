#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> input(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> input[i];
    }

    map<int, int> poses;
    for (int v : input)
    {
        auto iter = poses.find(v);
        if (iter == poses.end())
        {
            poses[v] = 0;
        }
    }
    int num = 0;
    for (auto iter = poses.begin(); iter != poses.end(); ++iter)
    {
        iter->second = num++;
    }

    for (int v : input)
    {
        cout << poses[v] << " ";
    }

    return 0;
}