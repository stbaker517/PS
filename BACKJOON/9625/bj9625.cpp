#include<iostream>
#include<queue>
int arr[46][2];
int main(){

    arr[0][0]=1;
    arr[0][1]=0;
    arr[1][0]=0;
    arr[1][1]=1;
    
    
    for(int i=2;i<=45;i++)
    {
        arr[i][0]=arr[i-1][0]+arr[i-2][0];
        arr[i][1]=arr[i-1][1]+arr[i-2][1];
    }
    int k;
    scanf("%d",&k);

    printf("%d %d",arr[k][0],arr[k][1]);


    return 0;
}