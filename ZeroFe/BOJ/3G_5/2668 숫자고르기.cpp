#include <iostream>
#include <cstring>

using namespace std;

int N;
int nums[101];
bool visited[101];

int result[101];
int resultIdx = 0;

void DFS(int current, int start)
{
	if (visited[current])
	{
        if (current == start)
            result[resultIdx++] = start;
	}
    else
    {
        visited[current] = true;
        DFS(nums[current], start);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> nums[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        memset(visited, false, sizeof(visited));
        DFS(i, i);
    }

    cout << resultIdx << '\n';
    for (int i = 0; i < resultIdx; ++i)
    {
        cout << result[i] << '\n';
    }
    
    return 0;
}