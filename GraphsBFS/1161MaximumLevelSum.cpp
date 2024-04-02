#include "..\Solution.h"

int Solution::maxLevelSum(TreeNode* root)
{
    std::queue<TreeNode*> q;
    int nodeCount = 1;
    int max = root->val;
    int level = 1;
    int levelCount = 1;
    q.push(root);

    while (!q.empty())
    {
        int sum = 0;
        int nextNodeCount = 0;
        for (int i = 0; i < nodeCount; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            sum = sum + node->val;
            if (node->left)
            {
                q.push(node->left);
                nextNodeCount++;
            }
            if (node->right)
            {
                q.push(node->right);
                nextNodeCount++;
            }
        }
        nodeCount = nextNodeCount;
        if (sum > max)
        {
            max = sum;
            level = levelCount;
        }
        levelCount++;
    }
    return level;
}