#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

using namespace std;
 vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return {-1, -1};  // Not enough nodes to have two critical points
    }

    vector<int> criticalPoints;
    ListNode* prev = head;
    ListNode* curr = head->next;
    int index = 1;

    while (curr->next) {
        ListNode* next = curr->next;
        if ((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) {
            criticalPoints.push_back(index);
        }
        prev = curr;
        curr = next;
        index++;
    }

    if (criticalPoints.size() < 2) {
        return {-1, -1};  // Not enough critical points
    }

    int minDist = INT_MAX;
    int maxDist = criticalPoints.back() - criticalPoints.front();

    for (size_t i = 1; i < criticalPoints.size(); ++i) {
        minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
    }

    return {minDist, maxDist};
}
int main(){
    ListNode * head = new ListNode(4);
    ListNode * temp = head;
    temp->next = new ListNode(2);
    temp = temp->next;
    temp->next = new ListNode(3);
    temp = temp->next;
    temp->next = new ListNode(1);
    temp = temp->next;
    temp->next = new ListNode(5);
    temp = temp->next;
    temp->next = new ListNode(6);
    temp = temp->next;
    temp->next = new ListNode(4);
    temp = temp->next;
    temp->next = new ListNode(8);
   temp = temp->next;
   temp ->next = NULL; 
    vector<int> res = nodesBetweenCriticalPoints(head);
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}