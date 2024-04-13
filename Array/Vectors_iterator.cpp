#include<iostream>
#include<vector>
using namespace std;

vector<int>arr;

int main(){
    for (int i = 1; i <= 5; i++){
        arr.push_back(i);
    }
    cout<<"The elements in the array are:";
    for(auto i = arr.begin();i!=arr.end();i++){
        cout<<*i<<" ";
    }
}