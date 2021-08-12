#include<iostream>
#include<algorithm>
using namespace std;

char arr[16];
char ptr[16];
int visit[16];
int mo,ja;
int l,c;

bool isMo(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')return true;
    else return false;
}
void func(int k,int idx)
{
    if(k==l)
    {
        //printf("%s m: %d j: %d\n",ptr,mo,ja);
        if(mo>=1&&ja>=2)
            printf("%s\n",ptr);
        return;
    }

    for(int i=idx;i<c;i++)
    {
        if(visit[i])continue;
        visit[i]=true;

        if(isMo(arr[i])){mo++;
            ptr[k]=arr[i];
            func(k+1,i+1);
            mo--;

        }
        else {ja++;
            ptr[k]=arr[i];
        func(k+1,i+1);
            
            ja--;
            }

        

        

        visit[i]=false;
    }


}
int main(){
    cin>>l>>c;
    for(int i=0;i<c;i++)
    {
        cin>>arr[i];
    }
    
    sort(arr,arr+c);
    //for(int i=0;i<c;i++)cout<<arr[i];
    func(0,0);

    return 0;
}