#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int rowNum, colNum, divRow, divCol;
    cin >> rowNum >> colNum >> divRow >> divCol;

    // 간격 + 사람 자리 칸 수
	divRow++;
    divCol++;

    // 간격을 div로 나눌 때 몫과 나머지
    int rowQuot, colQuot, rowRem, colRem;
    rowQuot = rowNum / divRow;
    colQuot = colNum / divCol;
    rowRem = rowNum % divRow;
    colRem = colNum % divCol;

    int resRow = rowQuot + (rowRem != 0 ? 1 : 0);
    int resCol = colQuot + (colRem != 0 ? 1 : 0);

    cout << resRow * resCol;

    return 0;
}