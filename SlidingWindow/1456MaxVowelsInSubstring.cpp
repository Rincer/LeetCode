#include "..\Solution.h"

bool isVowel(char c)
{
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

int Solution::maxVowels(string s, int k)
{
    int end = k - 1;
    int sum = 0;
    for (int i = 0; i <= end; i++)
    {
        if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u'))
            sum++;
    }
    end++;
    int tempSum = sum;
    while (end < s.size())
    {             
        if (isVowel(s[end]))
            tempSum++;
        if (isVowel(s[end - k]))
            tempSum--;
        sum = max(sum, tempSum);
        end++;
    }
    return sum;
}
