#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;
ListNode *reverseList(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    ListNode *temp = NULL;
    ListNode *agla = (head != NULL) ? head->next : NULL;
    if (agla == NULL)
    {
        return head;
    }
    while (agla)
    {

        head->next = temp;
        temp = head;
        head = agla;
        agla = head->next;
    }
    head->next = temp;
    return head;
}
ListNode *removeHead(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    ListNode *temp = head;
    head = head->next;
    delete temp;
    return head;
}
ListNode *removeK(ListNode *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (k == 1)
    {
        head = removeHead(head);
        return head;
    }
    ListNode *temp = head;
    ListNode *prev = NULL;
    int count = 0;
    while (temp)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *newHead = reverseList(head);
    newHead = removeK(newHead, n);
    return reverseList(newHead);

}
ListNode*remo(ListNode *head, int n){
     ListNode *trav = head;
    int length = 0;

    while (trav)
    {

        trav = trav->next;
        length++;
    }
    if (length == 1)
    {
        return NULL;
    }
    int target = length -n;
    if (target == 0)
    {
        return head->next;
    }
    trav = head;
    for (int i = 0; i < target - 1; i++)
    {
        trav = trav->next;
    }
    trav->next = trav->next->next;
    return head;

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
    head->next->next->next->next = NULL;

    ListNode *ans = remo(head, 1);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}