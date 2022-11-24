#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, std::greater<>> pq;
    int input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
	    if (input != 0)
	    {
            pq.push(input);
            continue;
	    }

        if (pq.empty())
        {
            cout << "0" << '\n';
        }
        else
        {
            int minValue = pq.top();
            pq.pop();
            cout << minValue << '\n';
        }
    }

    return 0;
}