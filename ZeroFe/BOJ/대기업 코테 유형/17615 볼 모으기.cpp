#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // 0 : 빨간 공 개수, 1 : 파란 공 개수
    int ball[2] = {};
    char prev;
    cin >> prev;
    auto getNum = [](char c) { return c == 'R' ? 0 : 1; };

    // 시작할 때 연속되는 개수 구하기
    int startColor = getNum(prev);
    ball[getNum(prev)]++;
    int startSeq = 1;   // 공이 연속되는 경우
    for (int i = 1; i < n; ++i)
    {
        char curr;
        cin >> curr;
        ball[getNum(curr)]++;

        if (prev != curr)
        {
            prev = curr;
            break;
        }
        else
        {
            prev = curr;
            startSeq++;
        }
    }

    // 끝까지 돌리고 마지막 연속 구하기
    int endColor = getNum(prev);
    int endSeq = 1;
    for (int i = startSeq + 1; i < n; ++i)
    {
        char curr;
        cin >> curr;
        ball[getNum(curr)]++;
        endColor = getNum(curr);
        endSeq++;
        if (prev != curr)
        {
            // 바뀌었으면 연속이 아니게 됨
            endSeq = 1;
        }
        prev = curr;
    }

    int res = min(ball[startColor] - startSeq, ball[endColor] - endSeq);
    // 둘이 색이 같은 경우
    if (startColor == endColor)
    {
        res = min(res, ball[!startColor]);
    }
    cout << res;

    return 0;
}