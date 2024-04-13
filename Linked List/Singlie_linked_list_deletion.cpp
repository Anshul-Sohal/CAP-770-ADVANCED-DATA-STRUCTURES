#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;
};

node* create_node(node*& head, int data){
    node*temp = new node;
    temp->data = data;
    temp->next = NULL;
    if(head = NULL){
        head = temp;
        return head;
    }else{
        node*ptr = head;
        while (ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
        return head;
    }
}

node* delete_beg(node*&head){
    node*temp = head;
    head = temp->next;
    delete temp;
    return head;
}

void delete_end(node*head){
    
}
