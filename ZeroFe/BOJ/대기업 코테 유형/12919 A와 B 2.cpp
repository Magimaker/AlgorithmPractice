#include <assert.h>
#include <iostream>

using namespace std;

string s, t;
int aTarget, bTarget;

bool IsSame(int front, int back, bool reverse)
{
    assert(back - front + 1 == s.size());

    int sign = reverse ? -1 : 1;
    int start = reverse ? back : front;
    int j = start;
    for (int i = 0; i < s.size(); i++, j += sign)
    {
	    if (s[i] != t[j])
	    {
            return false;
	    }
    }

    return true;
}

// 문자를 하나씩 줄여나가며 변환한다
int Transform(int aCount, int bCount, int front, int back, bool reverse)
{
    // 선결조건 : aCount와 bCount가 target보다 작다면 변환할 수 없다
    if (aCount < aTarget || bCount < bTarget)
    {
        return 0;
    }
    // A랑 B 개수 같다면 진짜 되는지 확인하기
    if (aCount == aTarget && bCount == bTarget)
    {
        return IsSame(front, back, reverse);
    }

    // reverse에 따라 뒤집어서 계산해야할지 확인
    int sign = reverse ? -1 : 1;
    int start = reverse ? back : front;
    int end = reverse ? front : back;

    // 앞으로 뺄 수 있나?(앞에 B가 있는 경우)
    if (t[start] == 'B')
    {
        int tmpStart = start + sign;
        int tmpEnd = end;
        if (tmpStart > tmpEnd) swap(tmpStart, tmpEnd);
        if (Transform(aCount, bCount - 1, tmpStart, tmpEnd, !reverse))
        {
            return 1;
        }
    }
    // 뒤로 뺄 수 있나?
    if (t[end] == 'A')
    {
        int tmpStart = start;
        int tmpEnd = end - sign;
        if (tmpStart > tmpEnd) swap(tmpStart, tmpEnd);
        if (Transform(aCount - 1, bCount, tmpStart, tmpEnd, reverse))
        {
            return 1;
        }
    }
    // 둘 다 안 되나보다
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> t;
    
    for (char c : s)
    {
	    if (c == 'A')
	    {
            aTarget++;
	    }
        else
        {
            bTarget++;
        }
    }
    int aCount = 0;
	int bCount = 0;
    for (char c : t)
    {
        if (c == 'A')
        {
            aCount++;
        }
        else
        {
            bCount++;
        }
    }

    cout << Transform(aCount, bCount, 0, t.size() - 1, false);
    
    return 0;
}