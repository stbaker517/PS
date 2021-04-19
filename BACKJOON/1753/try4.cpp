#include<iostream>


#define Inf 9999999;
#define Max_Heap 1024*4;
typedef struct Graph {
	struct Vertex* Vert;
	int* T;
	
}Graph;
typedef struct Edge {
	int u, v, w;
}Edge;
typedef struct Vertex {
	
	int Dist;
	Edge* E;
	int numE;

}Vertex;

typedef struct Node {
	
	int Vidx;
	struct Node* next, * prev;
}Node;

typedef struct Queue {
	Node* head, *tail;
}Queue;

//간선 인서트
void InsertE(Graph*);

//큐 작업
Node* CreateNode();
Queue* CreateQueue();
int IsEmptyQ(Queue*);

//힙 정렬
void Headpify(Graph*,int*);
int main() {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	G->T = (int*)malloc(sizeof(int) * (n + 1));
	G->Vert = (Vertex*)malloc(sizeof(Vertex)*(n + 1));
	for (int i = 1; i <= n; i++)
	{
		G->Vert[i].numE = 0;
		G->Vert[i].Dist = Inf;
		G->Vert[i].E = (Edge*)malloc(sizeof(Edge) * m);
	}
	for (int i = 0; i < m; i++)
		InsertE(G);
	for (int i = 1; i <= n; i++)
		G->T[i] = i;
	G->T[0] = n;
	G->Vert[s].Dist = 0;
	G->T[s] = 1;
	G->T[1] = s;

	//for (int i = 1; i <= n; i++)
	//	printf("%d길이: %d  ", G->T[i], G->Vert[G->T[i]].Dist);//test
	//printf("\n\n");

	/*Headpify(G, G->T);*/


	//printf("%d\n", G->T[1]);
	//for (int i = 1; i <= n; i++)
	//	printf("%d길이: %d  ", G->T[i], G->Vert[G->T[i]].Dist);//test
	//	printf("\n\n");

	//for (int i = 1; i <= G->T[0]; i++)
	//	printf("V[%d]: %d  ", G->T[i], G->Vert[G->T[i]].Dist);//test
	//printf("\n\n");

	int u;
	int* P = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; i++)P[i] = 0;
	while (G->T[0] != 0)
	{
		u = G->T[1];
		P[u] = 1;
		int d_u = G->Vert[u].Dist;
		for (int i = 0; i < G->Vert[u].numE; i++)
		{
			
			int z = G->Vert[u].E[i].v;
			int d_z = G->Vert[u].E[i].w;
			
			if (G->Vert[z].Dist > d_z + G->Vert[u].Dist)
				G->Vert[z].Dist = d_z + G->Vert[u].Dist;
			/*printf("u: %d Z: %d Dz: %d\n", u,z, G->Vert[z].Dist);*/


		}

		G->T[1] = G->T[G->T[0]];
		
		G->T[0]--;
		
		//printf("전 ");
		//for (int i = 1; i <= G->T[0]; i++)
		//	printf("V[%d]: %d  ", G->T[i], G->Vert[G->T[i]].Dist);//test
		//printf("\n\n");
		Headpify(G, G->T);
		//printf("후 ");
		//for (int i = 1; i <= G->T[0]; i++)
		//	printf("V[%d]: %d  ", G->T[i], G->Vert[G->T[i]].Dist);//test
		//printf("\n\n");
		
		
		
	}
	//printf("끝\n");

	for (int i = 1; i <= n; i++)
	{
		if(G->Vert[i].Dist==9999999)
		printf("INF\n");
		else
		printf("%d\n",G->Vert[i].Dist);
		
	}



}

void InsertE(Graph*G)
{
	int u, v, w;
	scanf("%d %d %d", &u, &v, &w);
	int u_num_E=G->Vert[u].numE, v_num_E = G->Vert[v].numE;
	G->Vert[u].E[u_num_E].u = u;
	G->Vert[u].E[u_num_E].v = v;
	G->Vert[u].E[u_num_E].w = w;



	G->Vert[u].numE++;



}

Node* CreateNode()
{
	Node* N = (Node*)malloc(sizeof(Node));
	N->next = N->prev = NULL;
	return N;
}

Queue* CreateQueue()
{
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->head = CreateNode();
	Q->tail = CreateNode();
	Q->head->next = Q->tail;
	Q->tail->prev = Q->head;

	return Q;
}

int IsEmptyQ(Queue*Q)
{
	if (Q->head->next == Q->tail)
		return 1;
	else return 0;
}

void Headpify(Graph* G, int* T)
{
	int target = 1;

	int tmp;

	//for (int i = target; i >= 1; i--)
	//{
	//	if (i == target && i * 2+1 > T[0])
	//	{
	//		if (G->Vert[T[i]].Dist < G->Vert[T[i * 2]].Dist)
	//		{
	//			tmp = T[i];
	//			T[i] = T[i*2];
	//			T[i*2] = tmp;
	//		}
	//	}
	//	else if (G->Vert[T[i * 2]].Dist < G->Vert[T[target * 2 + 1]].Dist)//RC가 더 큼
	//	{
	//		if (G->Vert[T[i]].Dist > G->Vert[T[i * 2]].Dist) {
	//			tmp = T[i];
	//			T[i] = T[i * 2 ];
	//			T[i * 2 ] = tmp;
	//		}
	//	}


	//	else if ((G->Vert[T[i * 2]].Dist >= G->Vert[T[target * 2 + 1]].Dist))
	//	{
	//		if (G->Vert[T[i]].Dist > G->Vert[T[i * 2+1]].Dist) {
	//			tmp = T[i];
	//			T[i] = T[i * 2+1];
	//			T[i * 2+1] = tmp;
	//		}
	//	}

	//}/*
	for (int i = T[0] / 2; i >= 1; i--)
	{
		if (i * 2 == T[0])
		{
			if (G->Vert[T[i]].Dist > G->Vert[T[i * 2]].Dist)
			{
				tmp = T[i];
				T[i] = T[i * 2];
				T[i * 2] = tmp;
			}
			continue;
		}
		if (G->Vert[T[i * 2]].Dist < G->Vert[T[i * 2 + 1]].Dist)//왼쪽이 더 작다.
		{
			if (G->Vert[T[i]].Dist > G->Vert[T[i * 2]].Dist)
			{
				tmp = T[i];
				T[i] = T[i * 2];
				T[i * 2] = tmp;
			}
		}
		else
		{
			if (G->Vert[T[i]].Dist > G->Vert[T[i * 2 + 1]].Dist)
			{
				tmp = T[i];
				T[i] = T[i * 2 + 1];
				T[i * 2 + 1] = tmp;
			}
		}
	}

}
