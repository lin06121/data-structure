#include"Binarytree.h"
#include<iostream>
template<class DATA>
void Bitree<DATA>::cleartree(Bitreenode<DATA>* node)
{if(node)
  {cleartree(node->left);
   cleartree(node->right);
   delete node;
  }
}
template<class DATA>
bool Bitree<DATA>::insertLeft(Bitreenode<DATA>* node,const DATA& data)
{  if(node==nullptr||node->left!=nullptr)
     return false;
     node->left=new Bitreenode<DATA>(data);
     ++size;
     return true;
}
template<class DATA>
bool Bitree<DATA>::insertRight(Bitreenode<DATA>* node,const DATA& data)
{  if(node==nullptr||node->right!=nullptr)
     return false;
     node->right=new Bitreenode<DATA>(data);
     ++size;
     return true;
}
template<class DATA>
void Bitree<DATA>::removeRight(Bitreenode<DATA>* node)
{if(node&&node->right)
  cleartree(node->right);
  node->right=nullptr;
}
template<class DATA>
void Bitree<DATA>::removeLeft(Bitreenode<DATA>* node)
{if(node&&node->left)
  cleartree(node->left);
  node->left=nullptr;
}
template<class DATA>
Bitree<DATA>* Bitree<DATA>::merge(Bitree* leftTree,Bitree* rightTree,const DATA& rootdata )
{Bitree* newtree=new Bitree();
 newtree->root=new Bitreenode<DATA>(rootdata);
 newtree->root->left=leftTree->root;
 newtree->root->right=rightTree->root;
 
 newtree->size=leftTree->size+rightTree->size+1;
 leftTree->root=nullptr;
 rightTree->root=nullptr;
 
 return newtree;
}


