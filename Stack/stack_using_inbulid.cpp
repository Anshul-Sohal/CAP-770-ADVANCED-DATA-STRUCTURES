#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> stack;
    for (int i = 0; i < 10; i++){
        stack.push(i);
    }
    for (int i = 0; i < 10; i++){
        cout<<stack.top();
        stack.pop();
    }
}