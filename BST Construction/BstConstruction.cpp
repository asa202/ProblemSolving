#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST &insert(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.
		BST* curr = this;
		if(curr == nullptr){
			BST *root = new BST(val);
			curr = root;
		}else{
			BST* par = curr;
			while(curr!=nullptr){
				par = curr;
				if(curr->value <= val){
					curr = curr->right;
				}else{
					curr = curr->left;
				}
			}
			if(par->value <= val){
				par->right = new BST(val);
			}else{
				par->left = new BST(val);
			}
		}
    return *this;
  }

  bool contains(int val) {
    // Write your code here.
		BST* curr = this;
		while(curr!=nullptr){
			if(val == curr->value){
				return true;
			}else if(val > curr->value){
				curr = curr->right;
			}else{
				curr = curr->left;
			}
		}
    return false;
  }

  BST &remove(int val) {
    // Write your code here.
    // Do not edit the return statement of this method.
		BST* curr = this;
		BST* parCurr = curr;
		while(curr!= nullptr){
			if(curr->value == val){
				break;
			}else if(curr->value < val){
				parCurr = curr;
				curr = curr->right;
			}else{
				parCurr = curr;
				curr = curr->left;
			}
		}
		if(curr!=nullptr && curr->value == val){
			if(curr->right!= nullptr){
				BST* temp = curr->right;
				BST* parTemp = curr;
				while(temp->left!=nullptr){
					parTemp = temp;
					temp = temp->left;
				}
				curr->value = temp->value;
				if(curr->right->value == temp->value){
					if(temp->right == nullptr){
						curr->right = nullptr;
						temp = nullptr;
					}else{
						curr->right = temp->right;
						temp = nullptr;
					}
				}else{
					parTemp->left =nullptr;
					temp = nullptr;
				}
			}else{
				if(curr->left!=nullptr){
					if(parCurr->value == curr->value){
						while(curr->left!=nullptr){
							curr->value = curr->left->value;
							parCurr = curr;
							curr = curr->left;
						}
						parCurr->left = nullptr;
					}else{
						parCurr->left = curr->left;
						curr = nullptr;
					}
				}else{
					if(parCurr->right!= nullptr && parCurr->right->value == curr->value){
						parCurr->right = nullptr;
					}else{
						parCurr->left = nullptr;
						curr = nullptr;
					}
				}
			}
		}
    return *this;
  }
};
