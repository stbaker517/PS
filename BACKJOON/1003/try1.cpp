#include<iostream>

int main(){
   
 
        int arr[41][2];
        arr[0][0]=1;
        arr[0][1]=0;
        
        arr[1][0]=0;
        arr[1][1]=1;

        for(int i=2;i<=40;i++)
        {
            arr[i][0]=arr[i-1][0]+arr[i-2][0];
            arr[i][1]=arr[i-1][1]+arr[i-2][1];
        }
 

    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        printf("%d %d\n",arr[t][0],arr[t][1]);
    }
    return 0;

}