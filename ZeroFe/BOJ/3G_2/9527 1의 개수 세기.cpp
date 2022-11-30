#include <iostream>

using namespace std;

using ll = long long;

ll d[55];

ll GetTotal(ll target)
{
    ll ans = target & 1;
    for (ll i = 54; i > 0; i--)
    {
	    if (target & (1LL << i))
	    {
            // 1ULL << 1 이하 부분들은 d[i - 1]
            // 1ULL << 1 이상의 부분들은 1씩 더해준다
            ans += d[i - 1] + (target - (1LL << i) + 1);
            target -= 1LL << i;
	    }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    d[0] = 1;
    for (ll i = 1; i < 55; ++i)
    {
        d[i] = d[i - 1] * 2 + (1ULL << i);
    }

    ll a, b;
    cin >> a >> b;

    // b가 2의 몇 승보다 작은지 구한다
    cout << GetTotal(b) - GetTotal(a-1);

    return 0;
}