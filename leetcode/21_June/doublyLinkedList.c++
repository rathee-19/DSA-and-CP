#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *back;
};
Node *convert(vector<int> &arr)
{
    int n = arr.size();
    Node *head = new Node;
    head->data = arr[0];
    head->next = NULL;
    head->back = NULL;
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node;
        newNode->data = arr[i];
        newNode->next = NULL;
        newNode->back = temp;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {12, 2, 3, 4, 5};
    Node *head = convert(arr);
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    cout << endl;
    while (temp)
    {
        cout << temp->data << " ";
        if (temp->back == NULL)
        {
            break;
        }
        temp = temp->back;
    }

    return 0;
}