#include <iostream>
#include <vector>

using namespace std;
#define pii pair<int, int>

pii Tree[10001];
bool isChild[10001];
int L[10001];
int R[10001];
int n;
void f(int par, int h, int &num)
{
    int l = Tree[par].first;
    int r = Tree[par].second;
    if (l != -1)
        f(l, h + 1, num);
    num++;
    if (!L[h])
        L[h] = num;
    R[h] = num;

    if (r != -1)
        f(r, h + 1, num);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int u, l, r;
        cin >> u >> l >> r;
        if (l != -1)
            isChild[l] = 1;
        if (r != -1)
            isChild[r] = 1;
        Tree[u] = {l, r};
    }
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (!isChild[i])
            root = i;
    }
    int num = 0;
    // cout << "root:" << root << "\n";
    f(root, 0, num);
    int lv = 0;
    int len = 0;
    for (int i = 0; i <= 10000; i++)
    {
        if (R[i] - L[i] + 1 > len)
        {
            lv = i;
            len = R[i] - L[i] + 1;
        }
    }
    cout << lv + 1 << " " << len;
    return 0;
}
