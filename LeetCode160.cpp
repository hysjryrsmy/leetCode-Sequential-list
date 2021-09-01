//160. 相交链表

//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
//图示两个链表在节点 c1 开始相交：
//题目数据 保证 整个链式结构中不存在环。
//注意，函数返回结果后，链表必须 保持其原始结构 。

//示例 1：
//输入：intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 0, 1, 8, 4, 5], skipA = 2, skipB = 3
//输出：Intersected at '8'
//解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
//从各自的表头开始算起，链表 A 为[4, 1, 8, 4, 5]，链表 B 为[5, 0, 1, 8, 4, 5]。
//在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

//示例 2：
//输入：intersectVal  = 2, listA = [0, 9, 1, 2, 4], listB = [3, 2, 4], skipA = 3, skipB = 1
//输出：Intersected at '2'
//解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
//从各自的表头开始算起，链表 A 为[0, 9, 1, 2, 4]，链表 B 为[3, 2, 4]。
//在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。

//示例 3：
//输入：intersectVal = 0, listA = [2, 6, 4], listB = [1, 5], skipA = 3, skipB = 2
//输出：null
//解释：从各自的表头开始算起，链表 A 为[2, 6, 4]，链表 B 为[1, 5]。
//由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
//这两个链表不相交，因此返回 null 。


//方法一：哈希集合
/*C++
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> visited;
        ListNode* temp = headA;
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr) {
            if (visited.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};
*/


/*C
struct HashTable {
    struct ListNode* key;
    UT_hash_handle hh;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct HashTable* hashTable = NULL;
    struct ListNode* temp = headA;
    while (temp != NULL) {
        struct HashTable* tmp;
        HASH_FIND(hh, hashTable, &temp, sizeof(struct HashTable*), tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = temp;
            HASH_ADD(hh, hashTable, key, sizeof(struct HashTable*), tmp);
        }
        temp = temp->next;
    }
    temp = headB;
    while (temp != NULL) {
        struct HashTable* tmp;
        HASH_FIND(hh, hashTable, &temp, sizeof(struct HashTable*), tmp);
        if (tmp != NULL) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
*/
//复杂度分析
//时间复杂度：O(m + n)O(m + n)，其中 mm 和 nn 是分别是链表 \textit{ headA }headA 和 \textit{ headB }headB 的长度。需要遍历两个链表各一次。
//空间复杂度：O(m)O(m)，其中 mm 是链表 \textit{ headA }headA 的长度。需要使用哈希集合存储链表 \textit{ headA }headA 中的全部节点。




//方法二：双指针
//C++
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode* pA = headA, * pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};


//C
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    struct ListNode* pA = headA, * pB = headB;
    while (pA != pB) {
        pA = pA == NULL ? headB : pA->next;
        pB = pB == NULL ? headA : pB->next;
    }
    return pA;
}

//复杂度分析
//时间复杂度：O(m + n)O(m + n)，其中 mm 和 nn 是分别是链表 \textit{ headA }headA 和 \textit{ headB }headB 的长度。
//两个指针同时遍历两个链表，每个指针遍历两个链表各一次。
//空间复杂度：O(1)O(1)。

