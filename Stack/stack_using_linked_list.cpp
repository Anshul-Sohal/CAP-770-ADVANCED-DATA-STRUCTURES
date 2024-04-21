#include<iostream>
using namespace std;
struct node{
    int data;
    node*next;
};node*top = NULL;
void push(int data){
    node*temp = new node;
    temp->data = data;
    temp->next = top;
    top = temp;
}
void pop(){
    if(top == NULL){
        cout<<"Under Flow! Stack is empty\n";
    }else{
        node*temp = top;
        top = temp->next;
        delete temp;
    }
}
void peek(){
    if(top == NULL){
        cout<<"Stack is empty";
    }else{
        cout<<top->data<<endl;
    }
}
int main(){
    for (int i = 0; i < 10; i++){
        push(i);
    }
    peek();
    pop();
    peek();    
}