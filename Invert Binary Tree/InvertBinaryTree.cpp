#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};
//O(n) time and O(h) space
void invertBinaryTree(BinaryTree *tree) {
  // Write your code here.
	if(tree->left){
		invertBinaryTree(tree->left);
	}
	if(tree->right){
		invertBinaryTree(tree->right);
	}
	BinaryTree *treeSwap = tree->left;
	tree->left = tree->right;
	tree->right = treeSwap;
}
