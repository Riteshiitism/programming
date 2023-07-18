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
// 1.
Node *reverseList(Node *head)
{
    if (head == NULL)
        return head;

    Node *par = head;
    Node *cur = NULL;
    while (par != NULL)
    {
        Node *tmp = par->next;
        par->next = cur;
        cur = par;
        par = tmp;
    }
    return cur;
}
// 3.
bool detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    do
    {
        if (fast == NULL)
            return 0;
        slow = slow->next;
        if (fast->next == NULL)
            return 0;
        fast = fast->next->next;
    } while (slow != fast);
    return 1;
}
// 4.
void removeLoop(Node *head)
{
    bool isCycle = true;
    Node *slow = head;
    Node *fast = head;
    // detect loop
    do
    {
        if (fast == NULL)
        {
            return;
        }
        slow = slow->next;
        if (fast->next == NULL)
        {
            return;
        }
        fast = fast->next->next;
    } while (slow != fast);
    // detect circle head
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // remove cycle
    Node *tmp = slow->next;
    while (tmp->next != slow)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
}
// 6.
Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return head;
    Node *prev = head;
    Node *cur = prev->next;
    while (cur != NULL)
    {
        if (cur->data != prev->data)
        {
            prev = cur;
            cur = cur->next;
        }
        else
        {
            Node *tmp = cur->next;
            prev->next = cur->next;
            cur->next = NULL;
            cur = tmp;
        }
    }
    return head;
}
// 7.
// 8.
Node *moveToFront(Node *head)
{
    if (head == NULL)
        return head;
    Node *cur = head;
    Node *prev = NULL;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL)
    {
        return head;
    }
    prev->next = NULL;
    cur->next = head;
    head = cur;

    return head;
}
// 9.
Node *addOne(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    head = reverseList(head);
    Node *tmp = head;
    int x = tmp->data;
    while (x == 9 && tmp->next != NULL)
    {
        tmp->data = 0;
        tmp = tmp->next;
        x = tmp->data;
    }
    if (tmp->next != NULL)
    {
        tmp->data += 1;
        head = reverseList(head);
        return head;
    }
    else
    {
        if (tmp->data != 9)
        {
            tmp->data += 1;
            head = reverseList(head);
            return head;
        }
        else
        {
            tmp->data = 0;
            Node *node = new Node(1);
            tmp->next = node;
            head = reverseList(head);
            return head;
        }
    }
}
// 10.
Node *addTwoLists(Node *first, Node *second)
{
    first = reverseList(first);
    second = reverseList(second);
    int x = 0;
    int y = 0;
    if (first != NULL)
    {
        x = first->data;
        first = first->next;
    }
    if (second != NULL)
    {
        y = second->data;
        second = second->next;
    }
    int sum = x + y;

    int d = sum % 10;
    int c = sum / 10;
    Node *head = new Node(d);
    Node *tail = head;

    while (first != NULL && second != NULL)
    {
        x = first->data;
        first = first->next;
        y = second->data;
        second = second->next;
        sum = x + y + c;
        d = sum % 10;
        c = sum / 10;
        tail->next = new Node(d);
        tail = tail->next;
    }
    while (first != NULL)
    {
        x = first->data;
        first = first->next;
        sum = x + c;
        d = sum % 10;
        c = sum / 10;
        tail->next = new Node(d);
        tail = tail->next;
    }
    while (second != NULL)
    {
        y = second->data;
        second = second->next;
        int sum = y + c;
        int d = sum % 10;
        c = sum / 10;
        tail->next = new Node(d);
        tail = tail->next;
    }
    if (c != 0)
    {
        tail->next = new Node(c);
        tail = tail->next;
    }
    head = reverseList(head);
    return head;
}
// 11.
Node *findIntersection(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = head;
    while (head1 != NULL && head2 != NULL)
    {
        int x = head1->data;
        int y = head2->data;
        if (x < y)
        {
            head1 = head1->next;
        }
        else if (x > y)
        {
            head2 = head2->next;
        }
        else
        {

            Node *node = new Node(x);
            if (tail == NULL)
            {
                head = node;
                tail = head;
            }
            else
            {
                tail->next = node;
                tail = tail->next;
            }

            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return head;
}
// 12.
int length(Node *head)
{
    int ans = 0;
    if (head == NULL)
        return ans;
    while (head != NULL)
    {
        ans++;
        head = head->next;
    }
    return ans;
}
int intersectPoint(Node *head1, Node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    if (l1 >= l2)
    {
        int d = l1 - l2;
        int ans = -1;
        while (d > 0)
        {
            head1 = head1->next;
            d--;
        }
        while (head1 != NULL && head2 != NULL)
        {
            if (head1 == head2)
            {
                ans = head1->data;
                return ans;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return ans;
    }
    else
    {
        int d = l2 - l1;
        int ans = -1;
        while (d > 0)
        {
            head2 = head2->next;
            d--;
        }
        while (head1 != NULL && head2 != NULL)
        {
            if (head1 == head2)
            {
                ans = head1->data;
                return ans;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return ans;
    }
}
// 17.
Node *findHead(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    do
    {
        // if(fast==NULL)  return 0
        slow = slow->next;
        // if(fast->next==NULL)  return 0
        fast = fast->next->next;
    } while (slow != fast);
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    head = findHead(head);

    Node *slow = head;
    Node *fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = *head1_ref;
    Node *tmp = *head2_ref;
    while (tmp->next != head)
    {
        tmp = tmp->next;
    }
    tmp->next = *head2_ref;

    return;
}
// 18.

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(Node *head)
{
    Node *mid = findMid(head);
    Node *tmp = reverseList(mid->next);
    // mid->next = tmp;
    Node *first = head;
    Node *second = tmp;
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            return false;
        }
        else
        {
            first = first->next;
            second = second->next;
        }
    }
    tmp = reverseList(tmp);
    mid->next = tmp;
    return true;
}
/* Function to delete a given node from the circular list */
void deleteNode(struct Node **head, int key)
{
    Node* par = *head;
    Node* prev = NULL;
    while(par->next!=*head){
        if(par->data==key){
            Node* tmp = par->next;
            par->next=NULL;
            if(prev!=NULL) prev->next = tmp;
            delete par;
            break;
        }
        prev = par;
        par=par->next;
    }
    return;
}

/* Function to reverse the circular linked list */
void reverseCircular(struct Node** head_ref)
{

    Node* prev = *head_ref;
    Node* par = (*head_ref)->next;
    do{
        Node* tmp = par->next;
        par->next = prev;
        prev = par;
        par = tmp;
    }while(prev!=(*head_ref));
    *head_ref = prev->next;
}

int main()
{
    // int n1, n2, n3;
    // cin >> n1 >> n2 >> n3;
    // Node *head1 = intputList(n1);
    // Node *head2 = intputList(n2);
    // Node *common = intputList(n3);
    // Node *tmp = head1;
    // while (tmp != NULL && tmp->next != NULL)
    // {
    //     tmp = tmp->next;
    // }
    // if (tmp != NULL)
    //     tmp->next = common;

    // tmp = head2;
    // while (tmp != NULL && tmp->next != NULL)
    // {
    //     tmp = tmp->next;
    // }
    // if (tmp != NULL)
    //     tmp->next = common;
    // cout << intersectPoint(head1, head2);

    // int a = 8;
    // cout<<&a<<endl;
    // int* x = &a;
    // cout<<x<<endl;

    // cout<<*x<<endl;
    // cout<<*(&a)<<endl;

    // *x = 5;
    // cout<<a<<endl;

    Node* head = new Node(10);

    // cout<<&head<<endl;
    Node**   tmp = &head;
    // cout<<tmp<<endl;
    Node* par = *tmp;
    cout<<par->data<<endl;
    par = par->next;
    cout<<(*tmp)->data<<endl;
    // cout<<*tmp->data<<endl;    WRONG

}

// 3 1 2
// 3 6 9
// 10
// 15 30