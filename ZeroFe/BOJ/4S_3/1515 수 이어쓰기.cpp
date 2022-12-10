#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string nums;
    cin >> nums;
    int sz = nums.size();
    int p = 0;
    int num = 0;
    for (num = 1; p < sz; ++num)
    {
        string tmp = to_string(num);
        for (int i = 0; i < tmp.size() && p < sz; ++i)
        {
            if (tmp[i] == nums[p])
            {
                p++;
            }
        }
    }

    cout << num - 1;
}