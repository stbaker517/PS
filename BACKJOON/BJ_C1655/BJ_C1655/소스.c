#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(sizeof(int) * n);
	arr[0] = 0;//numofdatas;
	int input;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		
		insert(arr, input);
		arr[0]++;
		for (int i = 0; i <= arr[0]; i++) {
			printf(" %d ", arr[i]);
		}
		printf("mid:");
		if (arr[0] % 2 == 0)
		{
			printf("%d\n", arr[arr[0] / 2 ]);
		}
		else
		{
			printf("%d\n",arr[arr[0] / 2+1]);
		}

	}


	return 0;
}

int insert(int* arr, int data) {
	int index,parent;
	index = arr[0] + 1;
	if (arr[0] == 0)
	{
		arr[1] = data;

		return 1;
	}
	else
	{
		while (RetParent(index))
		{
			parent = RetParent(index);
			if (arr[parent] > data) {
				arr[index] = arr[parent];
				index = parent;
			}
			else
			{
				break;
			}
		}
		arr[index] = data;

		return index;
	}
	

}


int RetParent(int i) {
	return i / 2;
}
