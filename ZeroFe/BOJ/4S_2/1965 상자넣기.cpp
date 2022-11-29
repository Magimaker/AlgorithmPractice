#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int input;
    vector<int> boxes;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        auto iter = lower_bound(boxes.begin(), boxes.end(), input);
        if (iter == boxes.end())
        {
            boxes.push_back(input);
        }
        else
        {
            *iter = input;
        }
    }


	cout << boxes.size();

    return 0;
}