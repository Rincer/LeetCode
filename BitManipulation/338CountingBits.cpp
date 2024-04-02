#include "..\Solution.h"

vector<int> Solution::countBits(int n)
{
    vector<int> res(n + 1, 0);
    for (int i = 0; i <= n; i++)
        res[i] = res[i >> 1] + (i & 1); // number of 1s in the upper bits except for rightmost bit has already been calculated 
    return res;
}