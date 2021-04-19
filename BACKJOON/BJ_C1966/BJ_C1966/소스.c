#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n;
	int arr[50];
	int cnt;
	int ptr[50];
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		cnt = 0;
		if (arr[i] == 0)
			continue;
		else {
			for (int j = i; j < n; j++) {
				if (arr[i] == arr[j])
				{
					if (cnt == 0)
						cnt++;
					else
					{
						arr[j] = 0;
						cnt++;
					}
				}
			}
			printf("%d %d\n", arr[i], cnt);
		}
	}
	

	return 0;
}
