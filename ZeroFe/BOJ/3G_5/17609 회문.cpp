#include <iostream>

using namespace std;

int IsPalindrom(string& s)
{
	// 먼저 회문인지 검사
    int n = s.size();
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            break;
        }
    }
	if (left >= right)
	{
        return 0;
	}

    // 회문이 아님 - 앞에서 문제일 수도 있고, 뒤에서 문제일 수도 있음
    // 고로 둘 다 시도해봐야 한다
    left = 0, right = n - 1;
    bool ok = true;
    // 뒤에서 문제인 경우
	while (left < right)
	{
		if (s[left] == s[right])
		{
            left++;
            right--;
		}
        else
        {
            if (ok)
            {
                right--;
                ok = false;
            }
            else
            {
                break;
            }
        }
	}
	if (left >= right)
	{
        return 1;
	}

    // 앞에서 문제인 경우
    left = 0, right = n - 1;
    ok = true;
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            if (ok)
            {
                left++;
                ok = false;
            }
            else
            {
                break;
            }
        }
    }
    if (left >= right)
    {
        return 1;
    }

    // 둘 다 아니다 - 회문 아님
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    string line;
    for (int t = 0; t < T; ++t)
    {
        cin >> line;
        cout << IsPalindrom(line) << '\n';
    }
    
    return 0;
}