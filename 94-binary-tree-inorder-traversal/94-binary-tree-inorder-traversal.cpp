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
    void help(TreeNode *root, vector<int>&h){
        if(root==NULL){
            return;
        }
        help(root->left,h);
        h.push_back(root->val);
        help(root->right,h);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> h;
        help(root,h);
        return h;
    }
};