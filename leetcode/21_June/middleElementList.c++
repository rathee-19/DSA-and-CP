#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "LinkedList.h"
using namespace std;

ListNode *middleNode(ListNode *head)
{

    ListNode *slow = head;

    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
int main()
{
    ListNode *head = new ListNode();
    head->val = 1;
    head->next = new ListNode();
    head->next->val = 2;
    head->next->next = new ListNode();
    head->next->next->val = 3;
    head->next->next->next = new ListNode();
    head->next->next->next->val = 4;
    head->next->next->next->next = new ListNode();
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;
    ListNode *ans = middleNode(head);
    cout << ans->val << " ";

    return 0;
}