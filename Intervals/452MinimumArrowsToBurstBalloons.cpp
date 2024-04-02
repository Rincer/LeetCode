#include "..\Solution.h"



int Solution::findMinArrowShots(vector<vector<int>>& points)
{
    struct
    {
        bool operator()(vector<int>& a, vector<int>& b) const { return a[0] < b[0]; }
    } customLess;

    std::sort(points.begin(), points.end(), customLess);
    int count = 1;
    int arrow = points[0][1];
    for (int i = 0; i < points.size(); i++)
    {
        if (points[i][0] > arrow)
        {
            count++;
            arrow = points[i][1];
        }
        else
        {
            if (points[i][1] < arrow)
            {
                arrow = points[i][1];
            }
        }
    }    
    return count;
}