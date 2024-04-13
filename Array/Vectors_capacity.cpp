#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr;
    for (int i = 1; i <= 10; i++){
        arr.push_back(i);
    }
    cout<<"The size of the vector is "<<arr.size()<<endl;
    cout<<"The capacity of the vector is "<<arr.capacity()<<endl;
    cout<<"The maximum size of the vector is "<<arr.max_size()<<endl;
    arr.resize(5);
    cout<<"Vector size after resizing is "<<arr.size()<<endl;
    if (arr.empty() == false){
        cout<<"vector is not empty";
    }else{
        cout<<"vector is empty";
    }
    return 0;
}