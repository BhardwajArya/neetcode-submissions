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
    int calculate(TreeNode* root){
        if(!root)return 0;
        int l = calculate(root->left);
        int r = calculate(root->right);
        return 1+max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int l = calculate(root->left);
        int r = calculate(root->right);
        if(abs(l-r)>1)return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};
