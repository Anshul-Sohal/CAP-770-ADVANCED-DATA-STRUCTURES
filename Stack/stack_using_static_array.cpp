#include<iostream>
using namespace std;
const int MAX_SIZE = 10;
int stack[MAX_SIZE];
int top_element = -1;
void push(int element){
    if(top_element < MAX_SIZE - 1){
        top_element++;
        stack[top_element] = element;
    }else{
        cout<<"Overflow! Stack is full\n";
    }
}
void pop(){
    if(top_element>=0){
        top_element--;
    }else{
        cout<<"Underflow! Stack is empty";
    }
}
void top(){
    if(top_element>=0){
        cout<<stack[top_element]<<endl;
    }else{
        cout<<"The Stack is empty";
    }
}
int main(){
    for (int i = 0; i < 10; i++)
    {
        push(i);
    }
    top();
    push(0);
    pop();
    top();
}
