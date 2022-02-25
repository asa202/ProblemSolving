#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

  BinaryTree(int value, BinaryTree *parent = nullptr);
  void insert(vector<int> values, int i = 0);
};
//O(n) time and O(1) space
void iterativeInOrderTraversal(BinaryTree *tree,
                               void (*callback)(BinaryTree *tree)) {
	 BinaryTree * previousNode = nullptr;
	BinaryTree * currentNode = tree;
	while(currentNode != nullptr){
		if(currentNode->left && currentNode->left!=previousNode && currentNode->right!=previousNode){
			previousNode = currentNode;
			currentNode = currentNode->left;
		}else{
			if(currentNode->right == previousNode){
				if(previousNode == nullptr){
					(*callback)(currentNode);
					return;
				}
				previousNode = currentNode;
				currentNode = currentNode->parent;
			}else{
				(*callback)(currentNode);
				if(currentNode->right){
					previousNode = currentNode;
					currentNode = currentNode->right;
				}else{
					if(previousNode->right == currentNode){
						currentNode = previousNode->parent;
					}
					else if(currentNode->left == previousNode){
						previousNode = currentNode;
						currentNode = currentNode->parent;
					}
					else if(previousNode->left == currentNode ){
						currentNode = previousNode;
						previousNode = previousNode->left;
					}
				}
			}
		}
	}
}
