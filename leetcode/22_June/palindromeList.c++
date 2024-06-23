#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>
#include"LinkedList.h"

using namespace std;
 bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    ListNode *slow = head;
    ListNode *fast = head;

    // Find the middle of the list
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Reverse the second half of the list
    ListNode *prev = nullptr;
    ListNode *current = slow->next;
    while (current) {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    slow->next = prev;

    // Compare the first half and the reversed second half
    ListNode *firstHalf = head;
    ListNode *secondHalf = slow->next;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

    
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout<<isPalindrome(head);


    return 0;
}