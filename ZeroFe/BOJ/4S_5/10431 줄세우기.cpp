#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    int T;
    cin >> T;
    int arr[20] = {};
    for (int tt = 1; tt <= T; ++tt)
    {
        int N;
        cin >> N;

        for (int i = 0; i < 20; ++i)
        {
            cin >> arr[i];
        }

        int count = 0;
        for (int i = 0; i < 20; ++i)
        {
	        for (int j = 0; j < i; ++j)
	        {
		        if (arr[i] < arr[j])
		        {
                    swap(arr[i], arr[j]);
                    count++;
		        }
	        }
        }

        cout << tt << " " << count << '\n';
    }

    return 0;
}