#include<iostream>
#include<string.h>

using namespace std;
char str[3000];
int startN=0,endN=0;
int startD=0,endD=0;
int strsize;
void getNum(){
    int sd=startD,ed=endD;
    startN=0,endN=0;
    for(int i=0;i<strsize&&i<sd;i++)
    {
        startN*=10;
        startN+=str[i]-'0';
    }

    for(int i=strsize-endD;i<strsize;i++)
    {
        endN*=10;
        endN+=str[i]-'0';
    }

}

int getDif()
{
    if(startD==endD)
    {
        return (endN-startN+1)*startD;
    }

    if(endD>=3)
    {
        if(startD>=2)
        {
            return (100-startN)*2+(endN-99)*3;
        }
        else
        {
            return 180+(10-startN)+(endN-99)*3;
        }
    }
    else if(endD>=2)
    {
        //startd가 한자리.
        return (endN-9)*2+(10-startN);
    }
    return 0;
}
int main(){
    scanf("%s",str);
    strsize=strlen(str);

    //printf("strsize:%d\n",strsize);

    int size;
    for(int i=1;i<=3&&i<=strsize;i++)
    {
        for(int j=i;j<=3&&j<=strsize;j++)
        {
            startD=i;endD=j;
            
            getNum();
            if(startN>endN)continue;

            size=getDif();
            //printf("i: %d j: %d startN: %d endN: %d\n",i,j,startN,endN);
            if(size==strsize)
            {
                
                
                    cout<<startN<<" "<<endN;
                
                return 0;
            }
        }
    }



    return 0;
}