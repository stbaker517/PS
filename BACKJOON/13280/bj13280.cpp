#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> V;

    int N;
    while (1)
    {
        V.clear();

        cin >> N;
        if (!N)
            return 0;

        int input;
        for (int i = 0; i < N; i++)
        {
            cin >> input;
            V.push_back(input);
        }

        sort(V.rbegin(), V.rend());

        int Min = 0x7fffffff;
        for (int i = 0; i < V.size() - 1; i++)
        {
            Min = min(Min,abs(V[i] - V[i + 1]));
        }

        cout << Min << "\n";
    }
}