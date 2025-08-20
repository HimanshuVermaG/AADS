#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;

    node (int k){
        data = k;
        left = right = NULL;
    }
};

node *insert(node *root,int d){
    // Base case
    if(!root){
        node *temp = new node(d);
        return temp;
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

void inorder(node* root){
    if (!root){
        return;
    }
    else{
        cout<< root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
}

void preorder(node *root){
    if(!root){
        return;
    }
    else{
        preorder(root->left);
        cout<< root->data << " ";
        preorder(root->right);
    }
}

void postorder(node* root){
    if(!root){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        cout<< root->data << " ";
    }
}

bool search(node* root, int trgt){
    if(!root){
        return 0;
    }
    else{
        if (trgt == root->data){
            return 1;
        }
        else if (trgt<root->data){
            return search(root->left,trgt);
        }
        else if(trgt>root->data){
            return search(root->right,trgt);
        }
        else{
            return 0;
        }
    }
}

int main(){
    int arr[]= {6,3,17,5,11,18,2,1,20,14};
    int trgt = 0;
    bool found;
    node *root = NULL;
    int s = sizeof(arr)/sizeof(arr[0]);
    for (int i =0;i<s;i++){
        root = insert(root,arr[i]);
    }
    inorder(root);
    cout<<"- Inorder"<<endl;
    preorder(root);
    cout<<"- Preorder"<<endl;
    postorder(root);
    cout<<"- Postorder"<<endl<<endl;

    cout<< "Enter the data to search"<<endl;
    cin >> trgt;

    found = search(root,trgt);
    if(found == 1){
        cout << "Targate found!!!";
    }
    else if (found == 0){
        cout << "Targate not found!!!";
    }

}

