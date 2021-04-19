#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int DATATYPE;



typedef struct Node
{
	DATATYPE data;
	struct Node* next;
}Node;

typedef struct Stack {
	Node* head;

}Stack;

void StackInit(Stack* stack);
void Push(Stack* stack, DATATYPE data);

DATATYPE Pop(Stack* stack);


int IsEmpty(Stack* stack);


int main(int argc, char* argv[]) {
	Stack stack;
	StackInit(&stack);//스택의 헤드는 널 헤드 다음 노드부터 존재
	Stack Numstack;
	StackInit(&Numstack);


	int n;
	
	int* arr;
	char* prt;
	int prtcnt = 0;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	prt = (char*)malloc(sizeof(char) * (2 * n + 1));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = n; i >= 1; i--) {
		Push(&Numstack, i);
	}
	Push(&stack, 0);
	//내용물 꺼내기
	//pop할때 본인이 아니면 NO반납해주기
	for (int i = 0; i < n; i++) {
		while (arr[i] > stack.head->data)
		{
			Push(&stack, Pop(&Numstack));
			prt[prtcnt++] = '+';
		}
		
		if (arr[i] == stack.head->data)
		{
			Pop(&stack);
			prt[prtcnt++] = '-';
		}
		else
		{
			prt[0] = 1;
			break;
		}

	}

	if (prt[0] == 1)
	{
		printf("NO");
		return 0;
	}
	else {
		for (int i = 0; i < 2 * n; i++) {
			printf("%c\n", prt[i]);
		}


	}
	/*int n;
	scanf("%d", &n);
	int input;
	int ch = 0;
	int charr[100001] = { 0 };
	for (int i = n; i >= 1; i--) {
		Push(&Numstack, i);
	}
	char* prt;
	prt = (char*)malloc(sizeof(char) * n * 2);
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	int chh = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		arr[i] = input;
		charr[input] = 1;
		if (i >= 2 && (arr[i - 1] > arr[i]))
		{
			for (int k = arr[i] + 1; k < arr[i - 1]; k++) {
				if (charr[k] == 0)
				{
					
					chh++;
				}
			}
		}

	}
	if (chh != 0)
	{
		printf("NO");
		return 0;
	}
	int max;
	for (int i = 0; i < n; i++) {
		input = arr[i];

		while (input > Data(&stack)) {
			Push(&stack, Pop(&Numstack));
			printf("+\n");
		}

		if (input == Data(&stack)) {
			Pop(&stack);
			printf("-\n");
		}



	}*/




	return 0;
}
int IsEmpty(Stack* stack) {
	if (stack->head == NULL)
		return 1;
	else
		return 0;
}
void StackInit(Stack* stack) {
	stack->head = NULL;


}
void Push(Stack* stack, DATATYPE data) {
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->next = NULL;
	temp->data = data;


	temp->next = stack->head;
	stack->head = temp;
}

DATATYPE Pop(Stack* stack) {
	if (stack->head == NULL)
		return FALSE;
	Node* temp;
	DATATYPE ret;
	temp = stack->head;
	stack->head = stack->head->next;

	ret = temp->data;
	free(temp);

	return ret;

}

int Data(Stack* stack) {
	if (IsEmpty(stack))
		return 0;
	else
		return stack->head->data;
}