#include <iostream>
#include <unordered_set>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char game;
    int count;
    cin >> count >> game;

    string name;
    auto set = unordered_set<string>();
    for (int i = 0; i < count; i++)
    {
        cin >> name;
        auto iter = set.find(name);
        if (iter == set.end())
        {
            set.insert(name);
        }
    }

    int div = 1;
    switch (game)
    {
	    case 'Y': div = 1; break;
	    case 'F': div = 2; break;
	    case 'O': div = 3; break;
    }

    cout << set.size() / div;

    return 0;
}