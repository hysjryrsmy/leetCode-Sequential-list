
//206. 反转链表
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

//示例 1：
//输入：head = [1, 2, 3, 4, 5]
//输出：[5, 4, 3, 2, 1]

//示例 2：
//输入：head = [1, 2]
//输出：[2, 1]

//示例 3：
//输入：head = []
//输出：[]


//方法一：迭代
/*C++*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

/*C*/
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//复杂度分析
//时间复杂度：O(n)，其中 n 是链表的长度。需要遍历链表一次。
//空间复杂度：O(1)。



//方法二：递归

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};


struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}


//复杂度分析
//时间复杂度：O(n)O(n)，其中 n 是链表的长度。需要对链表的每个节点进行反转操作。
//空间复杂度：O(n)O(n)，其中 n 是链表的长度。空间复杂度主要取决于递归调用的栈空间，最多为 n 层。



class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode ans = null;
        for (ListNode x = head; x != null; x = x.next) {
            ans = new ListNode(x.val, ans);
        }
        return ans;
    }
}

