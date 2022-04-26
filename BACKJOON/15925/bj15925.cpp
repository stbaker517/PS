#include<iostream>
#include<queue>

using namespace std;

int arr[32][32];

int n;
int k;
queue<int> Q;

void ptr(){
    cout<<"map";
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void f1(){
    //ptr();
    for(int i=1;i<=n;i++)
    {
        if(arr[i][0]*2>=n)
        {
            Q.push(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[0][i]*2>=n)
        {
            Q.push(i+32);
        }
        
    }
}

void f2(){
    f1();
    while(!Q.empty())
    {
        int t=Q.front();
        Q.pop();
        int iscol=t/32;
        t=t%32;

        if(iscol)
        {
            if(arr[0][t]*2>=n)
            {
                for(int i=1;i<=n;i++)
                {
                    if(arr[i][t]!=k)
                       { arr[i][t]=k;
                        arr[i][0]--;
                        arr[0][t]--;}
                }



            }
        }
        else
        {
            if(arr[t][0]*2>=n)
            {
                for(int i=1;i<=n;i++)
                {
                     if(arr[t][i]!=k)
                    {arr[t][i]=k;
                    arr[0][i]--;
                    arr[t][0]--;}
                }
            }
        }
        f1();
    }





}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin>>n>>k;

   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!=k)
            {
                arr[i][0]++;
                arr[0][j]++;
            }
        }
   }

    f2();

        for(int i=1;i<=n;i++)
    {
        if(arr[i][0]||arr[0][i]){cout<<0;
        return 0;}
    }
    cout<<1;


    return 0;
}