#include <iostream>
#include <queue>

using namespace std;

struct Vec2
{
    int x;
    int y;

    // 외적의 성질을 이용해 시계 방향인지 반시계 방향인지 구함
    // 이번 문제는 2차원 평면 상이므로 zx - xz만 사용한다
    int IsCW(Vec2 right)
    {
        int up = (y * right.x) - (x * right.y);
	    if (up > 0)
	    {
            return -1;
	    }
        else if (up < 0)
	    {
            return 1;
	    }
        else
        {
            return 0;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Vec2 point[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> point[i].x >> point[i].y;
    }

    // 두 선분을 만들기
    Vec2 forward = Vec2{ point[1].x - point[0].x, point[1].y - point[0].y };
    Vec2 right = Vec2{ point[2].x - point[0].x, point[2].y - point[0].y };

    cout << forward.IsCW(right);

    return 0;
}