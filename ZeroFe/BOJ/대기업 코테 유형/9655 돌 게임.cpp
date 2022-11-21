#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 돌을 1개 또는 3개만 가져갈 수 있음 -> 둘 다 홀수 -> 플레이어의 홀 짝이 나뉜다
    // 나머지가 1이면 상근이가, 나머지가 0이면 창영이가 이김
    cout << (N % 2 ? "SK" : "CY");

    return 0;
}