#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void add_at_last(node* head,int data){
    if (head == NULL){
        cout<<"The linked list is empty";
    }else{
        node* ptr = head;
        node* temp = new node;
        temp->data = data;
        temp->next = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

node* add_at_beg(node*& head,int data){
    node*temp = new node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
        return head;
    }else{
        temp->next = head;
        head = temp;
        return head;
    }
}

node* add_at_any(node*& head, int data,int position){
    node*temp = new node;
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return head;
    }else{
        node*ptr = head;
        int count=0;
        while(ptr!=NULL){
            count++;
            if (count == position-1){
                temp->next = ptr->next;
                ptr->next = temp;
                break;
            }
            ptr = ptr->next;
        }
        return head;
    }
    return head;
}

void traverse(node*head){
    node*ptr = head;
    while (ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
int main(){
    int data,option;
    string choice;
    node*head = NULL;
    do
    {
        cout<<"Pick you choice = \n1).Insert at Beginning\n2).Insert at end\n3).Insert at any Position\n";
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Enter the data that you want to insert = ";
            cin>>data;
            add_at_beg(head,data);
            traverse(head);
            break;
        case 2:
            cout<<"Enter the data that you want to insert = ";
            cin>>data;
            add_at_last(head,data);
            traverse(head);
            break;
        case 3:
            int position;
            cout<<"Enter the data that you want to insert = ";
            cin>>data;
            cout<<"Enter the position in which you want the element to be = ";
            cin>>position;
            add_at_any(head,data,position);
            traverse(head);
            break;
        default:
            cout<<"Wrong choice! Try again";
            break;
        }
        cout<<"Want to add another element?(y/n)=";
        cin>>choice;
    } while (choice == "y");
    while (head!=NULL)
    {
        node*temp = head;
        head = head->next;
        delete temp;
    }
}