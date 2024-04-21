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
    if(head == NULL){
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

node* delete_end(node*&head){
    if (head == NULL)
    {
        cout<<"The Linked List is empty";
    }else{
        if (head->next == NULL){
            delete head;
            head = NULL;
        }else{
            node*slowptr = head;
            node*fastptr = head->next;
            while (fastptr->next!=NULL){
                slowptr = slowptr->next;
                fastptr = fastptr->next;
            }
            delete fastptr;
            slowptr->next = NULL;    
        }
    }
    return head;
}

node* delete_any_position(node*& head, int position) {
    node* ptr = head;
    if(position == 1) {
        head = head->next;
        delete ptr;
    }else{
        for(int i = 0; i < position - 2 && ptr != nullptr; i++){
            ptr = ptr->next;
        }
        if(ptr == nullptr || ptr->next == nullptr){
            return head;
        }
        node* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
    return head;
}

void traverse(node*head){
    if (head == NULL){
        cout<<"\nLinked list is empty";
    }else{
        node*ptr = head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
    }
}
int main(){
    int data,option;
    string choice;
    node*head = NULL;
    do
    {
        cout<<"\nPick you choice =\n1).Create an Linked List\n2).Delete from Beginning\n3).Delete from end\n4).Delete from any Position\n";
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Enter the element you want to insert = ";
            cin>>data;
            create_node(head,data);
            traverse(head);
            cout<<"\nDo you want to add another element?(y/n)=";
            cin>>choice;
            break;
        case 2:
            cout<<"Linked list before the deletion =\n";
            traverse(head);
            delete_beg(head);
            cout<<endl<<"Linked list after the deletion =\n";
            traverse(head);
            break;
        case 3:
            cout<<"Linked list before the deletion =\n";
            traverse(head);
            delete_end(head);
            cout<<endl<<"Linked list after the deletion =\n";
            traverse(head);
            break;
        case 4:
            cout<<"Linked list before the deletion =\n";
            traverse(head);
            int position;
            cout<<"Enter the position of the element you want to delete =";
            cin>>position;
            delete_any_position(head,position);
            cout<<endl<<"\nLinked list after the deletion =\n";
            traverse(head);
            break;
        default:
            cout<<"Wrong Position!Try Again";
            break;
        }
    } while (choice == "y");
    while (head != NULL)
    {
        node*temp = head;
        head = temp->next;
        delete temp;
    }
    cout<<"\nMemory cleared";
    return 0;
}
