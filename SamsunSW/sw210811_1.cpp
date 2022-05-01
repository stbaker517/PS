#include<iostream>
 using namespace std;

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node*next;
}Node;

int Max_Node;
Node node[Max_Node];
int nodeCnt;
Node*head;

Node*getNode(int data)
{
    node[nodeCnt].data=data;
    node[nodeCnt].prev=nullptr;
    node[nodeCnt].next=nullptr;
    return &node[nodeCnt++];
}
int main(){

}