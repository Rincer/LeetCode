#include "Solution.h"

TreeNode* BuildTree(uint8_t s[], int size)
{
    std::queue<TreeNode*> q;
    TreeNode* root = nullptr;
    if (size > 0)
    {
        TreeNode* node = new TreeNode(s[0]);
        root = node;
        q.push(node);
    }
    int i = 1;
    while (i < size)
    {
        TreeNode* node = q.front();
        q.pop();
        if (s[i] != 255)
        {
            TreeNode* newNode = new TreeNode(s[i]);
            node->left = newNode;
            q.push(newNode);
        }
        i++;
        if (i == size)
        {
            break;
        }
        if (s[i] != 255)
        {
            TreeNode* newNode = new TreeNode(s[i]);
            node->right = newNode;
            q.push(newNode);
        }
        i++;
    }
    return root;
}