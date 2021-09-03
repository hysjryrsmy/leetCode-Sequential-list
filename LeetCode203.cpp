
//203. 移除链表元素
//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//
//示例 1：
//输入：head = [1, 2, 6, 3, 4, 5, 6], val = 6
//输出：[1, 2, 3, 4, 5]
//
//示例 2：
//输入：head = [], val = 1
//输出：[]
//
//示例 3：
//输入：head = [7, 7, 7, 7], val = 7
//输出：[]
//
//提示：
//列表中的节点数目在范围[0, 104] 内
//1 <= Node.val <= 50
//0 <= val <= 50


/*
方法一：递归
C++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};


C
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) {
        return head;
    }
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}
*/
//复杂度分析
//时间复杂度：O(n)O(n)，其中 nn 是链表的长度。递归过程中需要遍历链表一次。
//空间复杂度：O(n)O(n)，其中 nn 是链表的长度。空间复杂度主要取决于递归调用栈，最多不会超过 nn 层。



/*
//方法二：迭代
C++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        struct ListNode* dummyHead = new ListNode(0, head);
        struct ListNode* temp = dummyHead;
        while (temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            }
            else {
                temp = temp->next;
            }
        }
        return dummyHead->next;
    }
};

C
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* temp = dummyHead;
    while (temp->next != NULL) {
        if (temp->next->val == val) {
            temp->next = temp->next->next;
        }
        else {
            temp = temp->next;
        }
    }
    return dummyHead->next;
}
*/
//复杂度分析
//时间复杂度：O(n)O(n)，其中 nn 是链表的长度。需要遍历链表一次。
//空间复杂度：O(1)O(1)。



//方法三：双指针
//设置两个指针分别指向头节点，pre （记录待删除节点的前一节点）和 cur(记录当前节点)；
//遍历整个链表，查找节点值为 val 的节点，找到了就删除该节点，否则继续查找。
//2.1.找到，将当前节点的前一节点（pre 节点或者说是之前最近一个值不等于 val 的节点）连接到当前节点（cur 节点）的下一个节点（pre->next = cur->next）。
//2.2.没找到，更新最近一个值不等于 val 的节点（pre = cur），继续遍历（cur = cur->next）。

//C
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        head = head->next;
    }

    struct ListNode* cur = head;  //  当前节点
    struct ListNode* pre = head;  //  保存待删除节点的前一节点
    while (cur != NULL) {
        if (cur->val == val) {
            pre->next = cur->next;
        }
        else {
            pre = cur;
        }
        cur = cur->next;
    }

    return head;
}


//C++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            head = head->next;
        }

        ListNode* cur = head;  //  当前节点
        ListNode* pre = head;  //  保存删除节点的前一节点
        while (cur != NULL) {
            if (cur->val == val) {
                pre->next = cur->next;
            }
            else {
                pre = cur;
            }
            cur = cur->next;
        }

        return head;
    }
};

