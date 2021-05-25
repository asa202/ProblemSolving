using namespace std;
//O(n)time | O(n)space
// This is the class of the input root. Do not edit it.
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
void recursiveHelper(BinaryTree *tree, int currSumBranch, vector<int> &ret ){
	currSumBranch += tree->value;
	if(tree->left){
		recursiveHelper(tree->left, currSumBranch, ret );
	}
	if(tree->right){
		recursiveHelper(tree->right, currSumBranch, ret );
	}
	if(tree->left == nullptr && tree->right == nullptr){
		ret.push_back(currSumBranch);
	}
}

vector<int> branchSums(BinaryTree *root) {
  // Write your code here.
	vector<int> ret{};
	recursiveHelper(root,0,ret);
  return ret;
}
