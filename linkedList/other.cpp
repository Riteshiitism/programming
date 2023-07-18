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

// Function to sort a linked list of 0s, 1s and 2s.
Node *segregate(Node *head)
{

    // take some dummy node it remove some if else conditions
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *cur = head;
    // make three list(zero ,one , two)
    while (cur != NULL)
    {
        if (cur->data == 0)
        {
            zeroTail->next = cur;
            zeroTail = zeroTail->next;
        }
        else if (cur->data == 1)
        {
            oneTail->next = cur;
            oneTail = oneTail->next;
        }
        else
        {
            twoTail->next = cur;
            twoTail = twoTail->next;
        }
        cur = cur->next;
    }

    // connect three list
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // connect head to ones list
    head = zeroHead->next;

    // delete dummy node
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}

// merge two sorted list
Node *solve(Node *head1, Node *head2)
{
    Node *head = head2;
    Node *cur = head->next;
    Node *prev = head;
    while (head1 != NULL)
    {
        if (cur == NULL)
        {
            prev->next = head1;
            return head;
        }
        if (head1->data <= cur->data)
        {
            prev->next = head1;
            Node *tmp = head1->next;
            head1->next = cur;
            prev = prev->next;
            head1 = tmp;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}
Node *sortedMerge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data >= head2->data)
    {
        return solve(head1, head2);
    }
    else
    {
        return solve(head2, head1);
    }
}

// find middle element
Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL)
    {
        return slow;
    }
    else
    {
        return slow->next;
    }
}
int main()
{
}