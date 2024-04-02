#include "..\Solution.h"

int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    struct
    {
        bool operator()(vector<int>& a, vector<int>& b) const { return a[0] < b[0]; }
    }
    customLess;
    std::sort(intervals.begin(), intervals.end(), customLess);
    int end = intervals[0][1];  // intervals are sorted so only use the end to check for overlap
    int answ = 0;
    for (int nextIndex = 1; nextIndex < intervals.size(); nextIndex++)
    {
        // overlap
        if (end > intervals[nextIndex][0])
        { 
            answ++;
            end = min(end, intervals[nextIndex][1]); // which interval to drop?
            // 2 cases:
            //   ------------end
            //          ------------------
            //
            //  -------------------------------end
            //          ------------------
            //
            // in the 1st case we drop the 2nd interval because it has greater chance to overlap with something else
            // in the 2nd case we drop the 1st interval because it has greater chance to overlap with something else
        }
        else
        {
            end = intervals[nextIndex][1];
        }
    }
    return answ;
}