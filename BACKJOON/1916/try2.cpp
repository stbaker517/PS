
#include <iostream>

#define MAX_INT 2147483647;
typedef struct Graph
{
	struct Vertex *V;
	int nV;
} Graph;

typedef struct Vertex
{
	struct Edge *E;
	int dist;
	int visited;
} Vertex;

typedef struct Edge
{
	struct Edge *next;
	int from, to;
	int w;
} Edge;

typedef struct node
{
	struct node *prev, *next;
	int data;
} node;
typedef struct Queue
{
	struct node *head, *tail;
} Queue;

Graph *CreateGraph();
void Djaikstra(Graph *, int);
Edge *CreateEdge();

Queue *CreateQueue();
node *CreateNode();

int IsQEmpty(Queue *);
void EnQueue(Queue *, int);
int DeQueue(Queue *);

int pop(int*);
int main()
{
	Graph *G = CreateGraph();

	int start, dest;
	scanf("%d %d", &start, &dest);

	Djaikstra(G, start);

	printf("%d", G->V[dest].dist);
	return 0;
}

Graph *CreateGraph()
{
	int N_V, N_E;
	scanf("%d %d", &N_V, &N_E);

	Graph *G = (Graph *)malloc(sizeof(Graph));
	G->nV = N_V;

	//정점 생성
	G->V = (Vertex *)malloc(sizeof(Vertex) * (N_V + 1));

	//정점에 엣지 리스트 연결.
	for (int i = 1; i <= N_V; i++)
	{
		G->V[i].E = CreateEdge();
		G->V[i].dist = MAX_INT;
		G->V[i].visited = 0;
	}

	int departure, destination, fee;

	Edge *newBus;
	for (int i = 0; i < N_E; i++)
	{
		scanf("%d %d %d", &departure, &destination, &fee);

		newBus = CreateEdge();
		newBus->from = departure;
		newBus->to = destination;
		newBus->w = fee;

		newBus->next = G->V[departure].E->next;
		G->V[departure].E->next = newBus;
	}

	return G;
}

void Djaikstra(Graph *G, int start)
{
	int n=G->nV;
	int visitedV=1;

	G->V[start].dist=0;
	G->V[start].visited=1;
	int turn =start;

	Edge*curE=NULL;
	int index=turn;
	int nextmindist=INT_MAX;
	while(visitedV<n){
		
		curE=G->V[turn].E->next;

		G->V[turn].visited=1;
		visitedV++;

		while(curE!=NULL)
		{
			if(G->V[index].dist>G->V[curE->to].dist+curE->w&&G->V[curE->to].visited==0)
			{
				G->V[curE->to].dist=G->V[curE->to].dist+curE->w;
				if(nextmindist>G->V[curE->to].dist)
				{
					nextmindist=G->V[curE->to].dist;
					index=curE->to;
				}
			}

			curE=curE->next;
		}
		turn=index;
	}


}

int pop(int *arr,int*dist)
{
	int limit = arr[0];
	int ret = arr[1];
	int temp = arr[arr[0]--];

	int parent = 1, child = 2;
	while (child <= limit)
	{
		if (child < limit)
		{
			if (arr[child] > arr[child + 1])
				child++;
		}

		if (arr[child] > temp)
			break;

		arr[parent] = arr[child];

		parent=child;
		child=child*2;
	}

	arr[parent]=temp;

	return ret;
}

Edge *CreateEdge()
{
	Edge *E = (Edge *)malloc(sizeof(Edge));
	E->next = NULL;

	return E;
}

Queue *CreateQueue()
{
	Queue *Q = (Queue *)malloc(sizeof(Queue));
	Q->head = CreateNode();
	Q->tail = CreateNode();
	Q->head->next = Q->tail;
	Q->tail->prev = Q->head;
	return Q;
}

node *CreateNode()
{
	node *N = (node *)malloc(sizeof(node));
	N->next = NULL;
	N->prev = NULL;

	return N;
}

int IsQEmpty(Queue *Q)
{
	if (Q->head->next == Q->tail)
		return 1;
	else
		return 0;
}

void EnQueue(Queue *Q, int data)
{
	node *N = CreateNode();
	N->data = data;

	N->next = Q->tail;
	N->prev = Q->tail->prev;

	N->next->prev = N;
	N->prev->next = N;
}

int DeQueue(Queue *Q)
{
	int ret = Q->head->next->data;
	node *temp = Q->head->next;

	Q->head->next = temp->next;
	temp->next->prev = Q->head;
	free(temp);
	return ret;
}
