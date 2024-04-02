#include "../Solution.h"


void calculateCollisions(vector<int>& currStack, vector<int>& prevStack, bool& collision)
{
    currStack.clear();
    collision = false;
    for (int i = 0; i < prevStack.size(); i++)
    {
        if (currStack.empty())
            currStack.push_back(prevStack[i]);
        else
        {
            // current asteroid moving right, the one being considered moving left
            if ((currStack.back() > 0) && (prevStack[i] < 0))
            {
                collision = true;
                if (abs(prevStack[i]) == abs(currStack.back()))
                {
                    currStack.pop_back();
                }
                else
                {
                    if (abs(prevStack[i]) > abs(currStack.back()))
                    {
                        currStack.pop_back();
                        currStack.push_back(prevStack[i]);
                    }
                }
            }
            else
            {
                currStack.push_back(prevStack[i]);
            }
        }
    }
}

vector<int> Solution::asteroidCollision(vector<int>& asteroids)
{
    bool collision = false;
    vector<int> stack1;
    vector<int> stack2;
    vector<int>* pCurrStack;
    vector<int>* pPrevStack;
    pCurrStack = &stack1;
    pPrevStack = &stack2;

    calculateCollisions(stack1, asteroids, collision);

    while (collision)
    {
        vector<int>* pTempStack = pCurrStack;
        pCurrStack = pPrevStack;
        pPrevStack = pTempStack;
        calculateCollisions(*pCurrStack, *pPrevStack, collision);
    }
    return *pCurrStack;
}