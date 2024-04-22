#include<iostream>
using namespace std;
struct node{
    node* previous;
    int data;
    node* next;
};node*head = NULL;
void insert_at_end(int data){
    node*temp = new node;
    temp->data = data;
    temp->next = NULL;
    temp->previous = NULL;
    if(head == NULL){
        head = temp;
    }else{
        node*ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->previous = ptr;        
    }
}
void insert_at_beg(int data){
    node*temp = new node;
    temp->data = data;
    temp->previous = NULL;
    temp->next = head;
    head = temp;
}
void insert_at_any(int data,int position){
    node*temp = new node;
    temp->data = data;
    temp->previous = NULL;
    temp->next = NULL;
    if(position == 1){
        insert_at_beg(data);
    }else{
        int count = 0;
        node*ptr = head;
        while(count!=position-2){
            ptr = ptr->next;
            count++;
        }
        if(ptr->next == NULL){
            insert_at_end(data);
        }else{
            temp->next = ptr->next;
            ptr->next = temp;
            temp->previous = ptr;
            temp->next->previous = temp;
        }
    }
}
void traverse(){
    node*ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
int main(){
    for (int i = 0; i < 10; i++){
        insert_at_end(i);
    }
    traverse();
    insert_at_beg(9);
    cout<<endl;
    traverse();
    cout<<endl;
    insert_at_any(0,1);
    traverse();
    while (head!=NULL)
    {
        node*temp = head;
        head = head->next;
        delete temp;
    }
}