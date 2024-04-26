#include<iostream>
using namespace std;
int factorial(int num){
    if(num == 1){
        return 1;
    }else{
        return num * (factorial(num-1));
    }
}
int main(){
    int number;
    cout<<"Enter the number to which you want to find the factorial for = ";
    cin>>number;
    cout<<factorial(number);
}