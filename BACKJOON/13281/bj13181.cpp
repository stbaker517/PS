#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int vote[26];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int N;
    char c;
    while (1)
    {
        cin >> n;

        if (!n)
            return 0;
        N = n;
        int flag = 0;
        memset(vote, 0, sizeof(vote));

        int first = -1, second = -1;
        while (n--)
        {
            cin >> c;
            //cout << c << "|";
            vote[c - 'A']++;

            if (first == -1)
            {
                first = c - 'A';
            }
            else
            {

                if (vote[c - 'A'] > vote[first])
                {
                    second = first;
                    first = c - 'A';
                }
                if (c - 'A' != first)
                {
                    if (second == -1)
                    {
                        second = c - 'A';
                    }
                    else if (vote[c - 'A'] > vote[second])
                    {
                        second = c - 'A';
                    }
                }
            }

            //cout << "F: " << first << " S: " << second << "\n";

            if (flag == 0 && vote[first] - vote[second] > n)
            {
                flag = 1;
                cout << (char)(first + 'A') << " " << N - n << "\n";
                continue;
            }
        }

        if (flag == 0)
            cout << "TIE"
                 << "\n";
    }

    return 0;
}