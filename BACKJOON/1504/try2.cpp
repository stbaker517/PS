#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 9000000


int numofPQ = 0;
int ch = 0;
typedef struct Graph
{
    struct Vertex* V;
    int n, start, e;
    int* visit, * dist;
} Graph;

typedef struct Vertex
{
    struct Edge* E;

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
int djikstra(Graph*, int, int);

void PQ_Insert(pair*, int, int);
int PQ_Pop(pair*);

int main()
{
    int v1, v2;
    Graph* G = CreateGraph();


    scanf("%d %d", &v1, &v2);
   

    int route1, route2,route2_1, route3;
    route1 = djikstra(G, 1, v1);
    if (route1 == INT_MAX||ch==1)
    {
        printf("-1");
        return 0;
    }
    route2 = djikstra(G, v1, v2);
    if (route2 == INT_MAX||ch==1)
    {
        printf("-1");
        return 0;
    }
    route2_1 = djikstra(G, v2, v1);
    if (route2_1 == INT_MAX || ch == 1)
    {
        printf("-1");
        return 0;
    }
    route3 = djikstra(G, v2, G->n);
    if (route3 == INT_MAX||ch==1)
    {
        printf("-1");
        return 0;
    }

    if(route2<=route2_1)
    printf("%d", route1 + route2 + route3);
    else
        printf("%d", route1 + route2_1 + route3);
    return 0;
}

Graph* CreateGraph()
{
    int v, e, k;
    scanf("%d %d", &v, &e);
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->n = v;

    G->e = e;

    G->V = (Vertex*)malloc(sizeof(Vertex) * (v + 2));
    G->dist = (int*)malloc(sizeof(int) * (v + 2));
    G->visit = (int*)malloc(sizeof(int) * (v + 2));

    for (int i = 1; i <= v; i++)
    {
        G->V[i].E = CreateEdge();
        G->dist[i] = INT_MAX;
        G->visit[i] = 0;
    }

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

    Edge* newE2 = CreateEdge();
    newE2->u = v;
    newE2->v = u;
    newE2->w = w;

    newE->next = G->V[u].E->next;
    G->V[u].E->next = newE;

    newE2->next = G->V[v].E->next;
    G->V[v].E->next = newE2;
}

int djikstra(Graph* G, int start, int end)
{
    //사전 작업
    numofPQ = 0;
    int* dist = G->dist;
    int* visit = G->visit;
    for (int i = 1; i <= G->n; i++)
    {
        dist[i] = INT_MAX;
        visit[i] = 0;
    }

    pair* PQ = (pair*)malloc(sizeof(pair) * (G->e + G->n)*2);
    PQ_Insert(PQ, start, 0);
    dist[start] = 0;
    int curV, z, dz;
    Edge* curE;

    while (numofPQ > 0)
    {

        curV = PQ_Pop(PQ);
        if (visit[curV] == 1)continue;

        visit[curV] = 1;

        curE = G->V[curV].E->next;

        while (curE != NULL)
        {
            z = curE->v;
            dz = dist[z];
            if (dz > dist[curV] + curE->w)
            {
                dist[z] = dist[curV] + curE->w;
                PQ_Insert(PQ, z, dist[z]);

            }

            curE = curE->next;

        }

    }
    free(PQ);

    if (dist[G->n] == INT_MAX)ch = 1;
    return dist[end];
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