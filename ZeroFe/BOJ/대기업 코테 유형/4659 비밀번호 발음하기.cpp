#include <iostream>
#include <ctgmath>

using namespace std;

bool IsVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool IsAcceptable(string& password)
{
    bool hasVowel = false;
    int seqVowelCount = 0;
    int seqConsCount = 0;
    char prev = '\0';   // 초기값은 절대 들어갈 수 없는거로

    for (char c : password)
    {
        // 모음
	    if (IsVowel(c))
	    {
            hasVowel = true;
            seqVowelCount++;
            seqConsCount = 0;
	    }
        // 자음
        else
        {
            seqVowelCount = 0;
            seqConsCount++;
        }

        // 자음 모음 3번 연속 방지
        if (seqVowelCount >= 3 || seqConsCount >= 3)
        {
            return false;
        }

        // 같은 글자 연속 방지
        if (prev == c && c != 'e' && c != 'o')
        {
            return false;
        }
        prev = c;
    }

    if (!hasVowel)
    {
        return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string password;
    while (true)
    {
        cin >> password;
        if (password == "end") break;
        string result = IsAcceptable(password) ? "acceptable" : "not acceptable";
        cout << "<" << password << "> is " << result << ".\n";
    }

    return 0;
}