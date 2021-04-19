#include <iostream>

typedef struct Graph
{
    struct Vertex *V;
    int *tptable, *PQ;
    int *inorder;
    int n;
} Graph;

typedef struct Vertex
{
    int visited;
    int in;
    struct Edge *E;

} Vertex;

typedef struct Edge
{
    int s, e;
    struct Edge *next;
} Edge;

int QH = 0, QT = 0, InTP = 0;
Graph *CreateGraph();
void tpsort(Graph *);

Edge *CreateEdge();

void PQ_Insert(int arr[], int incoming);
int DownHeap(int arr[], int parent);
int Pop(int arr[]);

int main()
{
    Graph *G = CreateGraph();
    //for(int i=1;i<=G->n;i++)    printf("%d ",G->inorder[i]);printf("\n");
    tpsort(G);

    for (int i = 0; i < QH; i++)
        printf("%d ", G->tptable[i]);
    return 0;
}

Graph *CreateGraph()
{
    int n, m, s, e;
    Edge *NewE;
    scanf("%d %d", &n, &m);

    Graph *G = (Graph *)malloc(sizeof(Graph));

    G->n = n;
    G->V = (Vertex *)malloc(sizeof(Vertex) * (n + 1));
    G->tptable = (int *)malloc(sizeof(int) * (n + 1));
    G->inorder = (int *)malloc(sizeof(int) * (n + 1));

    for (int i = 1; i <= n; i++)
    {
        G->V[i].E = CreateEdge();
        G->inorder[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &e);

        NewE = CreateEdge();
        NewE->s = s;
        NewE->e = e;

        NewE->next = G->V[s].E->next;
        G->V[s].E->next = NewE;

        G->inorder[e]++;
    }

    return G;
}

void tpsort(Graph *G)
{
    int *Inorder = G->inorder;
    int *PQ = (int *)malloc(sizeof(int) * (G->n + 1));
    G->PQ = PQ;
    PQ[0] = 0;

    //제일 작은 정점부터 시작함.
    for (int i = 1; i <= G->n; i++)
    {
        if (Inorder[i] == 0)
        {
            PQ_Insert(PQ, i);
        }
    }

    int idx;
    Edge *Eidx, *P;
    while (PQ[0])
    {
        //dequeue ->우선순위 큐로 정렬돼야함.

        idx = Pop(PQ);
        Eidx = G->V[idx].E->next;
        G->V[idx].visited = 1;
        //위상정렬 어레이에 정점 번호 저장
        G->tptable[QH++] = idx;

        while (Eidx != NULL)
        {
            G->inorder[Eidx->e]--; //in degree reduction

            if (G->inorder[Eidx->e] == 0 )
            {
                //inqueue
                PQ_Insert(PQ, Eidx->e);
            }
           // printf("TPtable: ");//TEST
            //for(int i=1;i<=G->n;i++)    printf("%d ",G->inorder[i]);printf("\n");

            //delete Edge
            P = Eidx;
            //next Edge
            Eidx = Eidx->next;

            free(P);
        }

        //free Edge Head
        free(G->V[idx].E);
    }

    /*for (int i = 0; i < G->n; i++)
        printf("%d ", G->tptable[i]);*/
}

Edge *CreateEdge()
{
    Edge *E = (Edge *)malloc(sizeof(Edge));
    E->next = NULL;
    return E;
}

void PQ_Insert(int arr[], int incoming)
{
    arr[0]++;
    arr[arr[0]] = incoming;
    for (int i = arr[0] / 2; i > 0; i /= 2)
    {
        if (i == DownHeap(arr, i))
            break;
    }
   /* printf("Insert: ");
    for (int i = 1; i <= arr[0]; i++)
        printf("%d ", arr[i]);
    printf("\n");*/
}
int DownHeap(int arr[], int parent)
{
    int child = parent * 2;
    int temp = arr[parent];
    if (arr[0] == child) //마지막 처리
    {
        if (arr[child] < arr[parent])
        {
            arr[parent] = arr[child];
            parent = child;
        }
    }
    else
    {
        if (arr[child] > arr[child + 1])
            child++;

        if (arr[child] < arr[parent])
        {
            arr[parent] = arr[child];
            parent = child;
        }
    }

    arr[parent] = temp;
    return parent;
}

int Pop(int arr[])
{
    int ret = arr[1];
    int temp = arr[arr[0]];
    arr[0]--;
    int parent = 1, Lchild, Rchild;
    while (parent <= arr[0] / 2)
    {
        Lchild = parent * 2;
        Rchild = parent * 2 + 1;
        if (arr[Lchild] < arr[Rchild]) //왼쪽이 더 작음
        {
            if (arr[Lchild] >= temp)
                break;

            arr[parent] = arr[Lchild];

            parent = Lchild;
        }
        else
        {
            if (arr[Rchild] >= temp)
                break;

            arr[parent] = arr[Rchild];
            parent = Rchild;
        }
    }

    arr[parent] = temp;
 /*   printf("Pop: ");
    for (int i = 1; i <= arr[0]; i++)
        printf("%d ", arr[i]);
    printf("\n");*/
    return ret;
}