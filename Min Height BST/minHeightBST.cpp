using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};
//O(n) time | O(n) space
BST *helper(vector<int> array, int start, int end, BST* tree){
	if(start <= end){
		int index = (start+end)/2;
		tree = new BST(array[index]);
		tree->left = helper(array,start,index-1, tree->left);
		tree->right = helper(array,index+1,end, tree->right);
		return tree;
	}
	return nullptr;
}

BST *minHeightBst(vector<int> array) {
  // Write your code here.
	BST* root;
	if(array.size() == 0){
		return nullptr;
	}else{
		BST* root = new BST(array[array.size()/2]);
		root->left = helper(array,0,array.size()/2-1, root->left);
		root->right = helper(array,array.size()/2+1,array.size()-1, root->right);
		return root;
	}
  return root;
}
