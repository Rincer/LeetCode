#include "..\Solution.h"

vector<string> map = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void solve(vector<string>& res, string& digits, string& builder, int level)
{
    if (level == builder.length())
    {
        res.push_back(builder);
        return;
    }
    int mapIndex = digits[level] - '2';
    for (int i = 0; i < map[mapIndex].size(); i++)
    {
        builder[level] = map[mapIndex][i];
        solve(res, digits, builder, level + 1);
    }
}

vector<string> Solution::letterCombinations(string digits)
{
    vector<string> res;
    if (digits.empty())
        return res;
    string builder(digits);
    solve(res, digits, builder, 0);
    return res;
}