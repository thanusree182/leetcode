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
    void get(TreeNode* root,int targetSum,vector<int> help,vector<vector<int>> &ans){
       if(!root){
           return;
       }
        if(!root->left && !root->right && root->val==targetSum){
            help.push_back(root->val);
            ans.push_back(help);
            return;
        }
        help.push_back(root->val);
        get(root->left,targetSum-root->val,help,ans);
        get(root->right,targetSum-root->val,help,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans;
        get(root,targetSum,{},ans);
        return ans;
    }
};