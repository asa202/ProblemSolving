using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};
//O(n) time and O(n) space
BST* helper(int min, int max, vector<int> array ,int& idx){
	if(idx < array.size() && array[idx] >= min && array[idx] < max){
		int treeVal = array[idx];
		idx++;
		BST* left = helper(min, treeVal,array,idx);
		BST* right = helper(treeVal,max,array,idx);
		BST* tree = new BST(treeVal);
		tree->left = left;
		tree->right = right;
		return tree;
	}
	return nullptr;
}

BST *reconstructBst(vector<int> preOrderTraversalValues) {
  // Write your code here.
	int idx = 0;
	BST* tree = helper(INT_MIN, INT_MAX, preOrderTraversalValues, idx);
  return tree;
}
