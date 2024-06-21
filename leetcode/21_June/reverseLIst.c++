#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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

    ListNode *ans = reverseList(head);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}