#include <iostream>
#include <cctype>

using namespace std;

int alphabets[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string word;
    cin >> word;

    if (word.empty())
    {
        cout << "?";
        return 0;
    }

    for (auto c : word)
    {
        auto bigC = toupper(c);
        alphabets[bigC - 'A']++;
    }

    int maxCount = 0;
    char maxAlpha;
    for (int i = 0; i < 26; i++)
    {
	    if (alphabets[i] > maxCount)
	    {
            maxCount = alphabets[i];
            maxAlpha = static_cast<char>('A' + i);
	    }
        else if (alphabets[i] == maxCount)
        {
            maxAlpha = '?';
        }
    }

    cout << maxAlpha;

    return 0;
}