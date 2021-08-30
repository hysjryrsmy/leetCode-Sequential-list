
//24. 两两交换链表中的节点

//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

//实例1：
//输入：head = [1, 2, 3, 4]
//输出：[2, 1, 4, 3]
//示例 2：
//输入：head = []
//输出：[]
//示例 3：
//输入：head = [1]
//输出：[1]

//提示：
//链表中节点的数目在范围[0, 100] 内
//0 <= Node.val <= 100


//方法一：递归
//C++
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        ListNode* newHead = head->next;
//        head->next = swapPairs(newHead->next);
//        newHead->next = head;
//        return newHead;
//    }
//};


//C
//struct ListNode* swapPairs(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//    struct ListNode* newHead = head->next;
//    head->next = swapPairs(newHead->next);
//    newHead->next = head;
//    return newHead;
//}
//复杂度分析
//时间复杂度：O(n)O(n)，其中 nn 是链表的节点数量。需要对每个节点进行更新指针的操作。
//空间复杂度：O(n)O(n)，其中 nn 是链表的节点数量。空间复杂度主要取决于递归调用的栈空间。



//方法二：迭代

//C++
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummyHead->next;
    }
};
*/


//C
/*
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummyHead;
    dummyHead.next = head;
    struct ListNode* temp = &dummyHead;
    while (temp->next != NULL && temp->next->next != NULL) {
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead.next;
}
*/
