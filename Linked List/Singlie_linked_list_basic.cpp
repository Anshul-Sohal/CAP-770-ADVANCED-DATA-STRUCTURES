#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

struct node* create_node(node*& head,int data){
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
        return temp;
    }else{
        node* ptr = head;
        while (ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;        
        return head;
    }
}

void traverse(node* head){
    node* ptr = head;
    while (ptr!=NULL){
        cout<<ptr->data<<" ";    
        ptr = ptr->next;
    }
}

int main(){
    int data;
    string choice;
    node* head = NULL;
    do{
        cout<<"Enter the data that you want to insert into the linked list = ";
        cin>>data;
        create_node(head,data);
        cout<<"Do you want to add another element?(y/n)=";
        cin>>choice;
    } while (choice == "y");
    cout<<"The linked list that you created is :\n";
    traverse(head);
    while(head!= NULL){
        node*temp = head;
        head = head->next;
        delete temp;
    }    
    return 0;
}
