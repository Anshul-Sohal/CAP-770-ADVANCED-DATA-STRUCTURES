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
    cout<<"The array is:";
    for(int i = 0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    int element,index_to_delete=0;
    cout<<"\nEnter the element that you want to delete=";
    cin>>element;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            index_to_delete = i;
            break;
        }
    }
    if (index_to_delete != -1) {
        for (int i = index_to_delete; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--; // Decrease the number of elements in the array
    } else {
        cout << "Element not found in the array." << endl;
    }
    cout<<"The updated array is: ";
    for(int i = 0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}