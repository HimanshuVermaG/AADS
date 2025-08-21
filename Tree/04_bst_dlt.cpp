#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
    node (int d){
        data = d;
        left = right = NULL;
    }
};

node *insert(node *root, int d){
    if(!root){
        root = new node(d);
        return root;
    }

    else{
        if(d<root->data){
            root->left = insert(root->left,d);
        }
        else{
            root->right = insert(root->right,d);
        }
        return root;
    }
}
void postTrvs(node* n){
    if(!n){
        return;
    }
    else{
        cout << n->data << " ";
        postTrvs(n->left);
        postTrvs(n->right);
    }
}

node *dltNode(node *root, int trgt){
    if(!root){
        return NULL;
    }
    if(root->data == trgt){
        
    }
    else{
        return root;
    }
}

int main(){
    int arr[] = {6,3,17,5,11,18,2,1,20,14};
    int s = sizeof(arr)/sizeof(arr[0]);
    node *root = NULL;
    for(int i=0; i<s; i++){
        root = insert(root,arr[i]);
    }
    postTrvs(root);
}