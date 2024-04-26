#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i=low, j=high;
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quicksort(int arr[],int low, int high){
    if(low<high){
        int j = partition(arr,low,high);
        quicksort(arr,low,j);
        quicksort(arr,j+1,high);
    }
}
int main(){
    int size;
    cout<<"Enter the size of the array =";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements one by one-\n";
    for(int i = 0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"\nThe elements that you entered are-";
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nUsing quick sort to sort the array -"<<endl;;
    int low = 0, high = size - 1;
    quicksort(arr,low,high);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}