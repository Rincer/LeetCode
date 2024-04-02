#include "../Solution.h"

int Solution::pivotIndex(vector<int>& nums)
{
    vector<int> sum;
    sum.resize(nums.size() + 1, 0);
    sum[0] = 0;
    for (int i = 1; i <= nums.size(); i++)
    {
        sum[i] = sum[i - 1] + nums[i - 1];
    }
    int totalSum = sum[nums.size()];

    for (int i = 1; i <= nums.size(); i++)
    {
        if ((sum[i - 1]) == (totalSum - sum[i]))
            return i - 1;
    }
    return -1;
}