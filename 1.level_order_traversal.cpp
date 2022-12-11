#include <iostream>
#include<queue>
using namespace std;
class Node{
  public: int data;
  Node* left;
Node* right;
Node(int data){
  this->data = data;
  this->left=NULL;
  this->right = NULL;
}
};
Node* createTrees(Node* root){
  int data;
  cout<<"Enter the value you want to enter into the root"<<endl;
  cin>>data;
  root = new Node(data);
if(data == -1){
  return NULL;
}
  cout<<"enter the value you want to enter to the left of"<<data<<endl;
    root->left = createTrees(root->left);
  cout<<"enter the value you want to enter to the right of"<<data<<endl;
  root->right = createTrees(root->right);
  return root;
}

//level order traversal
void traverse(Node* &root){
  queue<Node*> q;

  q.push(root);
  q.push(NULL);
  while(!q.empty()){
      Node* temp = q.front();
    
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

int main() {
  Node* root = NULL;
  //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  root = createTrees(root);
  //level order traversal
  //traverse(root);
  cout<<"in order traversal"<<" :";
  inorder(root);
  cout<<endl;
  cout<<"pre order traversal"<<" :";
  preorder(root);
  cout<<endl;
  cout<<"post order traversal"<< ": ";
  postorder(root);
  cout<<endl;
  
}

