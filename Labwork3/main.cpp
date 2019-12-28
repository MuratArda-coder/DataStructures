#include <iostream>
#include <cstdlib>
#include "genBST.h"

using namespace std;

template<class T>
void BST<T>::findNumberSmallerThan(int value,BSTNode<T>* p)
{
	if (p != 0 && p->el<=value) {
         findNumberSmallerThan(value,p->left);
         visit(p);
         findNumberSmallerThan(value,p->right);
     }
}


/*print numbers smaller than the given value in ascending order */
template<class T>
void BST<T>::findNumberSmallerThan(int value)
{
	cout<<endl;
	findNumberSmallerThan(value,root);
	cout<<endl;
}


template<class T>
void BST<T>::findNthSmallest(int count,int N,BSTNode<T>* p)
{
	if (p != 0) { 
	        findNthSmallest(count+1,N,p->left);
		findNthSmallest(count+1,N,p->right);
		if(N==count)
			visit(p);
	}
	

			
}

/*print Nth smallest number */
template<class T>
void BST<T>::findNthSmallest(int N)
{
	cout<<endl;
	findNthSmallest(0,N,root);
	cout<<endl;
	
}


template<class T>
int BST<T>::findNumberOfParentsWhoHasTwoChildren(BSTNode<T>* p) {
	if(p!=0){
		if(p->right!=0 && p->left!=0)
			return findNumberOfParentsWhoHasTwoChildren(p->right)+findNumberOfParentsWhoHasTwoChildren(p->left)+1;
		else
			return findNumberOfParentsWhoHasTwoChildren(p->right)+findNumberOfParentsWhoHasTwoChildren(p->left);
	}
	else
		return 0;

}

/* return number of parents that has two children */
template<class T>
int BST<T>::findNumberOfParentsWhoHasTwoChildren()
{

	return findNumberOfParentsWhoHasTwoChildren(root);

}



int main()
{
	BST<int> tree;
	tree.insert(20);
	tree.insert(10);
	tree.insert(30);
	tree.insert(5);
	tree.insert(3);
	tree.insert(25);
	tree.insert(35);

	tree.inorder();
	tree.findNumberSmallerThan(25);
	tree.findNthSmallest(3);

	cout<<"number of parents who have two children: "<<tree.findNumberOfParentsWhoHasTwoChildren()<<endl;
}

