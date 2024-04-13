#include<iostream>
#include<vector>
using namespace std;
int main(){
    //Syntax of declaring a vector "vector<DATA_TYPE>NAME_OF_VECTOR"
    vector<int>n;
    int size;
    cout<<"How many elements you want to insert into the array =";
    cin>>size;
    for (int i = 0; i < size; i++){
        int temp;
        cin>>temp;
        n.push_back(temp);
    }
    cout<<"The elements that you added are :";
    for (int i = 0; i < n.size(); i++){
        cout<<n[i]<<" ";
    }
}