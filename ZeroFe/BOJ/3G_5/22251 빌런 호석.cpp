#include <iostream>

using namespace std;

bool numLEDs[10][7] = { {true,true,true,false,true,true,true}, // 0
                   {false,false,true,false,false,false,true}, // 1
                   {false,true,true,true,true,true,false}, // 2
                   {false,true,true,true,false,true,true}, // 3
                   {true,false,true,true,false,false,true}, // 4
                   {true,true,false,true,false,true,true}, // 5
                   {true,true,false,true,true,true,true}, // 6
                   {false,true,true,false,false,false,true}, // 7
                   {true,true,true,true,true,true,true}, // 8
                   {true,true,true,true,false,true,true} // 9
};

int Change(int N, int K, int P, int X)
{
    int count = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (i == X)
		{
            continue;
		}

        // 스위치 바꾼 개수
        int changes = 0;
        // 스위치 바꿀 대상
        int from = X;
        int to = i;

        for (int j = 0; j < K; ++j)
        {
            int numFrom = from % 10;
            int numTo = to % 10;
            // 각 스위치 차이만큼 변경하기
            for (int k = 0; k < 7; ++k)
            {
	            if (numLEDs[numFrom][k] != numLEDs[numTo][k])
	            {
                    changes++;
	            }
            }
            from /= 10;
            to /= 10;
        }

        if (changes <= P)
        {
            count++;
        }
	}

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, P, X;
    cin >> N >> K >> P >> X;

	// 초기 시작점 제외
    cout << Change(N, K, P, X);

    return 0;
}