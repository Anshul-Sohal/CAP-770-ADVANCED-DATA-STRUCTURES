#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
void traverse(){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(8);
    traverse();
}