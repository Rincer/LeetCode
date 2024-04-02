#include "..\Solution.h"

/*
void rightSide(vector<int>& res, vector<TreeNode*>& level)
{
    if (level.empty())
        return;
    res.push_back(level.back()->val);
    vector<TreeNode*> nextLevel;
    for (int i = 0; i < level.size(); i++)
    {
        if (level[i]->left != nullptr)
            nextLevel.push_back(level[i]->left);
        if (level[i]->right != nullptr)
            nextLevel.push_back(level[i]->right);
    }
    rightSide(res, nextLevel);
}

vector<int> Solution::rightSideView(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    vector<TreeNode*> level;
    level.push_back(root);
    rightSide(res, level);
    return res;
}
*/

vector<int> Solution::rightSideView(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    TreeNode* nodes[1000];
    int start = 0;
    int nodeCount = 1;
    nodes[0] = root;    
    // Flatten the tree, problem constraints guarantee less than 1000 nodes
    while (nodeCount > 0)
    {
        res.push_back(nodes[start + nodeCount - 1]->val);        
        int nextStart = start + nodeCount;
        int end = start + nodeCount;
        for (; start < end; start++)
        {
            if (nodes[start]->left != nullptr)
            {
                nodes[nextStart] = nodes[start]->left;
                nextStart++;
            }
            if (nodes[start]->right != nullptr)
            {
                nodes[nextStart] = nodes[start]->right;
                nextStart++;
            }
        }
        nodeCount = nextStart - end;
    }
    return res;
}