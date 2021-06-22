using namespace std;
//O(nlogn) time | O(h) space 
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
void helper(BinaryTree *node, int depth, int &sum){
	if(node->left){
		helper(node->left, depth+1, sum);
	}
	sum+=depth;
	if(node->right){
		helper(node->right, depth+1, sum);
	}
}
void helper2(BinaryTree *root, int &sum){
	if(root->left){
		helper2(root->left, sum);
	}
	helper(root, 0, sum);
	if(root->right){
		helper2(root->right,sum);
	}
}
int allKindsOfNodeDepths(BinaryTree *root) {
  int sum = 0;
	helper2(root,sum);
  return sum;
}
