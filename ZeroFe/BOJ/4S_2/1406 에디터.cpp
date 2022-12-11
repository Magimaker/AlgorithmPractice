#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    string line;
    cin >> line;
    std::list<char> text;
    for (char c : line)
    {
        text.push_back(c);
    }
    auto cursor = text.end();

    int N;
    cin >> N;
    char command;
    char c;
    for (int i = 0; i < N; ++i)
    {
        cin >> command;
        switch (command)
        {
        case 'L':
	        if (cursor != text.begin())
	        {
                --cursor;
	        }
            break;
        case 'D':
            if (cursor != text.end())
            {
                ++cursor;
            }
            break;
        case 'B':
	        if (cursor != text.begin())
	        {
                auto temp = cursor;
                --temp;
                text.erase(temp);
	        }
            break;
        case 'P':
            cin >> c;
            text.insert(cursor, c);
            break;
        }
    }

    for (char c : text)
    {
        cout << c;
    }

    return 0;
}