#include<iostream>


typedef struct Graph
{
    struct Vertex *V;
    int NumOfVertex;
    int *TPtable;
    int *Inorder;
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

Graph *CreateGraph();
Edge *CreateEdge();
int main()
{

    return 0;
}

Graph *CreateGraph()
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    Graph *G = (Graph *)malloc(sizeof(Graph));

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
    char* str=(char*)malloc(sizeof(char)*(n+1));
    for(int i=0;i<m;i++){
        gets(str);
    }
}

Edge *CreateEdge()
{
    Edge *E = (Edge *)malloc(sizeof(Edge));
    E->next = NULL;
    return E;
}