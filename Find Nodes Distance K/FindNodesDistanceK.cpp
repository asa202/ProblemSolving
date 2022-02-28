using namespace std;
//O(n) time | O(n) space
// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};
int helper(BinaryTree *tree,int target, int distance_root){
	if(target == tree->value){
		return distance_root;
	}
	if(tree->left){
		int ret =helper(tree->left, target, distance_root + 1);
		if(ret!=-1){
			return ret;
		}
	}
	if(tree->right){
		int ret =helper(tree->right, target, distance_root + 1);
		if(ret!=-1){
			return ret;
		}
	}
	return -1;
}
void getNodesAtDistanceK(BinaryTree *tree, int depth, int k, vector<int> & nodesAtDistK){
	if(!tree){
		return;
	}
	if(depth == k){
		nodesAtDistK.push_back(tree->value);
		return ; 
	}
	if(tree->left){
		getNodesAtDistanceK(tree->left, depth+1, k, nodesAtDistK);
	}
	if(tree->right){
		getNodesAtDistanceK(tree->right, depth+1, k, nodesAtDistK);
	}
}
vector<BinaryTree *> getParentsOfTarget(BinaryTree *tree, int target, vector<BinaryTree *> parents){
	if(tree->value == target){
		return parents;
	}else{
		parents.push_back(tree);
	}
	if(tree->left){
		vector<BinaryTree *> ret = getParentsOfTarget(tree->left, target, parents);
		if(ret.size()!=0){
			return ret;
		}
	}
	if(tree->right){
		vector<BinaryTree *> ret = getParentsOfTarget(tree->right, target, parents);
		if(ret.size()!=0){
			return ret;
		}
	}
	return {};
}
vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k) {
	vector<int> ret{};
  if(tree->value != target){
		vector<BinaryTree* > parents =  getParentsOfTarget(tree, target, {});
		BinaryTree* current = parents.back()->left && parents.back()->left->value == target ?
													parents.back()->left:parents.back()->right;
		getNodesAtDistanceK(current,0,k,ret);
		while(!parents.empty()){
			BinaryTree* parent = parents.back();
			parents.pop_back();
			k = k - 1;
			if(k==0){
				ret.push_back(parent->value);
				break;
			}
			if(parent->left == current){
				getNodesAtDistanceK(parent->right,0,k-1,ret);
			}
			else if(parent->right == current){
				getNodesAtDistanceK(parent->left,0,k-1,ret);
			}
			current = parent;
		}
	}else{
		getNodesAtDistanceK(tree,0,k,ret);
	}
  return ret;
}
