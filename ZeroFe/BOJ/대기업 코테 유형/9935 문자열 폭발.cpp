#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

int bSz;

bool CanBoom(string& ans, string& boom)
{
    // 길이가 안 되는 경우 터뜨릴 수 없다
    if (ans.size() < bSz)
	{
        return false;
	}

    int start = ans.size() - bSz;
    for (int i = 0; i < boom.size(); ++i)
    {
	    if (ans[start + i] != boom[i])
	    {
            return false;
	    }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str, boom;
    cin >> str >> boom;

    // 호출 많이 되는 고정값이므로 캐싱
    bSz = boom.size();

    string ans = "";
    for (int p = 0; p < str.size(); p++)
    {
        // 문장 넣기
        ans.push_back(str[p]);

        if (CanBoom(ans, boom))
        {
            // 다 터뜨리기
	        for (int i = 0; i < bSz; i++)
	        {
                ans.pop_back();
	        }
        }
    }


    if (ans.empty())
    {
        ans = "FRULA";
    }
    cout << ans;

    return 0;
}