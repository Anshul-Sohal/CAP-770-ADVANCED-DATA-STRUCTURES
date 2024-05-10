#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void add_at_last(node* head,int data){
    if (head == NULL){
        std::cout<<"The linked list is empty";
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
node* add_at_any(node*& head, int data, int position){
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
        return head;
    }
    if (position == 1){
        temp->next = head;
        head = temp;
        return head;
    }
    node* ptr = head;
    int count = 1;
    while (ptr != NULL && count < position - 1){
        ptr = ptr->next;
        count++;
    }
    if (ptr == NULL){
        std::cout << "Position out of range" << endl;
        delete temp;
        return head;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}
void traverse(node*head){
    node*ptr = head;
    while (ptr!=NULL){
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    std::cout<<endl;
}
int main(){
    int data,option;
    string choice;
    node*head = NULL;
    do
    {
        std::cout<<"Pick you choice = \n1).Insert at Beginning\n2).Insert at end\n3).Insert at any Position\n";
        std::cin>>option;
        switch (option)
        {
        case 1:
            std::cout<<"Enter the data that you want to insert = ";
            std::cin>>data;
            add_at_beg(head,data);
            traverse(head);
            break;
        case 2:
            std::cout<<"Enter the data that you want to insert = ";
            std::cin>>data;
            add_at_last(head,data);
            traverse(head);
            break;
        case 3:
            int position;
            std::cout<<"Enter the data that you want to insert = ";
            std::cin>>data;
            std::cout<<"Enter the position in which you want the element to be = ";
            std::cin>>position;
            add_at_any(head,data,position);
            traverse(head);
            break;
        default:
            std::cout<<"Wrong choice! Try again";
            break;
        }
        std::cout<<"Want to add another element?(y/n)=";
        std::cin>>choice;
    } while (choice == "y");
    while (head!=NULL)
    {
        node*temp = head;
        head = head->next;
        delete temp;
    }
}