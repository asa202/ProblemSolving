using namespace std;
class BST{
	public:
		int val;
		int leftCounter;
		BST* left;
		BST* right;
		BST(int v,int lc){
			this->val = v;
			this->leftCounter = lc;
			left = nullptr;
			right = nullptr;
		}

		void insert(int v,int &ret){
			BST *node= new BST(v,0);
			BST *temp = this;
			BST *parent = this;
			bool flagR = false;
			bool flagL = false;
			ret = 0;
			while(temp!=nullptr){
				parent = temp;
				if(v < temp->val){
					temp->leftCounter +=1;
					temp = temp->left;
					flagL = true;
					flagR = false;
				}
				else{
					ret += temp->leftCounter;
					if(v != temp->val){
						ret +=1;
					}
					temp = temp->right;
					flagL = false;
					flagR = true;
				}
			}
			if(flagL){
				parent->left = node;
			}else{
				parent->right = node;
			}
		}
};

vector<int> rightSmallerThan(vector<int> array) {
	if(array.size() == 0){
		return {};
	}
	vector<int> retV(array.size(),0);
	int last = array.size()-1;
	BST *bst = new BST(array[last],0);
	for(int i=array.size()-2; i>= 0 ;i--){
		int ret = 0;
		bst->insert(array[i],ret);
		retV[i] = ret;
	}
  return retV;
}
