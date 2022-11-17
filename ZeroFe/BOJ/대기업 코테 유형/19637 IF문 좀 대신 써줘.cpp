#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int titleCount, userCount;
    cin >> titleCount >> userCount;

    multimap<int, string> titles;
    for (int i = 0; i < titleCount; i++)
    {
        int power;
        string title;
        cin >> title >> power;
    	titles.insert({ power, title });
    }

    for (int i = 0; i < userCount; i++)
    {
        int power;
        cin >> power;
        auto iter = titles.lower_bound(power);
        cout << iter->second << '\n';
    }

    return 0;
}