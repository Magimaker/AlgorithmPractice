#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    string nums;
    cin >> nums;
    int sz = nums.size();
    // 각 숫자들의 위치를 저장하는 큐
    queue<int> idxsArr[10];
    for (int i = 0; i < sz; ++i)
    {
        int num = nums[i] - '0';
        idxsArr[num].push(i);
    }

    int p = 0;
    string res;
    while (p < N - 1 && K > 0)
    {
	    for (int i = 9; i >= 0; --i)
	    {
		    while (p < N- 1 && K > 0 && !idxsArr[i].empty() && p + K >= idxsArr[i].front())
		    {
                // 이전까지 쭉 빼기
                int num = nums[p] - '0';
                if (num < i)
                {
                    idxsArr[num].pop();
                    p++;
                    K--;
                }
                else
                {
                    break;
                }
		    }
            // 도착한 경우
		    if (!idxsArr[i].empty() && nums[p] - '0' == i)
		    {
                idxsArr[i].pop();
                res.push_back(nums[p++]);
                break;
		    }
	    }
    }

    // 남아있는 개수만큼 다 넣기
    for (int i = p; i < N; ++i)
    {
        res.push_back(nums[i]);
    }

    // 남아있는 K번만큼 뒤에서 빼주기
    for (int i = 0; i < K; ++i)
    {
        res.pop_back();
    }

    cout << res;

    return 0;
}