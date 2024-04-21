#include<iostream>
#include<queue>
using namespace std;
queue<int> line;
int main(){
    for (int i = 0; i < 10; i++){
        line.push(i);
    }
    cout<<line.front()<<endl;
    cout<<line.back()<<endl;
    line.pop();
    cout<<line.front()<<endl;
    cout<<line.back();
}
