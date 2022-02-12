#include <bits/stdc++.h>
using namespace std;

bool sameStructure(Node* root1, Node* root2){
	if(!root1 && !root2) return true;
	if((root1 && !root2) || ((!root1 && root2))) return false;
	if(!isSameStructure(root1->left,root2->left)) return false;
	if(!isSameStructure(root1->right,root2->right)) return false;
	return true;
}