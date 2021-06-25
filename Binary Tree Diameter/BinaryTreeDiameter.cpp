using namespace std;
#include <algorithm> 
// This is an input class. Do not edit.
//Average : O(n) | O(h)
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int helper(BinaryTree *node ,int &max){
	int left = 0; int right = 0;
	if(node->left){
		left = helper(node->left, max);
	}
	if(node->right){
		right = helper(node->right, max);
	}
	if(!node->left && !node->right){
		if(max < 1){
			max = 1;
		}
		return 1;
	}else{
		if(node->left && node->right){
			if(left + right + 1 > max){
				max = left+right+1;
			}
		}
		if(max < std::max(left,right)+1){
				max = std::max(left,right)+1;
			}
		return std::max(left,right)+1;
	}
}
int binaryTreeDiameter(BinaryTree *tree) {
  // Write your code here.
	int max = 0;
	helper(tree,max);
	if(max>0){
		max -=1;
	}
  return max;
}
