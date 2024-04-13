#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the array=";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements one by one:";
    for(int i = 0; i<size;i++){
        cin>>arr[i];
    }
    int element;
    cout<<"Enter the element that you want to search=";
    cin>>element;
    for(int i = 0; i<size;i++){
        if (arr[i] == element)
        {
            cout<<"Element found in the index number = "<<i;
        }
    }
}