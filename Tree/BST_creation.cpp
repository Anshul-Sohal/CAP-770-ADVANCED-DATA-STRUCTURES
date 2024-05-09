#include<iostream>
using namespace std;
struct node{
    node*leftchild;
    int data;
    node*rightchild;
};node*root = NULL;
node*create(node*root,int data){
    if(root == NULL){
        node*temp = new node;
        temp->data = data;
        temp->leftchild = NULL;
        temp->rightchild = NULL;
        return temp;
    }else{
        if(data<root->data){
            root->leftchild = create(root->leftchild,data);
        }else if(data>root->data){
            root->rightchild = create(root->rightchild,data);
        }
    }
    return root;
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
void destory_tree(node*root){
    if(root == NULL){
        return;
    }
    destory_tree(root->leftchild);
    destory_tree(root->rightchild);
    delete root;
}
int main(){
    root = create(root,99);
    root = create(root,67);
    root = create(root,45);
    root = create(root,34);
    root = create(root,78);
    root = create(root,69);
    cout<<"The elements stored inside the BST are (Inorder Traversing)"<<endl;
    inorder(root);
    destory_tree(root);
    root = NULL;
}