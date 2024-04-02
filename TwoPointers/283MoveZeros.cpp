#include "..\Solution.h"

void Solution::moveZeroes(vector<int>& nums) 
{
    int zeroIndex = 0;
    int nonZeroIndex = 0;
    while (zeroIndex < nums.size())
    {
        if (nums[zeroIndex] == 0)
        {
            nonZeroIndex = max(nonZeroIndex, zeroIndex);
            while (nonZeroIndex < nums.size())
            {
                if (nums[nonZeroIndex] != 0)
                {
                    nums[zeroIndex] = nums[nonZeroIndex];
                    nums[nonZeroIndex] = 0;
                    break;
                }
                nonZeroIndex++;
            }
        }
        if (nonZeroIndex == nums.size())
            break;
        zeroIndex++;
    }
}