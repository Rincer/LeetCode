#include "..\Solution.h"

ListNode* Solution::deleteMiddle(ListNode* head) 
{
    if (head->next == nullptr)
        return nullptr;
    ListNode* node = head;
    int length = 0;
    while (node != nullptr)
    {
        node = node->next;
        length++;
    }
    node = head;
    for (int i = 0; i < length / 2 - 1; i++)
        node = node->next;
    if (node->next != nullptr)
    {
        ListNode* deletedNode = node->next;
        node->next = deletedNode->next;
    }
    return head;
}
