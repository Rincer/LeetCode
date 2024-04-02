#include "..\Solution.h"

string Solution::predictPartyVictory(string senate)
{
    queue<char> q[2];
    int curr = 0;
    bool votes = false;
    for (int i = 0; i < senate.length(); i++)
    {
        q[curr].push(senate[i]);
    }

    do
    {
        q[1 - curr].push(q[curr].front());
        q[curr].pop();
        votes = false;
        int votesR = 0;
        int votesD = 0;
        if (q[1 - curr].front() == 'D')
            votesD++;
        else
            votesR++;
        while (!q[curr].empty())
        {
            if (q[curr].front() == 'D')
            {
                if (votesR > 0)
                {
                    votesR--;
                    votes = true;
                }
                else
                {
                    if (q[1 - curr].front() == 'R')
                    {
                        q[1 - curr].pop();                        
                        votes = true;
                    }
                    else
                    {
                        votesD++;
                    }
                    q[1 - curr].push('D');
                }
            }
            else
            {
                if (votesD > 0)
                {
                    votesD--;
                    votes = true;
                }
                else
                {
                    if (q[1 - curr].front() == 'D')
                    {
                        q[1 - curr].pop();                        
                        votes = true;
                    }
                    else
                    {
                        votesR++;
                    }
                    q[1 - curr].push('R');
                }
            }
            q[curr].pop();
        }
        curr = 1 - curr;
    } while (votes == true);   
    if (q[curr].front() == 'D')
        return "Dire";
    else
        return "Radiant";
}