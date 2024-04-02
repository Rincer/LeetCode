#include "..\Solution.h"

bool IsDivisor(string str1, string str2)
{
    if ((str2.length() % str1.length()) != 0)
        return false;
    int ratio = str2.length() / str1.length();
    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < ratio; j++)
        {
            if (str1[i] != str2[j * str1.length() + i])
                return false;
        }
    }
    return true;
}

string Solution::gcdOfStrings(string str1, string str2)
{    
    string res;
    for (int i = 1; i <= str1.length() / 2 + 1; i++)
    {
        res = "";
        for (int j = 0; j < str1.length() / i; j++)
        {
            res.push_back(str1[j]);            
        }
        if (IsDivisor(res, str1) && IsDivisor(res, str2))
            return res;
    }
    return "";
}