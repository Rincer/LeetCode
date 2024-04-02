#include "..\Solution.h"


void findCombinations(vector<vector<int>>& res, vector<int>combination, int sum, int level, int start, int k, int n)
{
    if (level == k)
        return;
    for (int i = start; i <= 9; i++)
    {
        combination[level] = i;
        if (level == k - 1)
        {
            if (sum + i == n)
                res.push_back(combination);
        }
        else
        {
            findCombinations(res, combination, sum + i, level + 1, i + 1, k, n);
        }
    }
}

vector<vector<int>> Solution::combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> combination(k);
    findCombinations(res, combination, 0, 0, 1, k, n);
    return res;
}