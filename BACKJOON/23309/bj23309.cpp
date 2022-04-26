#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    struct Node *next, *prev;
    int num;
} Node;
typedef struct List
{
    Node *first;
    int numofStation;
} List;

Node arr[1000001];

int n;
int m;
int num[1000000];
void ptr(int n)
{
    int i = n;
    do
    {
        cout << i << " ";
        i = arr[i].next->num;

    } while (i != n);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m;
    for (int i = 0; i <= 1000000; i++)
    {
        arr[i].next = NULL;
        arr[i].prev = NULL;
        arr[i].num = i;
    }
    List *list = new List;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (i == 0)
        {
            list->first = &arr[num];
            list->first->next = list->first;
            list->first->prev = list->first;
            continue;
        }
        Node *target = &arr[num];
        target->next = list->first;
        target->prev = list->first->prev;

        target->next->prev = target;
        target->prev->next = target;
    }
    string cmd;
    int i, j;
    for (int a = 0; a < m; a++)
    {
        cin >> cmd >> i;
        if (cmd.compare("BN") == 0)
        {
            //다음 번호 출력, 그 사이에 j설립
            cin >> j;
            Node *target = arr[i].next;
            cout << target->num;

            Node *nu = &arr[j];
            nu->next = target;
            nu->prev = &arr[i];
            nu->next->prev = nu;
            nu->prev->next = nu;
        }
        else if (cmd.compare("BP") == 0)
        {
            //이전 번호 출력, 그 사이에 j 설립
            cin >> j;
            Node *target = arr[i].prev;
            cout << target->num;

            Node *nu = &arr[j];
            nu->prev = target;
            nu->next = &arr[i];
            nu->next->prev = nu;
            nu->prev->next = nu;
        }
        else if (cmd.compare("CN") == 0)
        {
            //다음역 폐쇄하고 고유번호 출력.
            Node *target = arr[i].next;
            cout << target->num;

            target->next->prev = target->prev;
            target->prev->next = target->next;
            target->next = NULL;
            target->prev = NULL;
        }
        else if (cmd.compare("CP") == 0)
        {
            //이전 역 폐쇄하고 고유번호 출력.
            Node *target = arr[i].prev;
            cout << target->num;

            target->next->prev = target->prev;
            target->prev->next = target->next;
            target->next = NULL;
            target->prev = NULL;
        }
        cout << "\n";
        //ptr(i);
        //cout << "\n";
    }

    return 0;
}