#include<iostream>
using namespace std;
struct node{
    node*previous;
    int data;
    node*next;
};node*head = NULL;
void creation(int data){
    node*temp = new node;
    temp->data = data;
    temp->previous = NULL;
    temp->next = NULL;
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
void delete_at_end(){
    if(head == NULL){
        cout<<"The Linked List is empty";
    }else{
        if(head->next == NULL){
            delete head;
            head = NULL;
        }else{
            node*slowptr = head;
            node*fastptr = head->next;
            while (fastptr->next!=NULL)
            {
                slowptr = slowptr->next;
                fastptr = fastptr->next;
            }
            delete fastptr;
            slowptr->next = NULL;            
        }
    }
}
void delete_beg(){
    node*ptr = head;
    head = head->next;
    delete ptr;
    head->previous = NULL;
}
void delete_any(int position){
    if(position == 1){
        delete_beg();
    }else{
        node*ptr = head;
        for(int i = 0; i<position-2 && ptr!=nullptr;i++){
            ptr = ptr->next;
        }
        if(ptr == nullptr || ptr->next == nullptr){
            cout<<"Invalid Position"<<endl;
        }
        node* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
}
void traverse(){
    node*ptr = head;
    while (ptr!=NULL)
    {
        cout<<ptr->data;
        ptr = ptr->next;
    }
    cout<<endl;
}
int main(){
    for (int i = 0; i < 10; i++){
        creation(i);
    }
    cout<<endl;
    traverse();
    delete_beg();
    cout<<endl;
    traverse();
    delete_at_end();
    cout<<endl;
    traverse();
    delete_any(5);
    cout<<endl;
    traverse();
    while (head!=NULL)
    {
        node*temp = head;
        head = head->next;
        delete temp;
    }
}