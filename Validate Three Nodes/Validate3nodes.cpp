using namespace std;
//O(h) time and O(1) space ,where h is the height of tree
// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};
bool contains(BST* tree, BST* node){
	BST* temp = tree;
	while(temp!=nullptr){
		if(node->value < temp->value){
			temp = temp->left;
		}else if(node->value > temp->value){
			temp = temp->right;
		}else{
			return true;
		}
	}
	return false;
}
bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
  // Write your code here.
	bool OneAncOfTwo = contains(nodeOne, nodeTwo);
	bool ThreeAncOfTwo = contains(nodeThree, nodeTwo);
	if(OneAncOfTwo){
		return contains(nodeTwo, nodeThree);
	}
	if(ThreeAncOfTwo){
		return contains(nodeTwo, nodeOne);;
	}
  return false;
}
