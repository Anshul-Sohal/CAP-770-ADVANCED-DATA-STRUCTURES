#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements one by one:";
    for(int i = 0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The array is:\n";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    int position, number;
    cout<<"\nEnter the number that you want to insert int the array =";
    cin>>number;
    cout<<"Enter the position of the number that you want to insert =";
    cin>>position;
    for(int i = size-2;i>=position-1;i--){
        arr[i+1]=arr[i];
    }
    arr[position-1] = number;
    cout<<"The updated array is:";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
