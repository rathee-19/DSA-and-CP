#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>
#include "LinkedList.h"

using namespace std;

  ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        for(int i = 0; i < len/k; i++){
            for(int j = 1; j < k; j++){
                ListNode* next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
        
    }
    
int main(){
    ListNode* head = new ListNode();
    head->val = 1;
    head->next = new ListNode();
    head->next->val = 2;
    head->next->next = new ListNode();
    head->next->next->val = 3;
    head->next->next->next = new ListNode();
    head->next->next->next->val = 4;
    head->next->next->next->next = new ListNode();
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->val = 6;
    head->next->next->next->next->next->next = new ListNode();
    head->next->next->next->next->next->next->val = 7;
    head->next->next->next->next->next->next->next = NULL;

    ListNode* ans = reverseKGroup(head, 3);
    while(ans){
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}