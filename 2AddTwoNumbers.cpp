#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* k = NULL;
        ListNode* r = NULL;
        int c = 0;
        int i = 1;
        while (p != NULL && q!=NULL)
        {
            int n = p->val + q->val;
            ListNode* node = new ListNode((n+c)%10);
            if (k == NULL)k = node;
            if (r != NULL)r->next = node;
            r = node;
            c = (n+c)/10;
            p = p->next;
            q = q->next;
        }

        while (p!=NULL)
        {
            int n = p->val;
            ListNode* node = new ListNode((n+c)%10);
            r->next = node;
            r = node;
            c = (n+c)/10;
            p = p->next;
        }

        while (q != NULL)
        {
            int n = q->val;
            ListNode* node = new ListNode((n+c)%10);
            r->next = node;
            r = node;
            c = (n+c)/10;
            q = q->next;
        }

        if (c != 0)
        {
            ListNode* node = new ListNode(c);
            r->next = node;
            r = node;
        }

        return k;
    }
};
int main()
{
    Solution m;
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    int nums1[] = {8, 9};
    for (int i = 0; i < 2; i++) {
        ListNode* p = new ListNode(nums1[i]);
        p->next = l1;
        l1 = p;
    }

    int nums2[] = {1};
    for (int i = 0; i < 1; i++) {
        ListNode* p = new ListNode(nums2[i]);
        p->next = l2;
        l2 = p;
    }

    ListNode* res = m.addTwoNumbers(l1, l2);
    ListNode* p = res;
    while (p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}

