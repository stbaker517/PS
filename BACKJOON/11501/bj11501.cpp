#include <iostream>

using namespace std;
int p[1000000];
int n;
int q;
long long tot;
int main()
{
    cin >> q;
    for (int aa = 0; aa < q; aa++)
    {
        tot = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        int m = p[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (p[i] < m)
            {
                tot += (m - p[i]);
            }
            else if (p[i] > m)
            {
                m = p[i];
            }
        }
        cout << tot << "\n";
    }

    return 0;
}