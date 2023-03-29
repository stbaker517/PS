#include<iostream>
#include<queue>
using namespace std;

int n;
int arr[1<10];

int arr[1<<10][1<<10];
int num[1<<10];

typedef struct {
    int start;
    int end;
    int num;
    struct node* prev;
    struct node* next;
}node;

typedef struct{
    node*head;
    node*tail;
}List;

bool isEmpty(List list) {
    if(list.head == list.tail->prev)return true;
    else return false;
}
typedef struct compare{
    bool operator() (node &a, node &b){
        if(a.num>b.num){
            return true;
        } else {
            if(a.start < b.start){
                return true;
            }
        }
        return false;
    }
}compare;

priority_queue<node,vector<node>,compare>PQ;


void remove(int idx){

}
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
}