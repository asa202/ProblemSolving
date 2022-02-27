#include <vector>
using namespace std;
//O(n) time | O(d) space
// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value);
};

void helper(BinaryTree *node, BinaryTree *parent, bool leftFlag){
	BinaryTree* left = node->left;
	BinaryTree* right = node->right;
	if(left){
		helper(left, node, true);
	}
	if(!parent){
		node->right = nullptr;
	}else if(leftFlag){
		node->right = parent->right;
	}else{
		if(parent->right){
			node->right = parent->right->left;
		}else{
			node->right = nullptr;
		}
	}
	if(right){
		helper(right, node, false);
	}
}

BinaryTree *rightSiblingTree(BinaryTree *root) {
	bool leftFlag = false;
  helper(root, nullptr, leftFlag);
  return root;
}
