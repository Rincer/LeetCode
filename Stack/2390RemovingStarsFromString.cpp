#include "..\Solution.h"

string Solution::removeStars(string s)
{
    string res;
    if (!s.empty())
        res.push_back(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if ((s[i] == '*') && (res.back() != '*'))
        {
            res.pop_back();
        }
        else
        {
            res.push_back(s[i]);
        }
    }
    return res;
}