#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int count = 0, n;
int H = 0; int T = 0;
int* Q;

void BFS(int** map, int* visit, int i) {
    if (visit[i] == 1)return;
    visit[i] = 1;
    Q[T++] = i;
    for (int j = 1; j <= n; j++)
    {
        if (visit[j] == 0)
            Q[T++] = j;
    }
    int pop;
    while (H != T)
    {
        pop = Q[H++];
        BFS(map, visit, pop);
    }
    for (int i = 0; i <= T; i++)printf("%d ", Q[i]);
}
void DFS(int** map, int* visit, int i) {
    if (visit[i] == 1)return;
    visit[i] = 1;
    printf("%d ", i);
    for (int i = 1; i <= n; i++)
        DFS(map, visit, i);
}

int main() {
    int bfs[101];
    for (int i = 0; i <= 100; i++)bfs[i] = 0;

    int dfs[101];
    for (int i = 0; i <= 100; i++)dfs[i] = 0;
    int m, k;
    scanf("%d %d", &n, &m, &k);
    Q = (int*)malloc(sizeof(int) * n + 1);
    int u, v;
    int** map = (int**)malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        map[i] = (int*)malloc(sizeof(int) * (n + 1));
        for (int j = 0; j <= n; j++)map[i][j] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        map[u][v] = 1;
        map[v][u] = 1;
    }

    DFS(map, dfs, k);
    printf("\n");
    BFS(map, bfs, k);
}

#include<iostream>

int count = 0, n;
int H = 0; int T = 0;
int* Q;

void BFS(int** map, int* visit, int i) {
    if (visit[i] == 1)return;
    visit[i] = 1;
    Q[T++] = i;
    for (int j = 1; j <= n; j++)
    {
        if (visit[j] == 0)
            Q[T++] = j;
    }
    int pop;
    while (H != T)
    {
        pop = Q[H++];
        BFS(map, visit, pop);
    }
    for (int i = 0; i <= T; i++)printf("%d ", Q[i]);
}
void DFS(int** map, int* visit, int i) {
    if (visit[i] == 1)return;
    visit[i] = 1;
    printf("%d ", i);
    for (int i = 1; i <= n; i++)
        DFS(map, visit, i);
}

int main() {
    int bfs[101];
    for (int i = 0; i <= 100; i++)bfs[i] = 0;

    int dfs[101];
    for (int i = 0; i <= 100; i++)dfs[i] = 0;
    int m, k;
    scanf("%d %d", &n, &m, &k);
    Q = (int*)malloc(sizeof(int) * n + 1);
    int u, v;
    int** map = (int**)malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i < n + 1; i++)
    {
        map[i] = (int*)malloc(sizeof(int) * (n + 1));
        for (int j = 0; j <= n; j++)map[i][j] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        map[u][v] = 1;
        map[v][u] = 1;
    }

    DFS(map, dfs, k);
    printf("\n");
    BFS(map, bfs, k);
}

