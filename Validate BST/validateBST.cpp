#include <algorithm> 
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};
//O(n) time and O(d) space
bool validateHelper(BST *tree, int min, int max){
	if(min > tree->value || max <= tree->value){
		return false;
	}
	if(tree->left){
		if(tree->value > tree->left->value ){
			if(!validateHelper(tree->left,min,std::min(tree->value,max))){
				return false;
			}
		}else{
			return false;
		}
	}
	if(tree->right){
		if(tree->value <= tree->right->value ){
			if(!validateHelper(tree->right,std::max(tree->value,min),max)){
				return false;
			}
		}else{
			return false;
		}
	}
  return true;
}
bool validateBst(BST *tree) {
  // Write your code here.
	if(tree!=nullptr){
		int min = INT_MIN;
		int max = INT_MAX;
		return validateHelper(tree, min, max);
	}
  return true;
}
