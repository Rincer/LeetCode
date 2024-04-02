#include "..\Solution.h"

int Solution::largestAltitude(vector<int>& gain)
{
    int alt = 0;
    int maxAlt = alt;
    for (int i = 0; i < gain.size(); i++)
    {
        alt += gain[i];
        maxAlt = std::max(maxAlt, alt);
    }
    return maxAlt;
}