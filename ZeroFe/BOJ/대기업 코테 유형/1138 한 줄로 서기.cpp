#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int personCount;
    cin >> personCount;

    int num;
    vector<int> persons = vector<int>(personCount);
    for (int p = 1; p <= personCount; p++)
    {
        cin >> num;
        int idx = 0;
        for (idx = 0; idx < personCount; ++idx)
        {
            if (persons[idx] == 0)
            {
                if (num == 0)
                {
                    break;
                }
                else
                {
                    num--;
                }
            }
        }

        persons[idx] = p;
    }

    // 출력
    cout << persons[0];
    for (int i = 1; i < personCount; i++)
    {
        cout << " " << persons[i];
    }

    return 0;
}