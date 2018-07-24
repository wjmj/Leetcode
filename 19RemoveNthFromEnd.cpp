#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL || n <= 0)
        return NULL;

    if (n == 1)
    {
        ListNode *p1 = head;
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return NULL;
        }
        ListNode *p2 = head->next;

        while (p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        p1->next = NULL;
        delete p2;
        p2 = NULL;
        return head;
    }

    else
    {
        ListNode *p1 = head;
        ListNode *p2 = head;
        int cnt = 1;
        while (p2->next != NULL && cnt < n)
        {
            p2 = p2->next;
            cnt++;
        }

        if (cnt < n)
            return NULL;

        while (p2 ->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        p1->val = p1->next->val;
        ListNode *node = p1->next;
        p1->next = p1->next->next;
        
        delete node;
        node = NULL;
    }

    return head;
}
       
