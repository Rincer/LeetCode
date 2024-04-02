#include "..\Solution.h"

TreeNode* Solution::searchBST(TreeNode* root, int val) 
{
    if (root == nullptr)
        return root;
    if (root->val == val)
        return root;
    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}
