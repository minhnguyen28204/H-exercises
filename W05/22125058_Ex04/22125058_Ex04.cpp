/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void dfs(TreeNode* cur, vector<int> &arr){
    if (cur){
        dfs(cur->left,arr);
        arr.push_back(cur->val);
        dfs(cur->right,arr);
    }
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> arr;
    dfs(A,arr);
    return arr[B-1];
}
