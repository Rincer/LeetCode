#include "..\Solution.h"

double Solution::findMaxAverage(vector<int>& nums, int k)
{
    int first = 0;
    int last;
    double max = 0;
    // compute the sum of 1st k elements
    for (last = 0; last < k; last++)
    {
        max += nums[last];
    }
    double sum = max;
    while (last < nums.size())
    {
        // calculate new sum by subtracting 1st element and adding the next
        sum = sum - nums[first] + nums[last];
        max = std::max(max, sum);
        first++;
        last++;
    }
    return max / k;
}