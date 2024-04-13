#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
int main(){
    cout<<"Enter the numbers to the array one by one:";
    while (true)
    {
        int temp;
        string decision;
        cin>>temp;
        cout<<"Continue?(y/n)";
        cin>>decision;
        if (decision == "n"){
            break;
        }else{
            arr.push_back(temp);
        }
    }
    cout<<"The elements in the array are:\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }   
}