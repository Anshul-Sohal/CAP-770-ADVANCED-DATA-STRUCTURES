#include<iostream>
using namespace std;
const int MAX_SIZE = 10;
int queue[MAX_SIZE];
int front = -1;
int back = -1;
void enqueue(int data){
    if (front == -1 && back == -1){
        front++;
        back++;
        queue[front] = data;
    }else{
        back++;
        queue[back] = data;
    }
}
void dequeue(){
    if(front == -1 && back == -1){
        cout<<"UnderFlow! The queue is enpty";
    }else{
        front++;
    }
}
void peek_front(){
    cout<<queue[front]<<endl;
}
void peek_back(){
    cout<<queue[back]<<endl;
}
int main(){
    for (int i = 0; i < 10; i++){
        enqueue(i);
    }
    peek_front();
    peek_back();
    dequeue();
    peek_front();
}