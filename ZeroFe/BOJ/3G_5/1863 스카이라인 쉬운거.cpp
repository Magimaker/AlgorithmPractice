#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    stack<int> buildings;
    int total = 0;
    for (int i = 0; i < N; ++i)
    {
        int x, height;
        cin >> x >> height;

        while (!buildings.empty() && height < buildings.top())
        {
            buildings.pop();
            total++;
        }
        if (height > 0)
        {
	        if (buildings.empty() || height > buildings.top())
	        {
                buildings.push(height);
	        }
        }
    }

    // 스택에 남아있는거 전부 비우기
    total += buildings.size();

    cout << total;

    return 0;
}