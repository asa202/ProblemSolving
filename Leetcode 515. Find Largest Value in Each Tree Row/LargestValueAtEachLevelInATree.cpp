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

// Second Solution and Better in Space Complexity 
// C++ program to find largest
// value on each level of binary tree.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
struct Node {
    int val;
    struct Node *left, *right;
};

/* Recursive function to find
the largest value on each level */
void helper(vector<int>& res, Node* root, int d)
{
    if (!root)
        return;

    // Expand list size
    if (d == res.size())
        res.push_back(root->val);

    else

        // to ensure largest value
        // on level is being stored
        res[d] = max(res[d], root->val);

    // Recursively traverse left and
    // right subtrees in order to find
    // out the largest value on each level
    helper(res, root->left, d + 1);
    helper(res, root->right, d + 1);
}

// function to find largest values
vector<int> largestValues(Node* root)
{
    vector<int> res;
    helper(res, root, 0);
    return res;
}

/* Helper function that allocates a
new node with the given data and
NULL left and right pointers. */
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver code
int main()
{
    /* Let us construct a Binary Tree
        4
    / \
    9 2
    / \ \
    3 5 7 */

    Node* root = NULL;
    root = newNode(4);
    root->left = newNode(9);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(7);
    
    vector<int> res = largestValues(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
        
    return 0;
}
