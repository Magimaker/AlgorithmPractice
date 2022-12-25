#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100000;

// 0 ~ 100001에 해당하는 범위
// 이 중 1 ~ 10000에 해당하는 범위를 사용한다
bool states[MAX_SIZE + 2];

inline void Change(int pos)
{
    states[pos - 1] = !states[pos - 1];
    states[pos] = !states[pos];
    states[pos + 1] = !states[pos + 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string before, after;
    cin >> before >> after;

    int count1 = 0, count2 = 0;
    for (int i = 1; i <= N; ++i)
    {
        states[i] = before[i - 1] - '0';
    }

    // 1번 스위치를 누른 경우
    Change(1);
    count1++;
    // 이후 N번 스위치를 누르면 N-1번 전구의 상태가 결정난다
    for (int i = 2; i <= N; ++i)
    {
	    if (states[i - 1] != after[i - 2] - '0')
	    {
            Change(i);
            count1++;
	    }
    }
    // 끝까지 눌렀는데 안 맞는 부분이 있으면 invalid하다
    if (states[N] != after[N-1] - '0')
    {
        count1 = MAX_SIZE;
    }

    // 1번 스위치를 누르지 않은 경우
    for (int i = 1; i <= N; ++i)
    {
        states[i] = before[i - 1] - '0';
    }

    for (int i = 2; i <= N; ++i)
    {
        if (states[i - 1] != after[i - 2] - '0')
        {
            Change(i);
            count2++;
        }
    }
    if (states[N] != after[N - 1] - '0')
    {
        count2 = MAX_SIZE;
    }

    if (count1 != MAX_SIZE || count2 != MAX_SIZE)
    {
        cout << min(count1, count2);
    }
    else
    {
        cout << -1;
    }

    return 0;
}