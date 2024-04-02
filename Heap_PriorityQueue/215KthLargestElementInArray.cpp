#include "..\Solution.h"
/*
int Solution::findKthLargest(vector<int>& nums, int k)
{
    vector<int> q;
    q.reserve(k);
    q.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        vector<int>::iterator j;
        for (j = q.begin(); j != q.end(); j++)
        {
            if (nums[i] > *j)
            {
                q.insert(j, nums[i]);
                break;
            }
        }
        if (j == q.end())
            q.push_back(nums[i]);
        if (q.size() > k)
        {
            q.pop_back();
        }
    }
    return q.back();
}
*/

int Solution::findKthLargest(vector<int>& nums, int k)
{
    // search area is the whole array
    int start = 0;
    int end = nums.size() - 1;

    // current candidate is the last element    
    int val = nums[end];

    // area to copy all elements greater than current candidate
    int greaterThanIndex = 0;

    while (true)
    {
        // put all numbers greater than or equal to the current candidate at the start of the search area.
        for (int i = start; i < end; i++)
        {
            if (nums[i] >= val)
            {
                swap(nums[i], nums[greaterThanIndex]);
                greaterThanIndex++;
            }
        }
        // copy the candidate to the end of the search area
        swap(nums[end], nums[greaterThanIndex]);
        greaterThanIndex++;

        int greaterThanAreaSize = greaterThanIndex - start;

        // current candidate the is Kth largest
        if (greaterThanAreaSize == k)
            return val;

        // There are more than k elements that are greater than current candidate, we need to find Kth largest
        // element of this area only since the rest of the elements are less than the candidate
        if (greaterThanAreaSize > k)
        {
            end = greaterThanIndex - 2; // previous candidate is at 'greaterThanIndex - 1', we know it is not the Kth largest   
            // start remains unchanged since we are searching the 'reduced' search are with a new candidate
            greaterThanIndex = start;
        }
        // we found less than k numbers that are greater than current candidate
        else
        {
            // end remains unchanged, because we are searching the remainder of the array 
            start = greaterThanIndex; // adjust the start of the new search area to point to after where the presvious candidate was copied to
            k -= greaterThanAreaSize; // remaining elements to find
        }
        val = nums[end];
    }
}