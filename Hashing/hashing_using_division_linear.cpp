#include<iostream>
using namespace std;
void hashing(int table[], int size){
    int data;
    cout<<"Enter a data to be added = ";
    cin>>data;

    int index = data%size;
    int start = index;

    while (table[index]!=-1){
        index = (index+1)%size;
        if (index == start){
            cout<<"Hash table is full, cannot insert more item"<<endl;
            return;
        }
    }
    table[index] = data;
    cout<<"The data of the hash table is following:"<<endl;
    for (int i = 0; i < size; i++){
        cout<<table[i]<<" ";
    }
    cout<<endl;    
}
int main(){
    const int TABLE_SIZE = 10;
    int table[TABLE_SIZE];
    fill(table,table+TABLE_SIZE,-1);
    int choice;
    do{
        cout<<"Enter 1 to add values in table, 2 to exit from the process: ";
        cin>>choice;
        switch (choice){
        case 1:
            hashing(table,TABLE_SIZE);
            break;
        case 2:
            cout<<"Exiting the program"<<endl;
            break;
        default:
            cout<<"Enter a valid choice"<<endl;
            break;
        }
    } while (choice!=2);
    return 0;
}