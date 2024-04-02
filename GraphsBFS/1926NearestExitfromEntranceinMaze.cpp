#include "..\Solution.h"
#include <queue>

/* Solution using arrays
bool visited[100][100] = {};
int locations[2][10000][2];
int locationCounts[2] = {};

int Solution::nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
{        
    memset(visited, 0, 10000 * sizeof(bool));
    int m = maze.size();
    int n = maze[0].size();
    int pathLength = 0;
    int locationsBuffer = 0;
    locations[locationsBuffer][0][0] = entrance[0];
    locations[locationsBuffer][0][1] = entrance[1];
    visited[entrance[0]][entrance[1]] = true;
    locationCounts[locationsBuffer] = 1;
    do 
    {  
        locationCounts[1 - locationsBuffer] = 0;
        for (int i = 0; i < locationCounts[locationsBuffer]; i++)
        {
            int x = locations[locationsBuffer][i][0];
            int y = locations[locationsBuffer][i][1];
            if (maze[x][y] != '+')
            {
                if (!visited[x][y] && ((x == 0) || (x == m - 1) || (y == 0) || (y == n - 1)))
                    return pathLength;

                visited[x][y] = true;
                if ((x > 0) && !visited[x-1][y])
                {
                    locations[1 - locationsBuffer][locationCounts[1 - locationsBuffer]][0] = x - 1;
                    locations[1 - locationsBuffer][locationCounts[1 - locationsBuffer]][1] = y;
                    locationCounts[1 - locationsBuffer]++;
                }

                if ((y > 0) && !visited[x][y - 1])
                {
                    locations[1 - locationsBuffer][locationCounts[1 - locationsBuffer]][0] = x;
                    locations[1 - locationsBuffer][locationCounts[1 - locationsBuffer]][1] = y - 1;
                    locationCounts[1 - locationsBuffer]++;
                }

                if ((x + 1 < m) && !visited[x + 1][y])
                {
                    locations[1 - locationsBuffer][locationCounts[1 - locationsBuffer]][0] = x + 1;
                    locations[1 - locationsBuffer][locationCounts[1 - locationsBuffer]][1] = y;
                    locationCounts[1 - locationsBuffer]++;
                }

                if ((y + 1 < n) && !visited[x][y + 1])
                {
                    locations[1 - locationsBuffer][locationCounts[1 - locationsBuffer]][0] = x;
                    locations[1 - locationsBuffer][locationCounts[1 - locationsBuffer]][1] = y + 1;
                    locationCounts[1 - locationsBuffer]++;
                }
            }            
        }
        locationsBuffer = 1 - locationsBuffer;
        pathLength++;
    } while (locationCounts[locationsBuffer] > 0);

    return -1;
}
*/

// Solution using stl
int Solution::nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
{
    struct pos
    {
        int row;
        int col;
        pos(int r, int c)
        {
            row = r;
            col = c;
        }
    };
    int rows = maze.size();
    int cols = maze[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pos> q;
    int pathLength = 0;
    pos moves[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    q.push(pos(entrance[0], entrance[1]));
    visited[entrance[0]][entrance[1]] = true;
    while (!q.empty())
    {
        pathLength++;
        for (int i = q.size(); i > 0; i--)
        {
            pos p = q.front();            
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                pos p1(p.row + moves[j].row, p.col + moves[j].col);
                if ((p1.row >= 0) && (p1.row < rows) && (p1.col >= 0) && (p1.col < cols) && (!visited[p1.row][p1.col]) && (maze[p1.row][p1.col] != '+'))
                {
                    if ((p1.row == 0) || (p1.row == rows - 1) || (p1.col == 0) || (p1.col == cols - 1))
                    {
                        return pathLength;
                    }
                    else
                    {
                        visited[p1.row][p1.col] = true;
                        q.emplace(p1);
                    }
                }
            }
        }
    }    
    return -1;
}