#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string line;
    cin >> line;

    deque<int> zeros;
    deque<int> ones;
    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] == '0')
        {
            zeros.push_back(i);
        }
        else
        {
            ones.push_back(i);
        }
    }

    int halfZeroCount = zeros.size() / 2;
    int halfOneCount = ones.size() / 2;

    for (int i = 0; i < halfZeroCount; ++i)
    {
        zeros.pop_back();
    }
    for (int i = 0; i < halfOneCount; ++i)
    {
        ones.pop_front();
    }

    string ans;
    int p0 = 0;
    int p1 = 0;
    while (p0 < zeros.size() && p1 < ones.size())
    {
	    if (zeros[p0] <= ones[p1])
	    {
            ans.push_back('0');
            p0++;
	    }
        else
        {
            ans.push_back('1');
            p1++;
        }
    }

    while (p0 < zeros.size())
    {
        ans.push_back('0');
        p0++;
    }
    while (p1 < ones.size())
    {
        ans.push_back('1');
        p1++;
    }

    cout << ans;

    return 0;
}