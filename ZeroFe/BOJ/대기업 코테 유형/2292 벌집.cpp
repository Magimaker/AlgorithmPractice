#include <iostream>
#include <ctgmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "1";
        return 0;
    }

    const long double epsilon = 0.0000000001;

    long double sum = 4 * static_cast<long double>(n) - 1;

    long double root = sqrtl(sum / 12);

    // k가 해당 값보단 작아야하므로 보정해준다
    long double k = 0.5 + root - epsilon;

    // 초기 1에서 한 칸 먹으니까 보정
    int ans = 1 + static_cast<int>(k);

    cout << ans;

    return 0;
}