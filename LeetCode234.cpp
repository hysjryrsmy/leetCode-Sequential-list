
//234. 回文链表
//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
// 
//示例 1：
//输入：head = [1, 2, 2, 1]
//输出：true
//
//示例 2：
//输入：head = [1, 2]
//输出：false


//方法一：将值复制到数组中后用双指针法
/*C++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.emplace_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = (int)vals.size() - 1; i < j; ++i, --j) {
            if (vals[i] != vals[j]) {
                return false;
            }
        }
        return true;
    }
};
*/
/*C
bool isPalindrome(struct ListNode* head) {
    int vals[50001], vals_num = 0;
    while (head != NULL) {
        vals[vals_num++] = head->val;
        head = head->next;
    }
    for (int i = 0, j = vals_num - 1; i < j; ++i, --j) {
        if (vals[i] != vals[j]) {
            return false;
        }
    }
    return true;
}
*/

//复杂度分析
//时间复杂度：O(n)，其中 n 指的是链表的元素个数。
//第一步： 遍历链表并将值复制到数组中，O(n)。
//第二步：双指针判断是否为回文，执行了 O(n / 2) 次的判断，即 O(n)。
//总的时间复杂度：O(2n) = O(n)。
//空间复杂度：O(n)，其中 n 指的是链表的元素个数，我们使用了一个数组列表存放链表的元素值。



//方法二：递归 (算法)
//C++
class Solution {
    ListNode* frontPointer;
public:
    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) {
                return false;
            }
            if (currentNode->val != frontPointer->val) {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};


//C
struct ListNode* frontPointer;

bool recursivelyCheck(struct ListNode* currentNode) {
    if (currentNode != NULL) {
        if (!recursivelyCheck(currentNode->next)) {
            return false;
        }
        if (currentNode->val != frontPointer->val) {
            return false;
        }
        frontPointer = frontPointer->next;
    }
    return true;
}

bool isPalindrome(struct ListNode* head) {
    frontPointer = head;
    return recursivelyCheck(head);
}

//复杂度分析
//时间复杂度：O(n)，其中n指的是链表的大小。
//空间复杂度：O(n)，其中 n 指的是链表的大小。我们要理解计算机如何运行递归函数，在一个函数中调用一个函数时，
//计算机需要在进入被调用函数之前跟踪它在当前函数中的位置（以及任何局部变量的值），通过运行时存放在堆栈中来实现（堆栈帧）。
//在堆栈中存放好了数据后就可以进入被调用的函数。在完成被调用函数之后，他会弹出堆栈顶部元素，以恢复在进行函数调用之前所在的函数。
//在进行回文检查之前，递归函数将在堆栈中创建 n 个堆栈帧，计算机会逐个弹出进行处理。所以在使用递归时空间复杂度要考虑堆栈的使用情况。
//这种方法不仅使用了 O(n) 的空间，且比第一种方法更差，因为在许多语言中，堆栈帧的开销很大（如 Python），
//并且最大的运行时堆栈深度为 1000（可以增加，但是有可能导致底层解释程序内存出错）。为每个节点创建堆栈帧极大的限制了算法能够处理的最大链表大小。



//方法三：快慢指针
//C++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // 判断是否回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 还原链表并返回结果
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* endOfFirstHalf(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};


//C
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

struct ListNode* endOfFirstHalf(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL) {
        return true;
    }

    // 找到前半部分链表的尾节点并反转后半部分链表
    struct ListNode* firstHalfEnd = endOfFirstHalf(head);
    struct ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

    // 判断是否回文
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalfStart;
    bool result = true;
    while (result && p2 != NULL) {
        if (p1->val != p2->val) {
            result = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 还原链表并返回结果
    firstHalfEnd->next = reverseList(secondHalfStart);
    return result;
}

//复杂度分析
//时间复杂度：O(n)，其中 n 指的是链表的大小。
//空间复杂度：O(1)。我们只会修改原本链表中节点的指向，而在堆栈上的堆栈帧不超过O(1)。



//方法四：哈希法
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode t = head;
        int base = 11, mod = 1000000007;
        int left = 0, right = 0, mul = 1;
        while (t != null) {
            left = (int)(((long)left * base + t.val) % mod);
            right = (int)((right + (long)mul * t.val) % mod);
            mul = (int)((long)mul * base % mod);
            t = t.next;
        }
        return left == right;
    }
}
