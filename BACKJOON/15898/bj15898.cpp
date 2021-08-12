#include <iostream>

using namespace std;

int n;
int mmax = 0;
int aval[10];
int comb[3];
int srcI[10][4][4][4];
char srcCH[10][4][4][4];

void rotate(int src[10][4][4][4], int idx)
{

    for (int a = 0; a < 3; a++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                src[idx][a + 1][j][3 - i] = src[idx][a][i][j];
            }
        }
    }
}

void count(int q,int w,int e)
{
    int m1,m2,m3;
    m1=com[0];m2=comb[1];m3=comb[2];
    x1=q/2;y1=q%2;
    x2=q/2;y2=q%2;
    x3=q/2;y3=q%2;
    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            for (int c = 0; c < 4; c++)
            {
                

            }
        }
    }
}

void ff(int k, int idx)
{
    if (k == 3)
    {
        //계산하고 최대값 갱신.
        int cnt = 0;
        for (int a = 0; a < 4; a++)
        {
            for (int b = 0; b < 4; b++)
            {
                for (int c = 0; c < 4; c++)
                {
                }
            }
        }

        if (mmax < cnt)
            mmax = cnt;

        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (aval[i])
            continue;

        aval[i] = 1;
        com[k] = i;
        ff(k + 1, i + 1);
        aval[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a < 4; a++)
        {
            for (int b = 0; b < 4; b++)
            {
                cin >> srcI[i][0][a][b];
            }
        }
        rotate(srcI, i);
        for (int a = 0; a < 4; a++)
        {
            for (int b = 0; b < 4; b++)
            {
                cin >> srcCH[i][0][a][b];
            }
        }
        rotate(srcCH, i);
    }
}