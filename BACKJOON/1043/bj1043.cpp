#include <bits/stdc++.h>

using namespace std;

int know[50];
int visited[50];
int Tparty[50];
int party[50][50]; //p[파티번호][참석자] 참석 여부용
vector<int> Pvec[50];
int n, m, t;

void ff(int v)
{
    //cout << "FF: " << v << "\n";
    know[v] = 1;
    for (int i = 0; i < m; i++)
    {
        if (party[i][v])
        { //i번째 파티
            Tparty[i] = 1;
            for (int next : Pvec[i])
            {
                if (visited[next])
                    continue;
                visited[next] = 1;
                ff(next);
            }
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    int input;
    for (int i = 0; i < t; i++)
    {
        cin >> input;
        know[input - 1] = 1;
    }
    int num;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> input;
            input -= 1;
            party[i][input] = 1;
            Pvec[i].push_back(input);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (know[i] && visited[i] == 0)
        {
            visited[i] = 1;
            ff(i);
        }
        //ff(i);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (Tparty[i] == 0)
            cnt++;
    }
    cout << cnt;
    return 0;
}