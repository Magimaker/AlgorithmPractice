#include <iostream>
#include <cmath>

using namespace std;

string firstWord;
int firstChars[26];
int otherChars[26];

bool IsSimilar(string& word)
{
    int lhsSize = firstWord.size();
    int rhsSize = word.size();
    int diff = abs(lhsSize - rhsSize);
	if (diff > 1)
	{
        return false;
	}

    memset(otherChars, 0, sizeof(otherChars));
    for (char c : word)
    {
        otherChars[c - 'A']++;
    }

    int count = 0;

    for (int i = 0; i < 26; ++i)
    {
        if (firstChars[i] != otherChars[i])
        {
            count += abs(firstChars[i] - otherChars[i]);
        }
    }

    if (count > 2)
    {
        return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int N;
    cin >> N;
    cin >> firstWord;
    for (char c : firstWord)
    {
        firstChars[c - 'A']++;
    }

    string word;
    int count = 0;
    for (int i = 1; i < N; ++i)
    {
        cin >> word;
        
        count += IsSimilar(word);
    }
    cout << count;

    return 0;
}