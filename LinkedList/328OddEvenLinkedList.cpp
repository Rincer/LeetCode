#include "..\Solution.h"

ListNode* Solution::oddEvenList(ListNode* head)
{
    ListNode* oddList = nullptr;
    ListNode* evenList = nullptr;
    ListNode* firstEven = nullptr;
    
    bool odd = true;
    for (ListNode* iterator = head; iterator != nullptr; iterator = iterator->next)
    {
        if (odd)
        {
            if (oddList == nullptr)
                oddList = iterator;
            else
            {
                oddList->next = iterator;
                oddList = iterator;
            }
            odd = false;
        }
        else
        {
            if (evenList == nullptr)
            {
                evenList = iterator;
                firstEven = iterator;
            }
            else
            {
                evenList->next = iterator;
                evenList = iterator;
            }
            odd = true;
        }
    }
    if (oddList != nullptr)
        oddList->next = firstEven;
    if (evenList != nullptr)
        evenList->next = nullptr;
    return head;
}