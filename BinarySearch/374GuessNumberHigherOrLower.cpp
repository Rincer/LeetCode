#include "..\Solution.h"

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0 
 */

const int kPickedNumber = 2;

int guess(int num)
{
    if (num < kPickedNumber)
        return 1;
    if (num > kPickedNumber)
        return -1;
    return 0;
}


int Solution::guessNumber(int n)
{
    int l = 1;
    int h = n;
    int pick;
    while (true)
    {
        if (guess(l) == 0)
            return l;
        if (guess(h) == 0)
            return h;
        pick = h / 2 + l / 2;
        int res = guess(pick);
        if (res == 0)
            return pick;

        if (res == -1)
            h = pick;
        else
            l = pick;
    }
}