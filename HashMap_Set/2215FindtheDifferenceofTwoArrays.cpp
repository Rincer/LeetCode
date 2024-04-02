#include "../Solution.h"

vector<vector<int>> Solution::findDifference(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> list1;
    vector<int> list2;
    vector<vector<int>> res;
    bool* set1 = new bool[2001];    // -1000 to 1000 including 0
    bool* set2 = new bool[2001];    // -1000 to 1000 including 0
    memset(set1, 0, 2001 * sizeof(bool));
    memset(set2, 0, 2001 * sizeof(bool));
    for (int i = 0; i < nums1.size(); i++)
    {
        set1[nums1[i] + 1000] = true;
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        set2[nums2[i] + 1000] = true;
    }

    for (int i = 0; i < 2001; i++)
    {
        if ((set1[i]) && (!set2[i]))
        {
            list1.push_back(i - 1000);
        }
        if ((!set1[i]) && (set2[i]))
        {
            list2.push_back(i - 1000);
        }

    }

    res.push_back(list1);
    res.push_back(list2);
    delete[] set1;
    delete[] set2;
    return res;
}