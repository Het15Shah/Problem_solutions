#include <iostream>
#include <queue>
using namespace std;
class node{   //creating class for node
    public:
    int data;   //data part of node
    node* left;  //pointer to left child node
    node* right;  //pointer to right child node
    
    node(int d){   //constructor to initialize node
        this->data=d;    
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildtree(node* root){   //function to create binary tree
//function take pointer to parent node as parameter and return pointer to child node
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root=new node(data);  //creating new node
    if(data==-1){
        return NULL;
    }
    else{
        cout<<"Enter data for inserting in left of "<<data<<endl;
        root->left=buildtree(root);  // recursive call to make left node of binarytree
        cout<<"Enter data for inserting in right of"<<data<<endl;
        root->right=buildtree(root);  //recursive call to make right node of binarytree
        return root;
    }
}

void levelorderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(node* root){
     if(root==NULL){
        return;
    }
    else{
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
     if(root==NULL){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void buildfromlevelOrder(node* root){
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }

    }
}
int main(){
    node* root=NULL;
    buildfromlevelOrder(root);
    levelorderTraversal(root);
    //creating a tree
   /* root=buildtree(root);
    cout<<"printing the binary tree"<<endl;
    levelorderTraversal(root);
    cout<<"Inorder traversal"<<endl;
    inorder(root);
    cout<<"preorder traversal"<<endl;
    preorder(root);
    cout<<"postorder traversal"<<endl;
    postorder(root);
    */

    return 0;
}