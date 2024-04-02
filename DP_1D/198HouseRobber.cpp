#include "..\Solution.h"
/*
int maxRobberies(int firstHouse, vector<int>& nums, vector<int>& cache)
{
    if (firstHouse >= nums.size())
        return 0;
    if (cache[firstHouse] != -1)
        return cache[firstHouse];

    int max1 = nums[firstHouse] + maxRobberies(firstHouse + 2, nums, cache);
    int max2 = maxRobberies(firstHouse + 1, nums, cache);
    int res = std::max(max1, max2);;
    cache[firstHouse] = res;
    return res;
}

int Solution::rob(vector<int>& nums)
{
    vector<int> cache(nums.size(), -1);
    return maxRobberies(0, nums, cache);
}*/

int Solution::rob(vector<int>& nums)
{
    vector<int> cache(nums.size());
    int n = nums.size();
    cache[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int sum1 = nums[i] + (i + 2 <= n - 1 ? cache[i + 2] : 0);
        int sum2 = cache[i + 1];
        cache[i] = std::max(sum1, sum2);
    }
    return cache[0];
}