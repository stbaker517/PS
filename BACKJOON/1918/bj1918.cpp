#include<iostream>
#include<stack>
#include<string>
#include<queue>

using namespace std;

stack<char>S;
string str;
string ans="";

void prefix(char);
int getValue(char);
int main(){
    getline(cin,str);
    //cin>>str;
    //cout<<str;
    for(int i=0;i<str.size();i++)
    {
        prefix(str.at(i));
    }
    while(!S.empty()){ans+=S.top();S.pop();}
    cout<<ans;
}

void prefix(char c){
    
    switch(c)
    {
        case '(':
            S.push('(');
            break;
        case ')':
            while(S.top()!='(')
            {
                ans+=S.top();
                S.pop();
            }
            S.pop();
            break;
        case '+':
            while(!S.empty()&&getValue(S.top())<=getValue(c))
            {
                ans+=S.top();
                S.pop();
            }
            S.push(c);
            break;
        case '-':
            while(!S.empty()&&getValue(S.top())<=getValue(c))
            {
                ans+=S.top();
                S.pop();
            }
            S.push(c);
            break;
        case '*':
        while(!S.empty()&&getValue(S.top())<=getValue(c))
            {
                ans+=S.top();
                S.pop();
            }
            S.push(c);
            break;
        case '/':
        while(!S.empty()&&getValue(S.top())<=getValue(c))
            {
                ans+=S.top();
                S.pop();
            }
            S.push(c);
            break;
        case ' ':
        break;
        default:
            ans+=c;
            break;
            
    }
    //cout<<'\n'<<c;
    return ;
}

int getValue(char c)
{
    switch(c)
    {
        case '(': return 4;
        case ')': return 4;
        case '*': return 2;
        case '/': return 2;
        case '+':return 3;
        case '-':return 3;
        default: return 0;
    }
}