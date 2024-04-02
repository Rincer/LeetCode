#include "..\Solution.h"

int Solution::uniquePaths(int m, int n)
{
    uint32_t* map = new uint32_t[m * n];
    memset(map, 0, m * n * sizeof(uint32_t));

    // all squares on bottom row have a single path to get to the exit
    // initialize bottom row to 1
    uint32_t offset = (m - 1) * n;
    for (int col = 0; col < n; col++)
    {
        map[offset + col] = 1;
    }
    // all squares on right column have a single path to get to the exit
    // initialize right column to 1
    offset = n - 1;
    for (int row = 0; row < m; row++)
    {
        map[offset + row * n] = 1;
    }
    
    for (int row = m - 2; row >= 0; row--)
    {
        for (int col = n - 2; col >= 0; col--)
        {
            map[row * n + col] += (map[(row + 1) * n + col] + map[row * n + col + 1]);
        }
    }
    uint32_t res = map[0];
    delete[] map;
    return res;
}