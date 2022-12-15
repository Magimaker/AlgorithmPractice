#include <iostream>

using namespace std;

const int MAX_SIZE = 20;

char map[MAX_SIZE][MAX_SIZE];
bool visited[26];

int R, C;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int Travel(int y, int x, int depth)
{
    int maxLength = depth;
    for (int d = 0; d < 4; ++d)
    {
        int newY = y + dy[d];
        int newX = x + dx[d];

        if (newY < 0 || newY >= R || newX < 0 || newX >= C || map[newY][newX] == '.' || visited[map[newY][newX] - 'A'])
        {
            continue;
        }

        char backup = map[newY][newX];
        map[newY][newX] = '.';
        visited[backup - 'A'] = true;
        maxLength = max(maxLength, Travel(newY, newX, depth + 1));
        map[newY][newX] = backup;
        visited[backup - 'A'] = false;
    }

    return maxLength;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);

    cin >> R >> C;

    string line;
    for (int y = 0; y < R; ++y)
    {
        cin >> line;
        for (int x = 0; x < C; ++x)
        {
            map[y][x] = line[x];
        }
    }

    visited[map[0][0] - 'A'] = true;
    map[0][0] = '.';
    cout << Travel(0, 0, 1);
    
    return 0;
}