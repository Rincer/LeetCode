#include "..\Solution.h"

class SmallestInfiniteSet {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    bool isInQueue[10001];
public:
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            q.push(i);
            isInQueue[i] = true;
        }
    }

    int popSmallest()
    {
        int res = q.top();
        isInQueue[res] = false;
        q.pop();
        return res;
    }

    void addBack(int num)
    {
        if (!isInQueue[num])
        {
            isInQueue[num] = true;
            q.push(num);
        }
    }
};
