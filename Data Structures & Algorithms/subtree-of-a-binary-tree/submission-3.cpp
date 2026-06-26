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
    bool match(TreeNode* r, TreeNode* sr){
        if(!r&&!sr)return true;
        if(!sr||!r)return false;
        if(r->val!=sr->val)return false;
        
        return match(r->left, sr->left)&&match(r->right, sr->right);
        
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;
        //if(!subRoot)return false;
        if(match(root, subRoot))return true;
        return isSubtree(root->left, subRoot)||isSubtree(root->right, subRoot);
    }
};
