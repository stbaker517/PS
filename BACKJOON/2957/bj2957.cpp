#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;
#define pii pair<int, int>
#define ll long long

pii tree[300'001];
int child[300'001];
int Parent[300'001];
int arr[300'001];
ll C[300'001];
set<int> parr;
set<int> narr;
ll cnt[300'001];
vector<int> leaf;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int root = 0;
    ll c = 0;

    for (int i = 0; i < n; i++)
    {

        int tmp;
        cin >> tmp;
        if (!root)
        {
            root = tmp;
            parr.insert(root);
            narr.insert(-root);
        }
        arr[i] = tmp;
        // printf("dd\n");
    }

    cnt[root] = 0;
    C[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int target = arr[i];
        // printf("[%d]\n", i);
        parr.insert(target);
        narr.insert(-target);
        auto rit = parr.find(target);
        auto lit = narr.find(-target);
        rit++;
        lit++;
        // cout << *rit << -*lit << "\n";
        int parent;

        if (rit == parr.end())
        { //제일 큰수보다 큼.
            // printf("ddasd");
            parent = *(--parr.find(target));
            tree[parent].second = target;
            // printf("B  ");
        }
        else if (lit == parr.end())
        { //제일 작은보다 작음.
            parent = -(*(--parr.find(target)));
            tree[parent].first = target;
            // printf("S  ");
        }
        else
        {                   // 두 수 사이에 있음.
            int er = *rit;  //큰수
            int el = -*lit; //작은수.

            // printf("M[%d %d]", el, er);
            if (!tree[er].first)
            {
                parent = er;
                tree[parent].first = target;
                // printf("1 ");
            }
            else if (!tree[el].second)
            {
                parent = el;
                tree[parent].second = target;
                // printf("2 ");
            }
        }
        cnt[target] = cnt[parent] + 1;
        Parent[target] = parent;

        // printf("%d\n", cnt[target]);
        C[i] = C[i - 1] + cnt[target];
        // printf("P:%d C:%d\n", parent, target);
    }
    for (int i = 0; i < n; i++)
    {
        cout << C[i] << "\n";
    }

    return 0;
}