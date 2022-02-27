using namespace std;
//O(h) time | O(1) space
// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  // Write your code here.
	if(node->right){
		BinaryTree* right = node->right;
		if(right->left){
				while(right->left){
				right = right->left;
			}
		}
		return right;
	}else{
		if(node->parent){
			if(node->parent->left == node){
				return node->parent;
			}else{
				while(node->parent && node->parent->right == node){
					node = node->parent;
				}
				if(node->parent){
					return node->parent;
				}
			}
		}
	}
  return nullptr;
}
