#include "..\Solution.h"

string Solution::mergeAlternately(string word1, string word2)
{
    string result;
    result.reserve(word1.length() + word2.length());
    if (word1.length() < word2.length())
    {
        int i = 0;
        for (; i < word1.length(); i++)
        {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        for (; i < word2.length(); i++)
        {
            result.push_back(word2[i]);
        }
    }
    else
    {
        int i = 0;
        for (; i < word2.length(); i++)
        {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        for (; i < word1.length(); i++)
        {
            result.push_back(word1[i]);
        }
    }
    return result;
}
