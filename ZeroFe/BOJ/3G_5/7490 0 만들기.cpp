#include <iostream>

using namespace std;

const char op[] = { ' ', '+', '-'};

void Travel(string& expression, int target, int curr, int sum, int remain)
{
    if (target == curr)
    {
	    if (sum + remain == 0)
	    {
            cout << expression << '\n';
	    }

        return;
    }

	for (int d = 0; d < 3; ++d)
	{
        int prevSum = sum;
        int prevRemain = remain;
        int next = curr + 1;
		if (d == 0)
		{
            remain *= 10;
            remain += remain > 0 ? next : -next;
		}
        else if (d == 1)
		{
            sum += remain;
            remain = next;
		}
        else if (d == 2)
		{
            sum += remain;
            remain = -next;
		}

        expression.push_back(op[d]);
        expression.push_back(next + '0');
        Travel(expression, target, next, sum, remain);
        expression.pop_back();
        expression.pop_back();
        sum = prevSum;
        remain = prevRemain;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt)
    {
        int N;
        cin >> N;
        string expression = "1";
        Travel(expression, N, 1, 0, 1);
        cout << '\n';
    }

    return 0;
}