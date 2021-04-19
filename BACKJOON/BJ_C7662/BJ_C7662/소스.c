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

int main() {
	int* maxh;
	int n, t, order;
	char input;

	scanf("%d", &n);
	
	getchar();

	maxh = (int*)malloc(sizeof(int) * 100001);

	maxh[0] = 0;

	for (int i = 0; i < n; ) {
		scanf("%d", &t);
		getchar();
		for (int j = 0; j < t; j++)
		{

			scanf("%c %d", &input, &order);
			getchar();
			if (input == 'I')
			{
				InsertmaxHeap(maxh, order);

			}
			else
			{

				if (maxh[0] == 0)
				{
					
					continue;
				}
				if (order == 1)
					Deletemaxheap(maxh);
				else
					Deletemin(maxh);
			}
		}
		if (maxh[0] == 0)
			printf("EMPTY\n");
		else
		{
			printf("Ãâ: %d %d\n", maxh[1], Deletemin(maxh));
		}

		maxh[0] = 0;
	}
	
	



	return 0;
}



int Deletemin(int* arr) {

	int start = arr[0] / 2 + 1;
	int min = arr[start];
	int target = start;
	for (int i = start; i <= arr[arr[0]]; i++) {
		if (min < arr[i])
		{
			min = arr[i];
			target = i;
		}
	}
	for (int i = target; i < arr[arr[0]]; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[0]--;
	return min;
}
void InsertmaxHeap(int* arr, int data) {
	int child = arr[0] + 1;

	while (child != 1)
	{

		if (arr[Retparent(child)] > arr[child])
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
}

int Deletemaxheap(int* arr)
{
	int ret = arr[1];
	int index = 1, last = arr[0];
	while (Retleft(index) < arr[0])
	{
		if (last >= arr[Retmaxpriority(arr, index)])
		{
			arr[index] = last;
			break;
		}
		else
		{
			arr[index] = arr[Retmaxpriority(arr, index)];
			index = Retmaxpriority(arr, index);
		}
	}
	arr[0]--;
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

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
////void InsertminHeap(int* arr, int data);
////int Deleteminheap(int* arr);
////int Retminpriority(int* arr, int index);
//void InsertmaxHeap(int* arr, int data);
//int Deletemaxheap(int* arr);
//int Retmaxpriority(int* arr, int index);
//int Retparent(int i);
//int Retleft(int i);
//int Retright(int i);
//
//int Deletemin(int* arr);
//
//int main() {
//	int* maxh;
//	int n,t,order;
//	char input;
//
//	scanf("%d", &n);
//	scanf("%d", &t);
//	getchar();
//	
//	maxh = (int*)malloc(sizeof(int) * (n + 1));
//
//	maxh[0] = 0;
//
//	for (int i = 0; i < t; ) {
//		scanf("%c %d", &input, &order);
//		getchar();
//		if (input == 'I')
//		{
//			InsertmaxHeap(maxh, order);
//
//		}
//		else
//		{
//			i++;
//			if (maxh[0] == 0)
//			{
//				printf("EMPTY\n");
//				continue;
//			}
//			if (order == 1)
//				Deletemaxheap(maxh);
//			else
//				Deletemin(maxh);
//		}
//	}
//	if (maxh[0] == 0)
//		printf("EMPTY");
//	else
//	{
//		printf("Ãâ: %d %d\n", maxh[1], Deletemin(maxh));
//	}
//
//	
//
//	return 0;
//}
//
////int findrow(int* arr)
////{
////	int total = 1;
////
////	while (1)
////	{
////
////		total *= 2;
////		if (arr[0] + 1 >= total)
////		{
////			return total / 2;
////		}	
////	}
////}
//////Min
////void InsertminHeap(int* arr,int data) {
////	int child=arr[0]+1;
////	
////	while (child != 1)
////	{
////		
////		if (arr[Retparent(child)] < arr[child])
////		{
////			break;
////		}
////		else
////		{
////			arr[child] = arr[Retparent(child)];
////			child = Retparent(child);
////		
////		}
////	}
////	arr[child] = data;
////	arr[0]++;
////}
////
////int Deleteminheap(int* arr)
////{
////	
////	int ret = arr[1];
////	int index=1,last=arr[0];
////	while (Retleft(index) < arr[0])
////	{
////		if (last <= arr[Retminpriority(arr,index)])
////		{
////			arr[index] = last;
////			break;
////		}
////		else
////		{
////			arr[index] = arr[Retminpriority(arr, index)];
////			index = Retminpriority(arr,index);
////		}
////	}
////	arr[0]--;
////	return ret;
////}
////
////int Retminpriority(int* arr, int index)
////{
////	int left = Retleft(index);
////	int right = Retright(index);
////	if (arr[left] > arr[right])
////		return right;
////	else
////		return left;
////}
//
//int Deletemin(int* arr) {
//	
//	int start = arr[0]/2+1;
//	int min = arr[start];
//	int target=start;
//	for (int i = start; i <= arr[arr[0]]; i++) {
//		if (min < arr[i])
//		{
//			min = arr[i];
//			target = i;
//		}
//	}
//	for (int i = target; i < arr[arr[0]]; i++)
//	{
//		arr[i] = arr[i + 1];
//	}
//	arr[0]--;
//	return min;
//}
//void InsertmaxHeap(int* arr, int data) {
//	int child = arr[0] + 1;
//
//	while (child != 1)
//	{
//
//		if (arr[Retparent(child)] > arr[child])
//		{
//			break;
//		}
//		else
//		{
//			arr[child] = arr[Retparent(child)];
//			child = Retparent(child);
//
//		}
//	}
//	arr[child] = data;
//	arr[0]++;
//}
//
//int Deletemaxheap(int* arr)
//{
//	int ret = arr[1];
//	int index = 1, last = arr[0];
//	while (Retleft(index) < arr[0])
//	{
//		if (last >= arr[Retmaxpriority(arr, index)])
//		{
//			arr[index] = last;
//			break;
//		}
//		else
//		{
//			arr[index] = arr[Retmaxpriority(arr, index)];
//			index = Retmaxpriority(arr, index);
//		}
//	}
//	arr[0]--;
//	return ret;
//}
//
//int Retmaxpriority(int* arr, int index)
//{
//	int left = Retleft(index);
//	int right = Retright(index);
//	if (arr[left] < arr[right])
//		return right;
//	else
//		return left;
//}
//
//int Retparent(int i)
//{
//	return i / 2;
//}
//int Retleft(int i)
//{
//	return 2 * i;
//}
//int Retright(int i)
//{
//	return 2 * i + 1;
//}