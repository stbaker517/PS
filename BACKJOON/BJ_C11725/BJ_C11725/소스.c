#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void InsertmaxHeap(int* arr, int data);
int Deletemaxheap(int* arr);
int Retmaxpriority(int* arr, int index);
int Retparent(int i);
int Retleft(int i);
int Retright(int i);

int Deletemin(int* arr);

int main() {//max min heap으로 하는 게 빠를듯
	int* maxh;
	int n, t, order;
	char input;

	scanf("%d", &n);

	getchar();

	maxh = (int*)malloc(sizeof(int) * 1000001);

	maxh[0] = 0;

	for (int i = 0; i < n;i++ ) {
		scanf("%d", &t);
		
		
		for (int j = 0; j < t; j++)
		{

			getchar();
			scanf("%c", &input);
			getchar();
			scanf("%d", &order);
			

			if (input == 'I'&&maxh[0]<t)
			{
				InsertmaxHeap(maxh, order);


			}
			else
			{

				if (maxh[0] == 0)
				{

					continue;
				}
				else {
					if (order == 1)
						Deletemaxheap(maxh);
					else
						Deletemin(maxh);
				}
			}
		}
		if (maxh[0] == 0)
			printf("EMPTY\n");
		else
		{
			printf("%d %d\n", maxh[1], maxh[maxh[0]]);
		}

		maxh[0] = 0;
	}





	return 0;
}



int Deletemin(int* arr) {

	
	return arr[arr[0]--];
}
void InsertmaxHeap(int* arr, int data) {
	int child = arr[0] + 1;

	while (child != 1)
	{

		if (arr[Retparent(child)] > data)
		{
			break;
		}
		else
		{
			arr[child] = arr[Retparent(child)];
			child = Retparent(child);

		}
	}
	arr[child] = data;
	arr[0]++;
	if (arr[0] > 1) {


		if (arr[arr[0]] > arr[arr[0] - 1])
		{
			int temp;
			temp = arr[arr[0]];
			arr[arr[0]] = arr[arr[0] - 1];
			arr[arr[0] - 1] = temp;
		}
	}
}

int Deletemaxheap(int* arr)
{
	int ret = arr[1];
	int index = 1, last = arr[0];
	while (Retleft(index) <= arr[0])
	{
		if (arr[last] >= arr[Retmaxpriority(arr, index)])
		{

			break;
		}
		else
		{
			arr[index] = arr[Retmaxpriority(arr, index)];
			index = Retmaxpriority(arr, index);
		}
	}
	arr[index] = arr[last];
	arr[0]--;
	if (arr[0] > 1) {


		if (arr[arr[0]] > arr[arr[0] - 1])
		{
			int temp;
			temp = arr[arr[0]];
			arr[arr[0]] = arr[arr[0] - 1];
			arr[arr[0] - 1] = temp;
		}
	}
	return ret;
}

int Retmaxpriority(int* arr, int index)
{
	int left = Retleft(index);
	int right = Retright(index);
	if (arr[left] < arr[right])
		return right;
	else
		return left;
}

int Retparent(int i)
{
	return i / 2;
}
int Retleft(int i)
{
	return 2 * i;
}
int Retright(int i)
{
	return 2 * i + 1;
}