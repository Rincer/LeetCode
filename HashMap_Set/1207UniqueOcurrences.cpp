#include "..\Solution.h"

bool Solution::uniqueOccurrences(vector<int>& arr)
{
    vector<int> occurrences;
    occurrences.resize(2001, 0);
    vector<int> res;
    res.resize(1001, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        occurrences[arr[i] + 1000]++;
    }

    for (int i = 0; i < occurrences.size(); i++)
    {
        if (occurrences[i] > 0)
        {
            if (res[occurrences[i]] != 0)
                return false;
            res[occurrences[i]]++;
        }
    }
    return true;
}