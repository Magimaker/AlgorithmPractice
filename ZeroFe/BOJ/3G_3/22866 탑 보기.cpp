#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> buildings(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> buildings[i];
    }

    // 건물 개수, 가장 가까운 건물
    vector<pair<int, int>> res(N);

    stack<int> rights;
    for (int i = N - 1; i >= 0; --i)
    {
	    while (!rights.empty() && buildings[rights.top()] <= buildings[i])
	    {
            rights.pop();
	    }

	    if (!rights.empty())
	    {
            res[i].first += rights.size();
            res[i].second = rights.top();
	    }
        rights.push(i);
    }
    stack<int> lefts;
    for (int i = 0; i < N; ++i)
    {
        while (!lefts.empty() && buildings[lefts.top()] <= buildings[i])
        {
            lefts.pop();
        }

        if (!lefts.empty())
        {
            res[i].first += lefts.size();
            if (abs(lefts.top() - i) <= abs(res[i].second - i))
            {
                res[i].second = lefts.top();
            }
        }
        lefts.push(i);
    }

    for (int i = 0; i < N; ++i)
    {
	    if (res[i].first)
	    {
            cout << res[i].first << " " << res[i].second + 1 << '\n';
	    }
        else
        {
            cout << res[i].first << '\n';
        }
    }

    return 0;
}