#include "..\Solution.h"


void buildLeafNodeArray(TreeNode* root, uint8_t* array, int& length)
{
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        array[length] = root->val;
        length++;
        return;
    }
    if (root->left != nullptr)
    {
        buildLeafNodeArray(root->left, array, length);
    }
    if (root->right != nullptr)
    {
        buildLeafNodeArray(root->right, array, length);
    }
}

bool Solution::leafSimilar(TreeNode* root1, TreeNode* root2)
{
    // Iterate through root1 and build an array of leaf nodes
    uint8_t array[200];
    int length = 0;
    buildLeafNodeArray(root1, array, length);

    uint8_t array1[200];
    int length1 = 0;
    buildLeafNodeArray(root2, array1, length1);
    if (length != length1)
        return false;

    for (int i = 0; i < length; i++)
    {
        if (array[i] != array1[i])
            return false;
    }
    return true;
}