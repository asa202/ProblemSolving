#include <vector>
using namespace std;
//O(n) time and O(d) space
// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value);
};

void helper(BinaryTree* node, BinaryTree* &rightMost){
	if(node->left){
		helper(node->left, rightMost);
	}
	if(rightMost){
		node->left = rightMost;
		rightMost->right = node;
	}
	rightMost = node;
	if(node->right){
		helper(node->right, rightMost);
	}
		
}

BinaryTree *flattenBinaryTree(BinaryTree *root) {
	BinaryTree* rightMost = nullptr;
 	helper(root, rightMost);
	if(rightMost){
		while(rightMost->left){
			rightMost = rightMost->left;
		}
	}
  return rightMost;
}
