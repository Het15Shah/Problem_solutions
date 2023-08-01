#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left,*right;
};

int het=0;
node* createnode(int d){
    node *temp= new node();
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
}




node* inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return root;
}

node* preorder(node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return root;
}

node* postorder(node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    return root;
}

node* insertion(node* root,int key){
    
   if(root==NULL){
    node* r=createnode(key);
    return r;
   }
   if(key<root->data){
    root->left=insertion(root->left,key);
   }
   else if(key>root->data){
    root->right=insertion(root->right,key);
   }
   return root;
    }

void levelorder(node* root){
    queue<node* > q;
    q.push(root);
    cout<<root->data<<" ";
    while(!q.empty()){
        root=q.front();
        q.pop();
        
        if(root->left){
            q.push(root->left);
            cout<<root->left->data<<" ";
        }
        if(root->right){
            q.push(root->right);
            cout<<root->right->data<<" ";
        }
    } 
    cout<<endl;
  
    } 

int height(node* p){
    if(!p){
        return 0;
    }
    int x=height(p->left);
    int y=height(p->right);
    
    
    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}
void leaf(node *p){
     
    if(p){
        
        if(p->left==NULL && p->right==NULL){
          het++;
        }
        leaf(p->left);
        leaf(p->right);
    }

}

node* inpre(node* p){
    if(p && p->left){
        p=p->left;
    }
    return p;
}

node* insuc(node* p){
    if(p && p->right){
        p=p->right;
    }
    return p;
}


node* deletion(node* root,int key){
    node* p;
    if(root==NULL){
        return NULL;
    }
    else if(root->left==NULL && root->right==NULL){
        p=root;
        root==NULL;
        free(p);
        return NULL;
    }
    if(key<root->data){
        root->left=deletion(root->left,key);
    }
    else if(key>root->data){
        root->right=deletion(root->right,key);
    }
    else{
        if(height(p->left)>height(p->right)){
            node* q=inpre(p->left);
            p->data=q->data;
            deletion(p->left,q->data);
        }
        else{
            node* q=insuc(p->right);
            p->data=q->data;
            deletion(p->right,q->data);
        }
    }
    return root;
}

int main(){
    node *root=NULL;
    root=insertion(root,2);
    root=insertion(root,1);
    root=insertion(root,3);
    root=insertion(root,4);
    levelorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    int h=height(root);
    cout<<h<<endl;
    leaf(root);
    cout<<het<<endl;
    root=deletion(root,3);
    levelorder(root);
    return 0;
}
