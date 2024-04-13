#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the array=";
    cin>>size;
    int arr[size];
    cout<<"Enter the value of the array one by one =\n";
    for (int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cout<<"The array created by you is - \n";
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    
}