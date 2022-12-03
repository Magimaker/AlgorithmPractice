#include <iostream>

using namespace std;

const int MAX_COUNT = 1000001;

int stock[MAX_COUNT];
int maxVals[MAX_COUNT];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int sz;
        cin >> sz;

        for (int i = 0; i < sz; ++i)
        {
            cin >> stock[i];
        }
        // 최대 이득이 되는 때 - n일까지 중 최고 고점까지 주식 다 사서 고점에 다 파는거
        // n일까지 최대 고점 = 역순으로 max값 계산
        int maxVal = 0;
        for (int i = sz - 1; i >= 0; --i)
        {
            maxVal = max(maxVal, stock[i]);
            maxVals[i] = maxVal;
        }

        // 주식 개수
        int cnt = 0;
        long long total = 0;
        for (int i = 0; i < sz - 1; ++i)
        {
            // 고점까지 사고 존-버
	        if (maxVals[i] <= maxVals[i + 1])
	        {
                total -= stock[i];
                cnt++;
	        }
            // 가격이 떨어질 땐 팖
            else
            {
	            total += static_cast<long long>(stock[i]) * cnt;
                cnt = 0;
            }
        }
        // 마지막 날엔 무조건 팔아야 한다
        total += static_cast<long long>(stock[sz - 1]) * cnt;

        cout << total << '\n';
    }
    
    return 0;
}