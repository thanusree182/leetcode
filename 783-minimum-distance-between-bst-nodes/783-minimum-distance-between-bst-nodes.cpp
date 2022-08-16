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
   void help(TreeNode* root, vector<int>&arr){
        if(root==NULL){
            return;
        }
        help(root->left,arr);
        arr.push_back(root->val);
        help(root->right,arr);
        
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        help(root,arr);
        int n=arr.size();
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               if(abs(arr[i]-arr[j])<min){
                   min=abs(arr[i]-arr[j]);
               }
            }
        }
        return min;
    }
};