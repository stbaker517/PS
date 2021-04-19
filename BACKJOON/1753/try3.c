#include <iostream>

#define MAX_INT 5000000
typedef struct Graph
{
    struct Vertex *V;
    int *InSack, *PQ; 
    int *dist;
    int n,m;
    int start;
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
    int w;
    struct Edge *next;
} Edge;


Graph *CreateGraph();
void djaikstra(Graph *);

Edge *CreateEdge();

void PQ_Insert(int arr[], int incoming);
int DownHeap(int arr[], int parent);
int Pop(int arr[]);

int main()
{
    Graph *G = CreateGraph();
    //for(int i=1;i<=G->n;i++)    printf("%d ",G->inorder[i]);printf("\n");
    djaikstra(G);


    return 0;
}

Graph *CreateGraph()
{
    int n, m, s, e,st;
    Edge *NewE;
    scanf("%d %d", &n, &m,&st);

    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->start=st;
    G->n = n;
    G->m=m;
    G->V = (Vertex *)malloc(sizeof(Vertex) * (n + 1));
    G->InSack = (int *)malloc(sizeof(int) * (n + 1));
    G->dist = (int *)malloc(sizeof(int) * (n + 1));

    for (int i = 1; i <= n; i++)
    {
        G->V[i].E = CreateEdge();
        G->dist[i] = MAX_INT;
        G->InSack[i]=0;
        G->V[i].visited=0;
    }
    int w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &e,&w);

        NewE = CreateEdge();
        NewE->s = s;
        NewE->e = e;
        NewE->w=w;


        NewE->next = G->V[s].E->next;
        G->V[s].E->next = NewE;

        
    }

    return G;
}

void djaikstra(Graph *G)
{
    
    int *PQ = (int *)malloc(sizeof(int) * (G->n*G->m + 1));
    G->PQ = PQ;
    PQ[0] = 0;

    PQ_Insert(PQ,G->start);

    int idx,EoE,CstV,mindist;
    Edge *Eidx, *P;
    while (PQ[0])
    {
        //dequeue ->우선순위 큐로 정렬돼야함.


        idx = Pop(PQ);
        if(G->V[idx].visited==1)continue;

        Eidx = G->V[idx].E->next;
        G->V[idx].visited = 1;


        
        while (Eidx != NULL)
        {
            EoE=Eidx->e;
            if(G->V[EoE].visited==0){
            if(G->dist[idx]+Eidx->w<G->dist[EoE])
            {
                G->dist[EoE]=G->dist[idx]+Eidx->w;
                PQ_Insert(PQ,EoE);
                
            }

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