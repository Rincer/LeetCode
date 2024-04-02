#include "..\Solution.h"

int Solution::orangesRotting(vector<vector<int>>& grid)
{
    struct coords
    {
        int row, col;
    };
    std::queue<coords> q;
    int rows = grid.size();
    int cols = grid[0].size();
    bool freshOranges = false;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 2)
            {
                q.push({row, col});
                grid[row][col] = 0;
            }
            if (grid[row][col] == 1)
                freshOranges = true;
        }
    }

    // edge case no fresh oranges
    if (freshOranges == false)
        return 0;

    if (q.empty())
        return -1;

    int minutes = 0;

    while (!q.empty())
    {
        minutes++;
        int queueSize = q.size();
        for (int iteration = 0; iteration < queueSize; iteration++)
        {
            coords loc = q.front();
            q.pop();
            if ((loc.row - 1 >= 0) && (grid[loc.row - 1][loc.col] == 1))
            {
                grid[loc.row - 1][loc.col] = 0;
                q.push({ loc.row - 1,loc.col });
            }
            if ((loc.row + 1 < rows) && (grid[loc.row + 1][loc.col] == 1))
            {
                grid[loc.row + 1][loc.col] = 0;
                q.push({ loc.row + 1,loc.col });
            }
            if ((loc.col - 1 >= 0) && (grid[loc.row][loc.col - 1] == 1))
            {
                grid[loc.row][loc.col - 1] = 0;
                q.push({ loc.row,loc.col - 1 });
            }
            if ((loc.col + 1 < cols) && (grid[loc.row][loc.col + 1] == 1))
            {
                grid[loc.row][loc.col + 1] = 0;
                q.push({ loc.row,loc.col + 1 });
            }
        }
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 1)
            {
                return -1;
            }
        }
    }
    return minutes - 1;
}