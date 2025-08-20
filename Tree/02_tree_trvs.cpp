#include<iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int k){
        data = k;
        left = right = NULL;
    }
};

node* bldNode(node* n){
    int d;
    cin >> d;
    n = new node(d);
    if (d == -1){
        return NULL;
    }
    else{
        cout << "Enter left child of: "<< d <<endl;
        n->left = bldNode(n->left);
        cout << "Enter right child of: "<< d <<endl;
        n->right = bldNode(n->right);
    }
    return n;
}
void preTrvs(node* n){
    if (n == NULL){
        return;
    }
    else{
        cout << n->data << " ";
        preTrvs(n->left);
        preTrvs(n->right);
    }
}

void inoTrvs(node* n){
    if (n==NULL){
        return;
    }
    else{
        inoTrvs(n->left);
        cout << n->data << " ";
        inoTrvs(n->right);
    }
}

void postTrvs(node* n){
    if(n == NULL){
        return;
    }
    else{
        postTrvs(n->left);
        postTrvs(n->right);
        cout << n->data << " ";
    }
}
int main(){
    // data = 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node *n = NULL;
    cout << "Enter root node data: " << endl;
    n = bldNode(n);
    preTrvs(n);
    cout<<"- Preorder"<<endl;
    inoTrvs(n);
    cout<<"- Inorder"<<endl;
    postTrvs(n);
    cout<<"- Postorder"<<endl;
    return 0;
}