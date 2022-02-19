#include <cmath>
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  // Write your code here.
	if(tree == NULL){
		return -1;
	}
	int closest  = tree->value;
	while(tree!= NULL){
		closest = abs(tree->value - target) < abs(closest - target) ? tree->value : closest;
		if(tree->value < target){
			tree = tree->right;
		}
		else if(tree->value > target){
			tree = tree->left;
		}else{
			return target;
		}
	}
  return closest;
}
