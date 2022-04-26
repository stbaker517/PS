#include <bits/stdc++.h>
using namespace std;

int arr[2200][2200];
int N;
void f(int x, int y, int n)
{

    if (n == 1)
    {
        arr[x][y] = 1;
        return;
    }
    //짝수일 때 위로 팁 홀수일 때 아래 팁.
    //x,y는 중앙 위치.
    int h = (1 << n - 1) - 1;
    //cout << n << ": " << h << "\n";
    if (n % 2 != 0) //홀수
    {
        //위로 좁아짐.
        for (int i = 0; i <= h; i++)
        {
            arr[x - i][y + h - i] = 1;
            arr[x - i][y - h + i] = 1;
        }
        //아래로 넓어짐.
        for (int i = 1; i <= h; i++)
        {
            arr[x + i][y + h + i] = 1;
            arr[x + i][y - h - i] = 1;
        }
        for (int i = 0; i <= 2 * h; i++)
        {
            arr[x + h][y + i] = 1;
            arr[x + h][y - i] = 1;
        }
        if (n == 2)
        {
            f(x, y, n - 1);
        }
        else
            f(x + h / 2, y, n - 1);
    }
    else //짝수
    {
        //아래로 좁아짐.
        for (int i = 0; i <= h; i++)
        {
            arr[x + i][y + h - i] = 1;
            arr[x + i][y - h + i] = 1;
        }
        //위로 넓어짐.
        for (int i = 1; i <= h; i++)
        {
            arr[x - i][y + h + i] = 1;
            arr[x - i][y - h - i] = 1;
        }
        for (int i = 0; i <= 2 * h; i++)
        {
            arr[x - h][y + i] = 1;
            arr[x - h][y - i] = 1;
        }
        if (n == 2)
        {
            f(x, y, n - 1);
        }
        else
            f(x - h / 2, y, n - 1);
    }
}
int main()
{
    cin >> N;
    int h = (1 << N - 1) - 1;
    f(h, h * 2, N);
    for (int i = 2 * h; i >= 0; i--)
    {
        for (int j = 4 * h + 1; j > 0; j--)
        {
            if (arr[i][j - 1] == 1)
            {
                arr[i][j] = -1;
                break;
            }
        }
    }
    for (int i = 0; i < 2 * h + 1; i++)
    {
        for (int j = 0; j < 4 * h + 1; j++)
        {
            if (arr[i][j] == 1)
                cout << "*";
            else if (arr[i][j] == -1)
                break;
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}