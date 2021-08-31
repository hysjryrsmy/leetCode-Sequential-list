﻿
//83. 删除排序链表中的重复元素

//存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
//返回同样按升序排列的结果链表。

//输入：head = [1, 1, 2]
//输出：[1, 2]

//输入：head = [1, 1, 2, 3, 3]
//输出：[1, 2, 3]

//提示：
//链表中节点数目在范围[0, 300] 内
//- 100 <= Node.val <= 100
//题目数据保证链表已经按升序排列



/*C++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            else {
                cur = cur->next;
            }
        }

        return head;
    }
};
*/



/*C
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return head;
    }

    struct ListNode* cur = head;
    while (cur->next) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        }
        else {
            cur = cur->next;
        }
    }

    return head;
}
*/


//复杂度分析
//时间复杂度：O(n)O(n)，其中 nn 是链表的长度。
//空间复杂度：O(1)O(1)。