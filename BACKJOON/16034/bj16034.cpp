#include<iostream>

using namespace std;

long long N;


int main(){
    //cin>>N;
    while(1)
    {
        cin>>N;
        if(!N)return 0;
        int i;
        for( i=1;;i++)
        {
            if(i*(i-1)/2>=N)break;
        }

        i--;
        long long temp=i*(i-1)/2;
        int a;
        while(1){
            
            if((N-temp)%i==0)
            {
                a=(N-temp)/i;
                break;}
            else
            {
                i--;
                temp=i*(i-1)/2;
            }
        }
        
        cout<<a<<" "<<i<<"\n";

    }


    return 0;

}