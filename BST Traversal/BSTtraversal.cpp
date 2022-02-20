#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
};
//O(n) time |O(n) space
void inOrderTraverse(BST *tree, vector<int> &array) {
  if(tree->left!=NULL){
		inOrderTraverse(tree->left, array);
	}
	array.push_back(tree->value);
	if(tree->right!=NULL){
		inOrderTraverse(tree->right, array);
	}
	
}

void preOrderTraverse(BST *tree, vector<int> &array) {
	array.push_back(tree->value);
  if(tree->left!=NULL){
		preOrderTraverse(tree->left, array);
	}
	if(tree->right!=NULL){
		preOrderTraverse(tree->right, array);
	}
}

void postOrderTraverse(BST *tree, vector<int> &array) {
  if(tree->left!=NULL){
		postOrderTraverse(tree->left, array);
	}
	if(tree->right!=NULL){
		postOrderTraverse(tree->right, array);
	}
	array.push_back(tree->value);
}
