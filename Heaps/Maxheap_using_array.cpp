#include<iostream>
using namespace std;
int arr[100];
int size = 0;
void insert(int data){
    //Time Complexity O(logn)
    ::size++;
    int index = ::size;
    arr[index] = data;
    while(index>1){
        int parent = index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index = parent;
        }else{
            return;
        }
    }
}
void travese(){
    for(int i = 1;i<=::size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    travese();
}