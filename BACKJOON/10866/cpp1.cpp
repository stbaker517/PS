#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> DQ;
    int n;
    cin>>n;
    string input;
    int x;
    
    for(int i=0;i<n;i++)
    {
        cin>>input;

        if(!input.compare("push_front"))
        {
            cin>>x;
            DQ.push_front(x);
               
        }
        else if(!input.compare("push_back"))
        {
             
            cin>>x;
            DQ.push_back(x);
            
        }
        else if(!input.compare("pop_front"))
        {
         
                if(DQ.size()==0)cout<<-1<<'\n';
                else{
                    cout<<DQ.front()<<'\n';
                    DQ.pop_front();
                }
           
        }
        else if(!input.compare("pop_back"))
        {
            if(DQ.size()==0)cout<<-1<<'\n';
                else{
                    cout<<DQ.back()<<'\n';
                    DQ.pop_back();
                }
        }
        else if(!input.compare("size"))
        {
            cout<<DQ.size()<<'\n';
        }
        else if(!input.compare("empty"))
        {
            cout<<(DQ.size()==0)<<'\n';
        }
        else if(!input.compare("front"))
        {
             if(DQ.size()==0)cout<<-1<<'\n';
                else{
                    cout<<DQ.front()<<'\n';
                }
        }
        else if(!input.compare("back"))
        {
            if(DQ.size()==0)cout<<-1<<'\n';
                else{
                    cout<<DQ.back()<<'\n';
                }
        }
           
        
    }
}