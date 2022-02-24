#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};
//O(n) time| O(logn)
int helper(BinaryTree* tree, int & max){
	int left ; int right ;
	if(tree->left){
		left = helper(tree->left, max);
	}
	if(tree->right){
		right = helper(tree->right, max);
	}
	int threeNodeSum ;int carrySumForward;int rightBranchSum ; int leftBranchSum;
	if(tree->left == nullptr && tree->right == nullptr){
		if(max < tree->value){
			max = tree->value;
		}
		return tree->value;
	}else{
		if(tree->left != nullptr && tree->right != nullptr){
			threeNodeSum = tree->value + right + left;
			rightBranchSum = tree->value + right;
			leftBranchSum = tree->value + left;
			carrySumForward = rightBranchSum > leftBranchSum ? rightBranchSum : leftBranchSum;
		}
		else if(tree->left){
			threeNodeSum = tree->value + left;
			carrySumForward = tree->value + left;
		}else{
			threeNodeSum = tree->value + right;
			carrySumForward = tree->value + right;
		}
	}
	if(max < threeNodeSum){
		max = threeNodeSum;
	}
	int BiggerNode = left > right ? left:right;
	if(BiggerNode > carrySumForward){
		if(max < BiggerNode){
			max = BiggerNode;
		}
	}else{
		if(max < carrySumForward){
			max = carrySumForward;
		}
	}
	if(carrySumForward < tree->value){
		if(max < tree->value){
			max = tree->value;
		}
		return tree->value;
	}else{
		return carrySumForward;
	}
}

int maxPathSum(BinaryTree tree) {
	int max = INT_MIN;
	helper(&tree, max);
	return max;
}
