// Function to sort the given linked list using Merge Sort.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};
Node *intputList(int n)
{
    if (n == 0)
        return NULL;
    int val;
    cin >> val;
    Node *head = new Node(val);
    Node *tail = head;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *findTail(Node *head)
{
    while (head != NULL && head->next != NULL)
        head = head->next;

    return head;
}
Node *findMid(Node *head, Node *tail)
{
    if (head == NULL)
        return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node *solve(Node *head1, Node *head2)
{
    Node *head = head1;
    Node *prev = head;
    Node *cur = head->next;
    while (head2 != NULL)
    {
        if (cur == NULL)
        {
            prev->next = head2;
            return head;
        }
        if (head2->data < cur->data)
        {
            Node *tmp = head2->next;
            head2->next = prev->next;
            prev->next = head2;
            prev = prev->next;
            head2 = tmp;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}
Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data)
    {
        return solve(head1, head2);
    }
    else
    {
        return solve(head2, head1);
    }
}
Node *solution(Node *head, Node *tail)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = findMid(head, tail);
    Node *tmp = mid->next;
    mid->next = NULL;
    Node *left = solution(head, mid);
    Node *right = solution(tmp, tail);
    return merge(left, right);
}
Node *mergeSort(Node *head)
{
    Node *tail = findTail(head);
    return solution(head, tail);
}
int main(){
    
}
/*
*/