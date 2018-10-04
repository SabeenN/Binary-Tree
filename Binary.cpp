#include "Binary.h"



// Takes a ref. of the pointer to the root node and inserts a new node containing data, based on the key's value
void insert(Node * & p, int key, double data){
  if (p==NULL){
     Node * n= new Node(key,data,NULL,NULL);
     p=n;
  }else if (key < p->key){
    if (p->left==NULL){
      Node * n1= new Node(key,data,NULL,NULL);
      p->left=n1;
    }else{
      insert(p->left, key, data);
    }
  }else if(key > p->key){
    if (p->right==NULL){
      Node * n2= new Node(key,data,NULL,NULL);
      p->right=n2;
    }else{
      insert(p->right,key,data);
    }
  }else if(key==p->key){
    p->data=data;
  }
}

//Removes a node with key value key from the tree
void remove(Node * & p, const int & key){
  if (p==NULL){
    throw std::out_of_range("Key not found!");
  }
  if (key < p->key){
    remove(p->left,key);
  }else if (key >p->key){
    remove(p->right,key);
  }else if (key==p->key){
    if(p->left==NULL && p->right==NULL){
      delete p;
      p = NULL;
    }
    else if(p->left==NULL){
      Node * oldd=p;
      p=p->right;
      delete oldd;
    }
    else if(p->right==NULL){
      Node * old=p;
      p=p->left;
      delete old;
    }else{
        Node* temp = getMax(p->left);
        int ktemp=temp->key;
        double dtemp=temp->data;
        p->key=ktemp;
        p->data=dtemp;
        remove(p->left,ktemp);
    }
  }
}

//Finds the node with the highest key value, i.e. the rightmost node
Node * getMax (Node * p){
  if (p == NULL){
    return NULL;
  }
  while (p->right != NULL){
    p=p->right;
  }
  return p ;
}

//prints the tree in post order format
void printPostorder(Node * p)
{
    if(p != NULL)
    {
        printPostorder(p->left);
        std::cout << (p->key) << std::endl;
        printPostorder(p->right);
    }
}

//Finds the node containing the data equal to argument val and returns the content of the node
const double & find(Node * p, const int & val){
  const double &data =0;
  while (p!=NULL){
    if (val < p->key){
        p = p->left;
    }else if (val > p->key){
      p=p->right;
    }else if(val==p->key){
    return p->data;
    }
  }
  throw std::out_of_range("Key not found!");
  return data;
}

//Returns editable data of a node
double & edit(Node * p, const int & val){
  double data = 0;
  while (p!=NULL){
    if (val < p->key){
        p = p->left;
    }else if (val > p->key){
      p=p->right;
    }else if(val == p->key){
      return p->data;
    }
  }
  throw std::out_of_range("Key not found!");
  return data;
}

//Deletes the entire tree
void delete_tree(Node * & p){
  if (p != NULL){
    if(p->left==NULL && p->right==NULL){
      delete p;
      p=NULL;
    }else if(p->left==NULL){
      Node * oldd=p;
      p=p->right;
      delete oldd;
      oldd=NULL;
    }
    else if(p->right==NULL){
      Node * old=p;
      p=p->left;
      delete old;
      old=NULL;
    }else{
    delete_tree(p->left);
    delete_tree(p->right);
    delete p;
    p=NULL;
    }
  }
}

//Returns the maximun depth of the tree
unsigned int max_height(Node * p){
  if (p==NULL){
      return 0;
  }else{
      /* compute the depth of each subtree */
      unsigned int lheight = max_height(p->left);
      unsigned int rheight= max_height(p->right);

      /* use the larger one */
      if (lheight > rheight){
          return(lheight+1);
      }else{
        return(rheight+1);
      }
   }
}

//Resturn the minimun depth of the tree
unsigned int min_height(Node * p){
  if (p == NULL)
   {
       return 0;
   }
   unsigned int lheight= min_height(p->left);
   unsigned int rheight= min_height(p->right);
   if (lheight < rheight){
       return(lheight+1);
   }else {
     return(rheight+1);
   }
}

//Returns the number of nodes in the tree
unsigned int size(Node *  p){
  unsigned int count =0;

  while (p !=NULL){
    if (p->left == NULL && p->right==NULL){
      ++count;
      p=p->left;
    }else if(p->left == NULL){
      count += 1;
      p=p->right;
    }else if(p->right == NULL){
      count += 1;
      p=p->left;
    }else{
      ++count;
      count += size(p->left);
      count += size(p->right);
      p=NULL;
    }
  }
  return count;
}

//Checks if the tree is balanced
bool is_balanced(Node * p){
  unsigned int min=min_height(p);
  unsigned int max=max_height(p);
  if ((max-min) <= 1 ){
    return true;
  }else{
    return false;
  }
}
