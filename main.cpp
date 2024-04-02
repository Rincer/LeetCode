#include <stdlib.h>
#include <stdio.h>
#include "Solution.h"

Solution solution;

int main(void)
{
    vector<vector<int>> v = { {10, 16} ,{2, 8},{1, 6},{7, 12} };
    int res = solution.findMinArrowShots(v);
    return 0;
}
