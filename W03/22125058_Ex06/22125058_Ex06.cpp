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
    bool isUnivalTree(TreeNode* root) {
        bool ok = true;
        if (root->left){
            if (root->left->val != root->val) ok = false;
            else ok &= isUnivalTree(root->left);
        }
        if (root->right){
            if (root->right->val != root->val) ok = false;
            else ok &= isUnivalTree(root->right);
        }
        return ok;
    }
};