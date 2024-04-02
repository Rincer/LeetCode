#include "..\Solution.h"

TreeNode* gParentNode;

TreeNode* findNode(TreeNode* root, TreeNode* parentNode, int key)
{
    if (root == nullptr)
    {
        gParentNode = parentNode;
        return nullptr;
    }

    if (root->val == key)
    {
        gParentNode = parentNode;
        return root;
    }

    TreeNode* node = findNode(root->left, root, key);
    if (node != nullptr)
        return node;

    node = findNode(root->right, root, key);
    return node;
}

TreeNode* Solution::deleteNode(TreeNode* root, int key)
{
    // find the node to delete
    TreeNode* searchNode = findNode(root, nullptr, key);    
    // remove the node
    if (searchNode == nullptr)
        return root;

    if (searchNode == root)
    {
        if ((searchNode->left == nullptr) && (searchNode->right == nullptr))
        {
            return nullptr;
        }

        if ((searchNode->left != nullptr) && (searchNode->right == nullptr))
        {
            return searchNode->left;
        }

        if ((searchNode->left == nullptr) && (searchNode->right != nullptr))
        {
            return searchNode->right;
        }
        TreeNode* node;
        for (node = searchNode->right; node->left != nullptr; node = node->left)
            ;
        node->left = searchNode->left;
        return searchNode->right;
    }
    else
    {
        if ((searchNode->left == nullptr) && (searchNode->right == nullptr))
        {
            if (gParentNode->left == searchNode)
                gParentNode->left = nullptr;
            if (gParentNode->right == searchNode)
                gParentNode->right = nullptr;
            return root;
        }

        if ((searchNode->left != nullptr) && (searchNode->right == nullptr))
        {
            if (gParentNode->left == searchNode)
            {
                gParentNode->left = searchNode->left;
            }

            if (gParentNode->right == searchNode)
            {
                gParentNode->right = searchNode->left;
            }
            return root;
        }

        if ((searchNode->left == nullptr) && (searchNode->right != nullptr))
        {
            if (gParentNode->left == searchNode)
            {
                gParentNode->left = searchNode->right;
            }

            if (gParentNode->right == searchNode)
            {
                gParentNode->right = searchNode->right;
            }
            return root;
        }

        TreeNode* node;
        for (node = searchNode->right; node->left != nullptr; node = node->left)
            ;
        node->left = searchNode->left;

        if (gParentNode->left == searchNode)
        {
            gParentNode->left = searchNode->right;
        }

        if (gParentNode->right == searchNode)
        {
            gParentNode->right = searchNode->right;
        }

        return root;
    }
}