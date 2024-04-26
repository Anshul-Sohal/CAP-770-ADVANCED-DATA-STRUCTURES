#include<iostream>
using namespace std;
struct node{
    node*leftchild;
    int data;
    node*rightchild;
};node*root = NULL;
//time complexity worst case(unbalanced):-O(n) best case(balanced):-O(logn)
node* create(node*root,int data){
    if(root == NULL){
        node*temp = new node;
        temp->data = data;
        temp->leftchild = NULL;
        temp->rightchild = NULL;
        return temp;
    }else if(data<root->data){
        root->leftchild = create(root->leftchild,data);
    }else if(data>root->data){
        root->rightchild = create(root->rightchild,data);
    }
    return root;
}
void search(node*root,int data){
    node*ptr = root;
    if(root == nullptr){
        cout<<"\nData not present in the tree";
        return;
    }
    if(data == root->data){
        cout<<"\nThe data is present in the tree";
    }else if(data<root->data){
        search(root->leftchild,data);
    }else if(data>root->data){
        search(root->rightchild,data);
    }
}
node* minValuenode(node*root){
    node*ptr = root;
    while(ptr && ptr->leftchild != NULL){
        ptr = ptr->leftchild;
    }
    return ptr;
}
node* deletenode(node*root,int data){
    if(root == NULL){
        return root;
    }else if(data<root->data){
        root->leftchild = deletenode(root->leftchild,data);
    }else if(data>root->data){
        root->rightchild = deletenode(root->rightchild,data);
    }else{
        if(root->leftchild == NULL){
            node*temp = root->rightchild;
            delete root;
            return temp;
        }else if(root->rightchild == NULL){
            node*temp = root->leftchild;
            delete root;
            return temp;
        }
        node*temp = minValuenode(root->rightchild);
        root->data = temp->data;
        root->rightchild = deletenode(root->rightchild,temp->data);
    }
    return root;
}
void preorder(node*root){
    if(root == NULL){
        return;
    }else{
        cout<<root->data<<" ";
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}
void postorder(node*root){
    if(root == NULL){
        return;
    }else{
    postorder(root->leftchild);
    postorder(root->rightchild);
    cout<<root->data<<" ";
    }
}
void inorder(node*root){
    if(root == NULL){
        return;
    }else{
    inorder(root->leftchild);
    cout<<root->data<<" ";
    inorder(root->rightchild);
    }
}
int main(){
    root = create(root,10);
    root = create(root,50);
    root = create(root,34);
    root = create(root,79);
    root = create(root,56);
    root = create(root,23);
    root = create(root,90);
    root = create(root,100);
    root = create(root,76);
    root = create(root,40);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    search(root,99);
    deletenode(root,100);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
}
