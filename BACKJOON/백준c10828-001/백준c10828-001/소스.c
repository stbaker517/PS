#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Datatype;
typedef struct Node {
	Datatype data;
	struct Node* next;
	

}Node;

typedef struct Stack{
	Node* head;
	int numofdata;


}Stack;

void CreateStack(Stack* stack);
void Push(Stack* stack, Datatype data);
Datatype Pop(Stack* stack);

int size(Stack* stack);
int Empty(Stack* stack);
Datatype Top(Stack* stack);
int main() {

	int n;
	char input[5];
	int numpush;
	scanf("%d", &n);
	Stack* stack;
	stack = (Stack*)malloc(sizeof(stack));
	CreateStack(stack);
	for (int i = 0; i < n; i++) {
		
		scanf("%s", input);
		
		if (strcmp(input,"push")==0) {
			scanf("%d", &numpush);
			Push(stack, numpush);
		}
		if (strcmp(input, "pop") == 0) {
			printf("%d\n", Pop(stack));
		}
		if (strcmp(input, "size") == 0) {
			printf("%d\n",stack->numofdata);
		}
		if (strcmp(input, "empty") == 0) {
			printf("%d\n", Empty(stack));
		}
		if (strcmp(input, "top") == 0) {
			printf("%d\n", Top(stack));

		}
		getchar();


	}






	return 0;
}

void CreateStack(Stack* stack) {
	
	stack->head = NULL;
	stack->numofdata = 0;
	return;
}

void Push(Stack* stack, Datatype data) {
	Node* temp;
	temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = stack->head;
	stack->head = temp;
	stack->numofdata++;
	return;
}

Datatype Pop(Stack* stack) {
	if (stack->head == NULL) {
		return -1;
	}
	Node* temp;
	Datatype pop;
	pop = stack->head->data;
	temp = stack->head;
	stack->head = stack->head->next;
	free(temp);
	stack->numofdata--;
	return pop;

}

int size(Stack* stack) {
	return stack->numofdata;
}

int Empty(Stack* stack) {
	if (stack->numofdata == 0)
		return 1;
	else
		return 0;
}

Datatype Top(Stack* stack) {
	if (Empty(stack))
		return -1;

	return stack->head->data;
}