#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	int size;
	struct Node* first;
	struct Node* second;
	struct Node* third;
	struct Node* fourth;
}Node;
typedef struct QuadTree {
	Node* root;

}QuadTree;
int main() {
	int n;
	int len = n;

	scanf("%d", &n);
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);

		}
	}
	
	return 0;
}



