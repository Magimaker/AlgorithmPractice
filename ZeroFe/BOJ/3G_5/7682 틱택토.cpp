#include <iostream>

using namespace std;

// 보드 판에 빙고가 있는지 계산
// 몇 개의 수직, 수평이 있는지 저장
bool HasBingo(char board[][3], char playerChar)
{
    // 수평
	for (int y = 0; y < 3; ++y)
	{
        if (board[y][0] == playerChar && board[y][0] == board[y][1] && board[y][1] == board[y][2])
        {
            return true;
        }
	}

    // 수평
    for (int x = 0; x < 3; ++x)
    {
	    if (board[0][x] == playerChar && board[0][x] == board[1][x] && board[1][x] == board[2][x])
	    {
            return true;
	    }
    }

    // 대각선
    if ((board[0][0] == playerChar && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == playerChar && board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
        return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char board[3][3];

    string input;
    while (true)
    {
        cin >> input;
        if (input == "end")
        {
            break;
        }

        int oCount = 0;
        int xCount = 0;
	    for (int y = 0; y < 3; ++y)
	    {
		    for (int x = 0; x < 3; ++x)
		    {
                board[y][x] = input[y * 3 + x];
                if (board[y][x] == 'X')
                {
                    xCount++;
                }
                else if (board[y][x] == 'O')
                {
                    oCount++;
                }
		    }
	    }

        // O가 X보다 많은 경우는 Invalid하다
        if (oCount > xCount)
        {
            cout << "invalid" << '\n';
            continue;
        }

    	bool hasBingo1 = HasBingo(board, 'X');
    	bool hasBingo2 = HasBingo(board, 'O');
        
        // 이긴 경우
        if (hasBingo1 && !hasBingo2)
        {
	        // 무조건 xCount가 하나 더 많아야 한다
	        if (xCount == oCount + 1)
	        {
                cout << "valid" << '\n';
                continue;
	        }
        }
        // 진 경우
        else if (!hasBingo1 && hasBingo2)
        {
            // xCount와 oCount는 같아야 한다
	        if (xCount == oCount)
	        {
                cout << "valid" << '\n';
                continue;
	        }
        }
        // 비긴 경우
        else if (!hasBingo1 && !hasBingo2)
        {
	        // 꽉 찬 경우 아니면 Invalid
	        if (xCount == 5 && oCount == 4)
	        {
                cout << "valid" << '\n';
                continue;
	        }
        }

        // 나머지는 Invalid
        cout << "invalid" << '\n';
    }

    return 0;
}