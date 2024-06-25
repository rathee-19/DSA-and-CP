#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;
ListNode *rotateRight(ListNode *head, int k)
{

    if (head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }

    ListNode *temp = head;
    int len = 1;
    while (temp->next)
    {
        len++;
        temp = temp->next;
    }
    
    k = k % len;
    
    if (k == 0)
    {
        return head;
    }
    k = len - k;
    temp->next = head;

    for (int i = 0; i < k; i++)
    {
        temp = head;
        head = temp->next;
        /* code */
    }
    temp->next = NULL;

    return head;
}
int main()
{
    ListNode *head = new ListNode();
    head->val = 0;
    head->next = new ListNode();
    head->next->val = 1;
    head->next->next = NULL;
    // head->next->next = new ListNode();
    // head->next->next->val = 2;
    // head->next->next->next = NULL;

    // head->next->next->next = new ListNode();
    // head->next->next->next->val = 4;
    // head->next->next->next->next = new ListNode();
    // head->next->next->next->next->val = 5;
    // head->next->next->next->next->next = NULL;

    ListNode *ans = rotateRight(head, 2);
    while (ans)
    {
        cout << ans->val;
        ans = ans->next;
    }

    return 0;
}