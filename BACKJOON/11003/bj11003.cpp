#include <iostream>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

#define pii pair<int, int>
struct cmp
{
    bool operator()(pii &a, pii &b)
    {
        if (a.first > b.first)
            return true;
        if (a.first == b.first)
        {
            if (a.second < b.second)
                return true;
        }
        return false;
    }
};
int arr[5000000];
int mmin[5000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<pii, vector<pii>, cmp> PQ;
    deque<pii> DQ;
    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        DQ.push_back({arr[i], i});
        PQ.push({arr[i], i});
        if (DQ.size() > l)
        {
            pii frt = DQ.front();
            DQ.pop_front();
            while (PQ.top().second <= frt.second)
            {
                PQ.pop();
            }
        }
        mmin[i] = PQ.top().first;
    }
    for (int i = 0; i < n; i++)
    {
        cout << mmin[i] << " ";
    }
    return 0;
}