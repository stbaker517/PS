#include <iostream>

using namespace std;

int row[9][9];
int col[9][9];
int area[9][9];
int sdoku[9][9];

int ok = 1;
void print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sdoku[i][j] << " ";
        }
        cout << "\n";
    }
}
void func(int n)
{
    if (n == 81 && ok)
    {
        //cout << "\n\nANS\n";
        print();
        ok = 0;
        return;
    }

    if (ok)
    {
        //cout<<n<<" ";
        int x = n / 9;
        int y = n % 9;
        if (sdoku[x][y])
            func(n + 1);
        else
        {
            for (int i = 0; i < 9; i++)
            {
                if (row[x][i] || col[y][i] || area[x / 3 * 3 + y / 3][i])
                {
                    continue;
                }
                else
                {

                    sdoku[x][y] = i + 1;
                    row[x][i] = 1;
                    col[y][i] = 1;
                    area[x / 3 * 3 + y / 3][i] = 1;

                    func(n + 1);

                    row[x][i] = 0;
                    col[y][i] = 0;
                    area[x / 3 * 3 + y / 3][i] = 0;
                    sdoku[x][y] = 0;
                }
            }
        }
    }
    else
        return;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%1d", &sdoku[i][j]);
            if (sdoku[i][j])
            {
                row[i][sdoku[i][j] - 1] = 1;
                col[j][sdoku[i][j] - 1] = 1;
                area[i / 3 * 3 + j / 3][sdoku[i][j] - 1] = 1;
            }
        }
    }
    func(0);

    return 0;
}