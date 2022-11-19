#include <iostream>

using namespace std;

int GetRank(int n, int newScore, int p)
{
	if (n == 0)
	{
        return 1;
	}

    // 태수의 번호는 맨 마지막에 넣는다
    int count = 0;
    int rank = 1;
    for (int i = 0; i < n; ++i)
    {
        int score;
        cin >> score;

        if (newScore > score)
        {
            break;
        }

        if (newScore < score)
        {
            rank++;
        }
        count++;
    }

    if (count == p)
    {
        return -1;
    }

    return rank;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, newScore, p;

    cin >> n >> newScore >> p;

    cout << GetRank(n, newScore, p);

    return 0;
}