#include <cstdlib>
using namespace std;
//O(n) time | O(h) space
// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

int helper(BinaryTree *tree, bool &flag){
	int left = 0; int right = 0;
	if(tree->left){
		left = helper(tree->left, flag);
		if(left == -1){
			return -1;
		}
	}
	if(tree->right){
		right = helper(tree->right, flag);
		if(right == -1){
			return -1;
		}
	}
	if(!tree->left && !tree->right){
		return 1;
	}else{
		if(abs(left-right) > 1){
			flag = false;
			return -1;
		}else{
			return std::max(left,right)+1;
		}
	}
}

bool heightBalancedBinaryTree(BinaryTree *tree) {
	bool flag = true;
	helper(tree, flag);
  return flag;
}
