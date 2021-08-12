#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1;
    string command;
    int num;
    while (1)
    {
        cin >> n;
        if (!n)
            break;

        int p1 = 0, p2 = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> command >> num;
            if (command.compare("DROP") == 0)
            {
                p2 += num;

                cout << "DROP 2 " << num << "\n";
            }
            else
            {
                if (p1 < num)
                {
                    int nw;
                    nw=num-p1;

                    cout << "MOVE 2->1 " << nw << "\n";
                    p1+=nw;
                    p2+=num-nw;
                }
                p1 -= num;
                cout << "TAKE 1 " << num << "\n";
            }
        }

        cout << "\n";
    }
}