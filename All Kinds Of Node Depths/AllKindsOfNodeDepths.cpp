using namespace std;
//If Balanced : O(n) time | O(h) space
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
	int localSum = (depth*(depth+1))/2;
	sum+=localSum;
	if(node->right){
		helper(node->right, depth+1, sum);
	}
}

int allKindsOfNodeDepths(BinaryTree *root) {
  int sum = 0;
	helper(root,0,sum);
  return sum;
}
