#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main(){
    string str;
    int n=0;
    cin>>str;
    n+=stoi(str);
    n*=100;
    for(int i=0;i<str.size();i++)
    {
        if(str.at(i)=='.')
        {
            n+=stoi(str.substr(i+1));
            break;
        }
    }
    //cout<<"N: "<<n<<"\n";
    if(36000%n==0)
        cout<<36000/n;

    else
    {
        int idx=1;
        int c=36000;
        

        int N=n;

        int* cd=new int[c+1];

        int slice=N;
        while(c%slice!=0||N%slice!=0)
        {
            slice--;
        }

        cout<<c/slice;
    }



    return 0;
}