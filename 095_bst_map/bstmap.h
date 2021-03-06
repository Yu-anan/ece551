#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<stdexcept>
#include"map.h"
template<typename K, typename V>
  class BstMap : public Map<K,V>{
 public:
  class Node {
  public:
    K key;
    V value;
    Node *left;
    Node *right;
  Node():key(0),value(0),left(NULL),right(NULL){}
  Node(const K &key,const V &type,Node *left,Node *right):key(key),value(type),left(left),right(right){}
    
  };
  Node *root;
 public:
 BstMap():root(NULL){}
 BstMap(const BstMap &rhs):root(NULL){root=copy(rhs.root);}
  Node * copy(Node * current){
    if(current==NULL)
      {
	return NULL;
      }
    
    Node * root = new Node(current->key,current->value,NULL,NULL);
    root->left=copy(current->left);
    root->right=copy(current->right); 
    return root;
  }
  
   
  void destroy(Node *t){
    if(t!=NULL){
      destroy(t->left);
      destroy(t->right);
      delete t;
    }
  }
  BstMap & operator= (const BstMap &rhs){
    if(this!= &rhs){
      destroy(root);
      root=copy(rhs.root);
    }
    return *this;
  }
  ~BstMap(){
    destroy(root);
    root=NULL;
  }
  virtual void add(const K & key,const V & value){
    Node ** current =&root;
    while((*current)!=NULL){
      if((*current)->key<key){
	current=&((*current)->right);
      }
      else if((*current)->key==key){
	(*current)->value=value;
	return ;
      }
      else{
	current=&((*current)->left);
      }
    }
    *current=new Node(key,value,NULL,NULL);
  }
  virtual const V & lookup(const K& key) const throw (std::invalid_argument){
    Node * current=root;
    while(current != NULL){
      if(current->key>key){
	current=current->left;
      }
      else if (current->key==key){
	return current->value;
      }
      else{
	current=current->right;
      }
    }
    throw std::invalid_argument("the key is not found");
  }
  virtual void remove(const K& key) {
    Node ** current=&root;
    Node * temp=NULL;
    while((*current)!=NULL){
      if((*current)->key==key){
        //check if it has two children                                                                                                                   
        if((*current)->left==NULL){
          temp=(*current)->right;
          delete *current;
          *current = temp;
          //current=&temp;                                                                                                                               
        }
        else if((*current)->right==NULL){
          temp=(*current)->left;
          delete *current;
          //current=&temp;                                                                                                                               
          *current = temp;
        }
        //it has two children          
         else{
          Node ** curr=current;
          curr=&(*curr)->left;
          
            while((*curr)->right!=NULL){
              curr=&(*curr)->right;
            }
            //change the value of current                                                                                                                
            (*current)->key=(*curr)->key;
            (*current)->value=(*curr)->value;
            temp=(*curr)->left;
            //record num                                                                                                                                 
            delete *curr;
            //curr = &temp;                                                                                                                              
            *curr=temp;
          
          
        }
      }
      else if((*current)->key<key){
        current=&(*current)->right;
      }
else{
        current=&(*current)->left;
      }
    }
  }



/*    void preorderprint(Node * root){
      if(root!=NULL){
	std::cout<<root->key<<" ";
	inorderprint(root->left);
	inorderprint(root->right);
      }
    }
    void preorder() {preorderprint(root);}
    */
  void inorder() { inorder_printer(root); }
  
  void inorder_printer(Node * root) {
    if (root != NULL) {
      inorder_printer(root->left);
      std::cout << root->key << " ";
      inorder_printer(root->right);
    }
  }
};
