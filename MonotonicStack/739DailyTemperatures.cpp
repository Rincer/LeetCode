#include "..\Solution.h"

vector<int> Solution::dailyTemperatures(vector<int>& temperatures)
{
    vector<int> res(temperatures.size(), 0);
    struct dayTemp
    {
        int day;
        int temp;
        dayTemp(int d, int t)
        {
            day = d;
            temp = t;
        }
    };
    vector<dayTemp> stack;
    stack.push_back(dayTemp(0, temperatures[0]));
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!stack.empty() && (temperatures[i] > stack.back().temp))
        {
            res[stack.back().day] = i - stack.back().day;
            stack.pop_back();
        }
        stack.push_back(dayTemp(i, temperatures[i]));
    }
    return res;
}