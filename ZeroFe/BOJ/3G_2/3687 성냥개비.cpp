#include <iostream>
#include <algorithm>

using namespace std;

void MakeShortest(int count, string& str)
{
	if (count <= 7)
	{
        // 공백이 들어가는 케이스는 에러케이스
        static const char nums[] = {' ', ' ', '1', '7', '4', '2', '0', '8'};

        // 각 성냥개비 갯수에 따른 최솟값
        // 단, 0은 한 자릿수인 경우 불가능하므로 따로 예외처리한다
        char addedNum = nums[count];
        if (str.empty() && count == 6)
        {
            addedNum = '6';
        }
        str.push_back(addedNum);
	}
    else
    {
        static const char firsts[] = { '8', '1', '1', '2', '2', '2', '6' };
        static const int firstSubs[] = { 7, 2, 2, 5, 5, 5, 6 };
        static const char others[] = { '8', '0', '0', '0', '0', '0', '0' };
        static const int secondSubs[] = { 7, 6, 6, 6, 6, 6, 6 };

        int remainder = count % 7;
        char addedNum;
        if (str.empty())
        {
            addedNum = firsts[remainder];
            count -= firstSubs[remainder];
        }
        else
        {
            addedNum = others[remainder];
            count -= secondSubs[remainder];
        }
        str.push_back(addedNum);

        MakeShortest(count, str);
    }
}

void MakeLongest(int count, string& str)
{
	if (count == 2)
	{
        str.push_back('1');
        return;
	}
    else if (count == 3)
	{
        str.push_back('7');
        return;
	}

    str.push_back('1');
    MakeLongest(count - 2, str);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt)
    {
        int count;
        cin >> count;

        string shortest;
        string longest;
        MakeShortest(count, shortest);
        MakeLongest(count, longest);
        reverse(longest.begin(), longest.end());

        cout << shortest << " " << longest << '\n';
    }

    return 0;
}