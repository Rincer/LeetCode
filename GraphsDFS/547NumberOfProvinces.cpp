#include "..\Solution.h"

int Solution::findCircleNum(vector<vector<int>>& isConnected) // N x N
{
    int n = isConnected.size();
    std::queue<int> q;
    int numProvinces = 0;
    int visited[200] = {};
    for (int row = 0; row < n; row++)
    {
        if (!visited[row])
        {
            numProvinces++;
            q.push(row);
            while (!q.empty())
            {
                int city = q.front();
                q.pop();
                visited[city] = 1;
                for (int col = 0; col < n; col++)
                {
                    if ((isConnected[city][col]) && !visited[col])
                    {                        
                        q.push(col);
                    }
                }
            }
        }
    }
    return numProvinces;
}