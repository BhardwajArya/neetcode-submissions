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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        //res.push_back(root->val);
        while(!q.empty()){
            TreeNode* r = nullptr;
            int qlen = q.size();
            for(int i=0; i<qlen; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    r=node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(r){
                res.push_back(r->val);
            }
        }
        return res;
    }
};
