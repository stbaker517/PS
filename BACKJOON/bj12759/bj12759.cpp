#include <iostream>
#include <cstring>
using namespace std;

int board[3][3];

bool isWin(int p, int x, int y)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return true;
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return true;

    return false;
}
int flag = 0;
int main()
{
    memset(board, -1, sizeof(int) * 9);
    int P = 0;
    int p;
    cin >> p;
    p -= 1;
    int x, y;
    for (int i = 0; i < 9; i++)
    {

        cin >> x >> y;
        board[x - 1][y - 1] = p;
        if (!flag && isWin(p, x - 1, y - 1))
        {
            P = p + 1;
            flag = 1;
        }
        p = (p + 1) % 2;
    }

    cout << P;
    return 0;
}