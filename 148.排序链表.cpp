/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//  归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head, ListNode* tail) 
    {
        if (head == nullptr) 
        {
            return head;
        }
        if (head->next == tail) 
        {
            head->next = nullptr;
            return head;
        }
        // 快慢指针找中点
        ListNode* slow = head, *fast = head;
        while (fast != tail) 
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) 
            {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        // 排序两个子链表
        // 参数为循环递归的子链表
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) 
    {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) 
        {
            if (temp1->val <= temp2->val) 
            {
                temp->next = temp1;
                temp1 = temp1->next;
            } 
            else 
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) 
        {
            temp->next = temp1;
        } 
        else if (temp2 != nullptr) 
        {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};
// @lc code=end

