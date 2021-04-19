#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Graph
{
    struct Vertex *V;
    int NumOfVertex;
    int *TPtable;
    int *Inorder;
    int*PQ;
    int n;
    int QH, QT;
} Graph;

typedef struct Vertex
{
    int visited;
    struct Edge *E;

} Vertex;

typedef struct Edge
{
    int a, b;
    int w;
    struct Edge *next;
} Edge;

typedef struct Node{
    int data;
    struct Node* prev,*next;
}Node;
typedef struct Queue{
    Node*Head,*Tail;
}Queue;

Graph *CreateGraph();
Edge *CreateEdge();
void Insert_Edge(Graph *, int, int);

Node* CreateNode();
Queue* CreateQueue();
int IsQEmpty(Queue*);
void Insert_Q(Queue*,int);
int Pop_Q(Queue*);

void TPSort(Graph *);

void PQ_Insert(int arr[], int incoming);
int DownHeap(int arr[], int parent);
int Pop(int arr[]);

void Q_Insert(Graph *, int incoming);
int Q_Pop(Graph *);

void ShowGraph(Graph*);
int main()
{
    Graph *G = CreateGraph();
    //printf("done\n");
    //ShowGraph(G);
    
    TPSort(G);

    if (G->TPtable[0] < G->n)
        printf("0");
    else
    {
        for (int i = 1; i <= G->n; i++)
            printf("%d\n", G->TPtable[i]);
    }

    return 0;
}

Graph *CreateGraph()
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->n = n;

    G->V = (Vertex *)malloc(sizeof(Vertex) * (n + 1));
    G->Inorder = (int *)malloc(sizeof(int) * (n + 1));
    G->TPtable = (int *)malloc(sizeof(int) * (n + 1));
    G->TPtable[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        G->V[i].visited = 0;
        G->V[i].E = CreateEdge();
        G->Inorder[i] = 0;
    }
    //입력
   
    int len, a, b;
    

    Queue*Q=CreateQueue();
    int t;
    int input;
    for (int wq = 0; wq < m; wq++)
    {
        scanf("%d",&t);
        
        for(int jk=0;jk<t;jk++)
        {
            scanf("%d",&input);
            Insert_Q(Q,input);
        }
        if(t==0)continue;

        a=Pop_Q(Q);
        while(!IsQEmpty(Q)){
            b=Pop_Q(Q);
            Insert_Edge(G, a, b);

            a=b;
        }
        

    }
    return G;
}

Edge *CreateEdge()
{
    Edge *E = (Edge *)malloc(sizeof(Edge));
    E->next = NULL;
    return E;
}

void Insert_Edge(Graph *G, int a, int b)
{
    Edge *NewE = CreateEdge();
    NewE->a = a;
    NewE->b = b;

    NewE->next = G->V[a].E->next;
    G->V[a].E->next = NewE;

    G->Inorder[b]++;

    return;
}

void TPSort(Graph *G)
{
    
    int n = G->n;
    int *Inorder = G->Inorder, *TPTB = G->TPtable;
    int TPorder = 1;
    //PQ생성
   Queue*Q=CreateQueue();

   /* printf("INORDER:");
    for(int i=1;i<=n;i++)printf("%d ",Inorder[i]);
    printf("\n");*/

    for (int i = 1; i <= n; i++)
    {
        if (Inorder[i] == 0)
        {
            Insert_Q(Q,i);
        }
    }

    int curV, destV;
    Edge *curE;
    while (!IsQEmpty(Q))
    {
        curV = Pop_Q(Q);
        G->V[curV].visited=1;
        TPTB[TPorder++] = curV;
        TPTB[0]++;

        curE = G->V[curV].E->next;

        while (curE != NULL)
        {
            destV = curE->b;
            Inorder[destV]--;
            if (Inorder[destV] == 0&&G->V[destV].visited==0)
            {
                Insert_Q(Q, destV);
            }

            curE = curE->next;
        }
    }
}

void Q_Insert(Graph *G, int incoming)
{
    
    int *PQ=G->PQ;

    PQ[(G->QT)++]=incoming;

    /*printf("INS PQ STATE:");//TEST
    for(int i=G->QH;i<G->QT;i++)printf("%d ",PQ[i]);
    printf("\n");*/
    

}
int Q_Pop(Graph *G)
{
    int ret=G->PQ[(G->QH)++];
    

    /*printf("POP PQ STATE:");//TEST
    for(int i=G->QH;i<G->QT;i++)printf("%d ",G->PQ[i]);
    printf("\n");*/
    return ret;
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


void ShowGraph(Graph*G)
{
    Edge*curE;
    for(int i=1;i<=G->n;i++)
    {
        curE=G->V[i].E->next;

        printf("V[%d]: ",i);
        while(curE!=NULL)
        {
            printf("%d ",curE->b);
            curE=curE->next;
        }
        printf("\n");
    }
}

Node* CreateNode()
{
    Node* newN=(Node*)malloc(sizeof(Node));
    newN->next=NULL;
    newN->prev=NULL;
    return newN;
}
Queue* CreateQueue()
{
    Queue*Q=(Queue*)malloc(sizeof(Queue));
    Q->Head=CreateNode();
    Q->Tail=CreateNode();

    Q->Head->next=Q->Tail;
    Q->Tail->prev=Q->Head;

    return Q;
}
int IsQEmpty(Queue*Q)
{
    if(Q->Head->next==Q->Tail)return 1;
    else return 0;
}

void Insert_Q(Queue* Q,int incoming)
{
    Node* NewNode=CreateNode();
    NewNode->data=incoming;

    NewNode->next=Q->Tail;
    NewNode->prev=Q->Tail->prev;

    NewNode->next->prev=NewNode;
    NewNode->prev->next=NewNode;

    
}
int Pop_Q(Queue* Q)
{


    int ret=Q->Head->next->data;
    Node* remove=Q->Head->next;

    remove->next->prev=remove->prev;
    remove->prev->next=remove->next;

    free(remove);


    return ret;
}