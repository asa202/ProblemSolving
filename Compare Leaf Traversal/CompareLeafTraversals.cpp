using namespace std;
//O(n+m) time | O(max(h1, h2)) space
// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};
void helper(BinaryTree *tree, BinaryTree * &rightMost){
	if(tree->left){
		helper(tree->left, rightMost);
	}
	if(tree->right){
		helper(tree->right, rightMost);
	}
	if(!tree->left && !tree->right){
		if(rightMost){
			tree->left = rightMost;
		}
		rightMost = tree;
	}
}
bool compareLeafTraversal(BinaryTree *tree1, BinaryTree *tree2) {
  // Write your code here.
	BinaryTree* rightMost1 = nullptr;
	BinaryTree* rightMost2 = nullptr;
	
	helper(tree1, rightMost1);
	helper(tree2, rightMost2);
	
	if(rightMost1 && rightMost2){
		while(rightMost1 && rightMost2){
			if(rightMost1->value == rightMost2->value){
				rightMost1 = rightMost1->left;
				rightMost2 = rightMost2->left;
			}else{
				return false;
			}
		}
		if(rightMost1 || rightMost2){
			return false;
		}
	}else{
		if(rightMost1 || rightMost2){
			return false;
		}
	}
  return true;
}
