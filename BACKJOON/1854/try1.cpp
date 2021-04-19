#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 2000000000


int numofPQ = 0, k;
typedef struct Graph
{
    struct Vertex* V;
    int n, start, e;
    int* visit, * dist;
} Graph;

typedef struct Vertex
{
    struct Edge* E;
    int* dist;
} Vertex;

typedef struct Edge
{
    struct Edge* next;
    int u, v;
    int w;
} Edge;

typedef struct pair
{
    int dist, num;
} pair;

void ShowGraph(Graph*);
void ShowQ(pair*);
Graph* CreateGraph();
Edge* CreateEdge();

void InsertE(Graph*);
void djikstra(Graph*);

void PQ_Insert(pair*, int, int);
int PQ_Pop(pair*);
pair PQ2_Pop(pair*);

void Heap_Insert(int arr[], int incoming);
int DownHeap(int arr[], int parent);
int Pop(int arr[]);


int main()
{

    Graph* G = CreateGraph();

    //ShowGraph(G);
    djikstra(G);

    for (int i = 1; i <= G->n; i++)
    {
        if (G->V[i].dist[0] !=k)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n", G->V[i].dist[1]);
    }


}

Graph* CreateGraph()
{
    int v, e;
    scanf("%d %d %d", &v, &e, &k);
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->n = v;
    G->start = 1;
    G->e = e;

    G->V = (Vertex*)malloc(sizeof(Vertex) * (v + 2));
    G->dist = (int*)malloc(sizeof(int) * (v + 2));
    G->visit = (int*)malloc(sizeof(int) * (v + 2));

    for (int i = 1; i <= v; i++)
    {
        G->V[i].E = CreateEdge();
        G->dist[i] = MAX;
        G->V[i].dist = (int*)malloc(sizeof(int) * (k + 5));
        G->V[i].dist[0] = 0;
        G->visit[i] = 0;
    }
    G->V[1].dist[0] = 1;
    G->V[1].dist[1] = 0;
    for (int i = 0; i < e; i++)
    {
        InsertE(G);
    }

    return G;
}

Edge* CreateEdge()
{
    Edge* E = (Edge*)malloc(sizeof(Edge));
    E->next = NULL;
    return E;
}

void InsertE(Graph* G)
{
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    Edge* newE = CreateEdge();
    newE->u = u;
    newE->v = v;
    newE->w = w;

    newE->next = G->V[u].E->next;
    G->V[u].E->next = newE;
}

void djikstra(Graph* G)
{
    //사전 작업
    int* dist = G->dist;
    int* visit = G->visit;

    pair* PQ = (pair*)malloc(sizeof(pair) * (G->e + G->n));
    PQ_Insert(PQ, 1, 0);
    dist[G->start] = 0;
    int curV, z, dz,curVdist;
    Edge* curE;
    pair Cur;
    while (numofPQ > 0)
    {

        Cur = PQ2_Pop(PQ);
        curV = Cur.num;
        curVdist = Cur.dist;

     

        curE = G->V[curV].E->next;

        while (curE != NULL)
        {
            z = curE->v;

            /*if (dz > dist[curV] + curE->w)
            {
                dist[z] = dist[curV] + curE->w;
                PQ_Insert(PQ, z, dist[z]);

            }*/
            dz = curVdist + curE->w;
            if (G->V[z].dist[0] < k)//k보다 작으면 그냥 들어가
            {
                Heap_Insert(G->V[z].dist, dz);
                PQ_Insert(PQ, z, dz);
            }
            else//k 초과면~
            {    //작은 녀석들은 집어 넣어주고 큰 녀석들은 넣지마
                if (G->V[z].dist[1] > dz)
                {
                    Pop(G->V[z].dist);
                    Heap_Insert(G->V[z].dist, dz);
                    PQ_Insert(PQ, z, dz);
                }
                else {
                    
                }

            }
            



            curE = curE->next;

        }

    }
}

void PQ_Insert(pair* PQ, int Vidx, int dist)
{
    numofPQ++;
    int child, parent;
    pair Npair;

    Npair.num = Vidx;
    Npair.dist = dist;

    child = numofPQ;
    parent = child / 2;

    while (parent > 0)
    {
        if (PQ[parent].dist > Npair.dist)
        {
            PQ[child] = PQ[parent];
        }
        else break;

        child = parent;
        parent = child / 2;
    }

    PQ[child] = Npair;

    //printf("ins ");
    //ShowQ(PQ);

}
pair PQ2_Pop(pair* PQ)
{
    pair ret = PQ[1];
    pair temp = PQ[numofPQ];
    numofPQ--;

    int child, parent;
    parent = 1;
    child = 2;



    while (child <= numofPQ)
    {
        if (child == numofPQ) //왼쪽만 비교
        {
            if (PQ[child].dist < temp.dist)
            {
                PQ[parent] = PQ[child];
            }
            else
                break;
        }

        if (PQ[child].dist > PQ[child + 1].dist)
            child++;

        if (PQ[child].dist < temp.dist)
        {
            PQ[parent] = PQ[child];
        }
        else break;

        parent = child;
        child = parent * 2;
    }

    PQ[parent] = temp;

    //printf("pop ");
    //ShowQ(PQ);//TEST

    return ret;
}

int PQ_Pop(pair* PQ)
{
    int ret = PQ[1].num;
    pair temp = PQ[numofPQ];
    numofPQ--;

    int child, parent;
    parent = 1;
    child = 2;



    while (child <= numofPQ)
    {
        if (child == numofPQ) //왼쪽만 비교
        {
            if (PQ[child].dist < temp.dist)
            {
                PQ[parent] = PQ[child];
            }
            else
                break;
        }

        if (PQ[child].dist > PQ[child + 1].dist)
            child++;

        if (PQ[child].dist < temp.dist)
        {
            PQ[parent] = PQ[child];
        }
        else break;

        parent = child;
        child = parent * 2;
    }

    PQ[parent] = temp;

    //printf("pop ");
    //ShowQ(PQ);//TEST

    return ret;
}

void ShowGraph(Graph* G)
{
    Edge* E;
    for (int i = 1; i <= G->n; i++)
    {
        printf("[%d]: ", i);
        E = G->V[i].E->next;
        while (E != NULL)
        {
            printf("%d ", E->v);
            E = E->next;
        }
        printf("\n");
    }
}
void ShowQ(pair* Q)
{
    printf("PQ printing\n");
    for (int i = 1; i <= numofPQ; i++)
    {
        printf("Vidx: %d Dist: %d\n", Q[i].num, Q[i].dist);
    }
}


void Heap_Insert(int arr[], int incoming)
{
    arr[0]++;
    arr[arr[0]] = incoming;//error
    for (int i = arr[0] / 2; i > 0; i /= 2)
    {
        if (i == DownHeap(arr, i))
            break;
    }
 /*    printf("Insert: ");
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
        if (arr[child] > arr[parent])
        {
            arr[parent] = arr[child];
            parent = child;
        }
    }
    else
    {
        if (arr[child] < arr[child + 1])
            child++;

        if (arr[child] > arr[parent])
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
        if (arr[Lchild] > arr[Rchild]) //왼쪽이 더 작음
        {
            if (arr[Lchild] <= temp)
                break;

            arr[parent] = arr[Lchild];

            parent = Lchild;
        }
        else
        {
            if (arr[Rchild] <= temp)
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