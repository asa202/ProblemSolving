using namespace std;

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
//O(n) time | O(h)

int nodeDepths(BinaryTree *root, int depth = 0) {
  // Write your code here.
	int depthLeft = 0 ; int depthRight = 0;
	if(root->left){
		depthLeft = nodeDepths(root->left, depth + 1);
	}
	if(root->right){
		depthRight = nodeDepths(root->right, depth + 1);
	}
	
  return depth + depthLeft + depthRight;
}
