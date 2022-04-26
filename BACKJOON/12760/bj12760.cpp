#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
int point[100];
vector<pii> arr[100];
vector<int> card[100];
int n, m;
int main()
{
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            card[i].push_back(tmp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        sort(card[i].begin(), card[i].end());
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            arr[j].push_back({card[i][j], i});
        }
        sort(arr[j].begin(), arr[j].end());

        for (int k = n - 1; k >= 0; k--)
        {
            if (arr[j][k].first == arr[j][n - 1].first)
            {
                point[arr[j][k].second]++;
            }
        }
    }
    int M = 0;
    for (int i = 0; i < n; i++)
    {
        M = max(point[i], M);
    }
    for (int i = 0; i < n; i++)
    {
        if (M == point[i])
        {
            cout << i + 1 << " ";
        }
    }

    return 0;
}