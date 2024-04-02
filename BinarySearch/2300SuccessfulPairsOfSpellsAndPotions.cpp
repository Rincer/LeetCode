#include "..\Solution.h"

int returnFirstHigherOrEqualIndex(vector<int>& potions, int key)
{
    int upper = potions.size() - 1;
    int lower = 0;
    bool found = false;
    while (!found)
    {
        if (key == potions[lower])
            return lower;
        if (key == potions[upper])
            return upper;                
        int middle = (upper + lower) / 2;
        if ((middle == lower) || (middle == upper))
            return upper;
        if (key >= potions[middle])
            lower = middle;
        else if (key <= potions[middle])
            upper = middle;
    }
    return 0;
}

vector<int> Solution::successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
{
    vector<int> pairs(spells.size(), 0);
    int n = spells.size();
    int m = potions.size();

    std::sort(potions.begin(), potions.end());
    for (int i = 0; i < spells.size(); i++)
    {
        int key = success / spells[i];
        if (key <= potions[m - 1])
        {
            if (key <= potions[0])
            {
                pairs[i] = m;
            }
            else
            {
                int index = returnFirstHigherOrEqualIndex(potions, key);
                pairs[i] = m - index - 1;
            }
        }
    }
    return pairs;
}