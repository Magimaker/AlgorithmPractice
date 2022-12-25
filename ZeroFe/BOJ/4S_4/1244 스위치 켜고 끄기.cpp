#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int N;
    cin >> N;

    vector<bool> switches(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        int num;
        cin >> num;
        switches[i] = num;
    }

    int K;
    cin >> K;



	for (int n = 0; n < K; ++n)
    {
        // 성별, 스위치 번호
        int s, num;
        cin >> s >> num;
        // 남학생
        if (s == 1)
        {
            for (int i = 1; i <= N; i++)
            {
                if (i % num == 0)  //배수일 때
                    switches[i] = !switches[i];  //스위치의 상태를 바꾼다.
            }
        }
        else
        {
            switches[num] = !switches[num];
            for (int i = 1; switches[num + i] == switches[num - i]; i++)
            {
                if (num + i > N || num - i < 1) break;
                switches[num + i] = !switches[num + i];
                switches[num - i] = !switches[num - i];
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << (switches[i] ? 1 : 0) << " ";
        if (i % 20 == 0)
        {
            cout << '\n';
        }
    }

    return 0;
}