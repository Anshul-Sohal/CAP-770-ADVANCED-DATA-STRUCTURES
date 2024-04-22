#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;
};

node*front = NULL;
node*back=NULL;

void enqueue(int data){
    node*temp = new node;
    temp->data = data;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
        back = temp;
    }else{
        back->next = temp;
        back = temp;
    }
}
void dequeue(){
    if(front == NULL){
        cout<<"Underflow! The queue is empty";
    }else{
        node*temp = front;
        front = front->next;
        delete temp;
    }
}
void peek_front(){
    cout<<front->data<<endl;
}
void peek_back(){
    cout<<back->data<<endl;
}
int main(){
    for (int i = 0; i < 10; i++){
        enqueue(i);
    }
    peek_front();
    peek_back();
    dequeue();
    peek_front();
    dequeue();
    peek_front();    
    while(front!= NULL){
        node*temp = front;
        front = front->next;
        delete temp;
    }
}