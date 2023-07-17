/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * @input B : Root pointer of the tree 
 * 
 * @Output Integer
 */ 

int isSameTree(treenode* A, treenode* B) {
    if (A == NULL && B == NULL) return 1;
    if (A->val != B->val) return 0;
    int ok = 1;
    if (A->left && B->left) ok &= isSameTree(A->left,B->left);
    else if ((A->left && B->left == NULL) || (A->left == NULL && B->left)) ok = 0;
    if (A->right && B->right) ok &= isSameTree(A->right,B->right);
    else if ((A->right && B->right == NULL) || (A->right == NULL && B->right)) ok = 0;
    return ok;
}
