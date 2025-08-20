#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    struct node *left , *right;
    node (int k){
        data = k;
        left = right = NULL;
    }
};
//Build Tree
node* bldNode(node* n){
    int data;
    cin >> data;
    n = new node(data);

    if (data == -1){
        return NULL;
    }
    cout << "Left child of :"<< data << endl;
    n->left = bldNode(n->left);
    cout << "Right child of :"<< data << endl;
    n->right = bldNode(n->right);
    return n;
}
// Level Order Traversal of Tree
void bfs(node* n){
    queue <node*> q;
    q.push(n);
    q.push(NULL); // seperator- denoting no more node after that in that lvl
    node *temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if (temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL); //seperator
            }
        }
        else{
            cout<< temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main(){
    // data = 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node *n = NULL;
    cout << "Enter Root node:" <<endl;
    n = bldNode(n);
    bfs(n);
    return 0;
}