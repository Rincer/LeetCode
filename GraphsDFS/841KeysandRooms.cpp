#include "..\Solution.h"

void visit(int roomNumber, vector<vector<int>>& rooms, bool* visited, int* keys, int& numKeys, int& numVisited)
{
    for (int i = 0; i < rooms[roomNumber].size(); i++)
    {
        keys[numKeys] = rooms[roomNumber][i];
        numKeys++;        
    }
    visited[roomNumber] = true;
    numVisited++;
}

bool Solution::canVisitAllRooms(vector<vector<int>>& rooms) 
{   
    bool visited[1000];
    int keys[3000];
    int numKeys = 0;
    int numVisited = 0;
    memset(visited, 0, 1000 * sizeof(bool));
    visit(0, rooms, visited, keys, numKeys, numVisited);
    int keyIndex = 0;
    while (keyIndex < numKeys)
    {
        int key = keys[keyIndex];
        if (!visited[key])
        {
            visit(key, rooms, visited, keys, numKeys, numVisited);
            if (numVisited == rooms.size())
                return true;
        }
        keyIndex++;
    }
    return false;
}