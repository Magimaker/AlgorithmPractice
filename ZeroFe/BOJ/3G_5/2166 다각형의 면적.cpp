#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Vec2
{
    // int로 하면 오버플로우 날 수 있으므로 long이나 double로 좌표 저장
    double x;
    double y;
};

// 외적을 이용해 삼각형의 넓이를 구한다
long double TriangleSize(Vec2 a, Vec2 b, Vec2 c)
{
    long double size = a.x * b.y + b.x * c.y + c.x * a.y;
    size -= a.y * b.x + b.y * c.x + c.y * a.x;
    return size / 2.0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Vec2> vertices = vector<Vec2>(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vertices[i].x >> vertices[i].y;
    }

    // 신발끈 공식을 이용해 다각형의 넓이를 구함
    long double total = 0.0;
    for (int i = 1; i < n - 1; i++)
    {
        total += TriangleSize(vertices[0], vertices[i], vertices[i + 1]);
    }
    total = abs(total);
    cout.precision(1);
    cout << fixed << total;

    return 0;
}