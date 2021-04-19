#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int arr[100];
	int Rarr[100] =  { 0 };
	int num = 0;
	int input;
	int cnt = 0;

	while (cnt != 100) {
		scanf("%d", &input);
		if (input < 0)
			break;
		arr[cnt++] = input;


	}
	if (cnt == 0)
	{
		printf("none");
		return 0;
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (arr[i] == arr[j]) {
				Rarr[i]++;
			}
		}
	}//Rarr세팅
	int temp;
	for (int i = 0; i < cnt - 1; i++){
		for (int j = i + 1; j < cnt; j++) {
			if (Rarr[i] > Rarr[j])
			{
				temp=Rarr[i];
				Rarr[i] = Rarr[j];
				Rarr[j] = temp;

				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	int ncnt=1;
	int new[100];
	int Rnew[100];
	new[0] = arr[0];
	Rnew[0] = Rarr[0];
	int ch = 0;
	for (int i = 1; i < cnt; i++) {
		ch = 0;
		for (int j = 0; j < ncnt; j++) {
			if (new[j] == arr[i])
			{
				ch++;
				break;
			}
		}
		if (ch == 0)
		{
			new[ncnt] = arr[i];
			Rnew[ncnt++] = Rarr[i];
		}
	}
	//new와 rnew로 재정렬

	for (int i = 0; i < ncnt-1; i++) {
		for (int j = i + 1; j < ncnt; j++) {
			if (new[i] > new[j] && Rnew[i] == Rnew[j]) {
				temp = new[i];
				new[i] = new[j];
				new[j] = temp;
				temp = Rnew[i];
				Rnew[i] = Rnew[j];
				Rnew[j] = temp;

			}


		}
	}

	for (int i = 0; i < ncnt; i++) {
		printf("%d (%d)\n", new[i], Rnew[i]);
	}

	printf("end");
	return 0;
}