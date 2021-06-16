#include <vector>
using namespace std;
//O(n) time and O(n) space;
// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value);
};
void helper(BinaryTree *root, vector<int> &array){
	if(root->left){
		helper(root->left, array);
	}
	array.push_back(root->value);
	if(root->right){
		helper(root->right, array);
	}
}
BinaryTree *flattenBinaryTree(BinaryTree *root) {
  // Write your code here.
	vector<int> array;
	helper(root, array);
	BinaryTree *left = new BinaryTree(array[0]);
	BinaryTree *leftMost = left;
	BinaryTree *right;
	for(int i = 0 ; i < array.size()-1 ; i++){
		right = new BinaryTree(array[i+1]);
		left->right = right;
		right->left = left;
		left = right;
		right = right->right;
	}
  return leftMost;
}
