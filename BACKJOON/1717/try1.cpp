#include<iostream>
int Find(int arr[],int i);

void Union(int arr[],int i1,int i2);
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int*arr=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<=n;i++) arr[i]=i;

    int c1,c2,c3;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&c1,&c2,&c3);
        if(c1==0){
            Union(arr,c2,c3);
        }

        else{
            if(Find(arr,c2)==Find(arr,c3)) printf("YES\n");
            else printf("NO\n");
        }
    }



    return 0;

}


int Find(int arr[],int i)
{
    if(arr[i]==i)
        return i;
    else { 
        int p=Find(arr,arr[i]);
        arr[i]=p;
        return p;
    }
}

void Union(int arr[],int i1,int i2)
{
    int p1=Find(arr,i1);
    int p2=Find(arr,i2);

    if(p1==p2)return;
    else if(p1<p2)
    {
        arr[p2]=p1;
    }
    else arr[p1]=p2;
}