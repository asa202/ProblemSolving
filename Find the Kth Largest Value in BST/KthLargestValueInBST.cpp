using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};
//O(h+k) time and O(h) space
void helper(BST *tree, int k , int &counter, int &k_value){
	if(tree->right!=nullptr){
		helper(tree->right,k,counter,k_value);
	}
	counter++;
	if(k == counter){
		k_value = tree->value;
		return;
	}
	if(tree->left!=nullptr){
		helper(tree->left,k,counter,k_value);
	}
}
int findKthLargestValueInBst(BST *tree, int k) {
	int k_value = 0 ;
	int counter = 0;
  helper(tree,k,counter, k_value);
	return k_value;
}
