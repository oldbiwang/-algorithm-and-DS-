#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int x = 0, y = 0, carry = 0, sum = 0;
        ListNode *h = NULL, **t = &h;

        while (l1 != NULL || l2 != NULL)
        {
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);

            sum = carry + x + y;

            ListNode *node = new ListNode(sum % 10);
            *t = node;
            t = (&node->next);

            carry = sum / 10;
        }

        if (carry > 0)
        {
            ListNode *node = new ListNode(carry % 10);
            *t = node;
        }

        return h;
    }

    void output(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }

    void free(ListNode *head)
    {
        cout << "不知是否需要手动释放链表的内存？这里释放了" << endl;
        ListNode *next;
        while (head != NULL)
        {
            next = head->next;
            delete head;
            head = next;
        }
    }

  private:
    int getValueAndMoveNext(ListNode *&l)
    {
        int x = 0;
        if (l != NULL)
        {
            x = l->val;
            l = l->next;
        }
        return x;
    }
};

int main()
{
    // 第一个链表 l1
    ListNode *l1head = new ListNode(2);
    ListNode *l1second = new ListNode(4);
    ListNode *l1third = new ListNode(3);

    l1head->next = l1second;
    l1second->next = l1third;

    // 第二个链表 l2
    ListNode *l2head = new ListNode(5);
    ListNode *l2second = new ListNode(6);
    ListNode *l2third = new ListNode(4);

    l2head->next = l2second;
    l2second->next = l2third;

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1head, l2head);
    solution.output(result);
    solution.free(l1head);
    solution.free(l2head);
    solution.free(result);
    return 0;
}