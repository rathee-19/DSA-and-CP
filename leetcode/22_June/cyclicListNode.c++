#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    else
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }
        if (slow != fast)           // if there is no cycle
        {
            return NULL;
        }
        if (slow == head)                // if the cycle starts from the head
        {
            return head;
        }
        {         
            return head;
        }

        fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;

            if (slow == fast)
            {
                break;
            }
        }
        return fast;
    }
    return NULL;
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    cout << detectCycle(head)->val << endl;

    return 0;
}