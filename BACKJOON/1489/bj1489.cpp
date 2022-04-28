#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
int A[51];
int B[51];
vector<int> mem[51][101]; //승,무,남아있는 놈들.

void copyFromAtoB(vector<int> &a, vector<int> &b);
int isLbetter(vector<int> &a, vector<int> &b);
bool vvisit[51][101];

int main()
{

    cin >> n;
    int MS = 2 * n;
    for (int i = 0; i <= 50; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            mem[i][j].clear();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> B[i];

    sort(A + 1, A + n + 1); //오름차순
    sort(B + 1, B + n + 1);
    for (int i = 1; i <= n; i++)
    {
        // cout << i;
        mem[0][0].push_back(A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        // cout << "ITER: [" << i << "] ";
        for (int score = 0; score <= MS; score++)
        {
            if (mem[i][score].empty())
                continue;

            int X = B[i + 1];
            int lb = lower_bound(mem[i][score].begin(), mem[i][score].end(), X) - mem[i][score].begin();
            // cout << lb << " " << score << " ";
            if (lb < mem[i][score].size())
            {
                //이기는 경우 -> 가장 근접한 놈으로 이겨야함.
                int tb = lb;
                if (mem[i][score][tb] == X)
                    tb++;
                if (tb < mem[i][score].size())
                {
                    if (mem[i + 1][score + 2].empty())
                    {
                        vvisit[i + 1][score + 2] = 1;
                        copyFromAtoB(mem[i][score], mem[i + 1][score + 2]);
                        // cout << "test" << mem[i + 1][score + 2][0];
                        mem[i + 1][score + 2].erase(mem[i + 1][score + 2].begin() + tb);
                    }
                    else
                    {
                        vector<int> tmp;
                        copyFromAtoB(mem[i][score], tmp);
                        tmp.erase(tmp.begin() + tb);
                        if (isLbetter(tmp, mem[i + 1][score + 2]))
                        {
                            mem[i + 1][score + 2].clear();
                            copyFromAtoB(tmp, mem[i + 1][score + 2]);
                        }
                    }
                    // cout << "win";
                }

                //비기는 경우 -> 똑같은 놈으로 비기기.
                if (mem[i][score][lb] == X)
                {
                    if (mem[i + 1][score + 1].empty())
                    {
                        vvisit[i + 1][score + 1] = 1;
                        copyFromAtoB(mem[i][score], mem[i + 1][score + 1]);
                        mem[i + 1][score + 1].erase(mem[i + 1][score + 1].begin() + lb);
                    }
                    else
                    {
                        vector<int> tmp;
                        copyFromAtoB(mem[i][score], tmp);
                        tmp.erase(tmp.begin() + lb);
                        if (isLbetter(tmp, mem[i + 1][score + 1]))
                        {
                            mem[i + 1][score + 2].clear();
                            copyFromAtoB(tmp, mem[i + 1][score + 1]);
                        }
                    }
                    // cout << "draw";
                }
            }

            //지는 경우 -> 가장 약한 놈을 제물로.
            if (lb > 0)
            {

                if (mem[i + 1][score].empty())
                {
                    vvisit[i + 1][score] = 1;
                    copyFromAtoB(mem[i][score], mem[i + 1][score]);
                    mem[i + 1][score].erase(mem[i + 1][score].begin());
                }
                else
                {
                    vector<int> tmp;
                    copyFromAtoB(mem[i][score], tmp);
                    tmp.erase(tmp.begin());
                    if (isLbetter(tmp, mem[i + 1][score]))
                    {
                        mem[i + 1][score].clear();
                        copyFromAtoB(tmp, mem[i + 1][score]);
                    }
                }
                // cout << "lose";
            }
            // cout << '\n';
        }
    }
    int mm = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (vvisit[n][i])
            mm = i;
    }
    cout << mm;
}

void copyFromAtoB(vector<int> &a, vector<int> &b)
{
    b.resize(a.size());
    copy(a.begin(), a.end(), b.begin());
    return;
}
int isLbetter(vector<int> &a, vector<int> &b)
{
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            break;
    }
    return 0;
}