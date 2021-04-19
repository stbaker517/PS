#include <iostream>

typedef struct Graph
{
    struct Vertex *V;
    int *tptable, *Q;
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

Graph *CreateGraph();
void tpsort(Graph *);

Edge *CreateEdge();

int main()
{
    Graph *G = CreateGraph();

    tpsort(G);

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
    G->Q = (int *)malloc(sizeof(int) * n);

    for (int i = 1; i <= n; i++)
    {
        G->V[i].E = CreateEdge();
        G->V[i].in = 0;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &e);

        NewE = CreateEdge();
        NewE->s = s;
        NewE->e = e;

        NewE->next = G->V[s].E->next;
        G->V[s].E->next = NewE;

        G->V[e].in++;
    }

    return G;
}

void tpsort(Graph *G)
{
    int *Que = G->Q;
    int *TpTb = G->tptable;

    int QH = 0, QT = 0;

    for (int i = 1; i <= G->n; i++)
    {
        if (G->V[i].in == 0)
        {
            Que[QT++] = i;
        }
    }

    int idx;
    Edge *Eidx, *P;
    while (QH < QT)
    {
        //dequeue
        idx = Que[QH];
        Eidx = G->V[idx].E->next;

        //위상정렬 어레이에 정점 번호 저장
        G->tptable[QH++] = idx;

        while (Eidx != NULL)
        {
            G->V[Eidx->e].in--; //in degree reduction
            if (G->V[Eidx->e].in == 0)
            {
                //inqueue
                Que[QT++] = Eidx->e;
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

    for (int i = 0; i < G->n; i++)
        printf("%d ", G->tptable[i]);
}

Edge *CreateEdge()
{
    Edge *E = (Edge *)malloc(sizeof(Edge));
    E->next = NULL;
    return E;
}