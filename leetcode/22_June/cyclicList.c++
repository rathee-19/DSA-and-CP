#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;
bool hasCycle0(ListNode *head)
{
    if (head->next == NULL || head == NULL)
    {
        return 0;
    }
    else
    {
        ListNode *slow = head;
        ListNode *fast = head;
       do {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == NULL || slow == NULL)
            {
                return 0;
            }
         
        }while (fast != slow);
        fast = head;
        
       do {
            fast = fast->next;
            slow = slow->next;
            if (fast = slow)
            {
                return 1;
            }
            if (fast == NULL || slow == NULL)
            {
                return 0;
            }
        }while (fast != slow);
    }
    return 0;
}

bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    cout << hasCycle(head) << endl;

    return 0;
}