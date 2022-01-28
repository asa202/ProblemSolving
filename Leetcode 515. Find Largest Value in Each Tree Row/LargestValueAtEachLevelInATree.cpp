/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        if(!root){
            return {};
        }
        vector<int> ret;
        vector<TreeNode*> currLevel{root};
        vector<TreeNode*>nextLevel;
        int max ;
        do{
            max = INT_MIN;
           while(!currLevel.empty()){
                TreeNode* node = currLevel.back();
                if(max<node->val){
                    max = node->val;
                }
                currLevel.pop_back();
                if(node->right){
                    nextLevel.push_back(node->right);
                }
                if(node->left){
                    nextLevel.push_back(node->left);
                }
            }
            ret.push_back(max);
            currLevel = nextLevel;
            nextLevel = {};
        }while(!currLevel.empty());
        
        return ret;
    }
};