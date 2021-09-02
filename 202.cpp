
//202. 快乐数
//编写一个算法来判断一个数 n 是不是快乐数。
//
//「快乐数」定义为：
//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果 可以变为  1，那么这个数就是快乐数。
//如果 n 是快乐数就返回 true ；不是，则返回 false 。
//
//示例 1：
//输入：19
//输出：true
//解释：
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1
//
//示例 2：
//输入：n = 2
//输出：false


/*
bool isHappy(int n) {
    short _n;
    while (n != 0 && n != 1 && n != 4 && n != 16 && n != 37 && n != 58
        && n != 89 && n != 145 && n != 42 && n != 20) {
        _n = 0;
        while (n) {
            _n = _n + pow(n % 10, 2);
            n = n / 10;
        }
        n = _n;
    }
    if (n == 1) return 1;
    else return 0;
}
*/


//主要思路就是
//1.写一个外部函数，用来将n转化成每一位的平方和；
//2.首先判断是否为1 ，如果是的话退出while循环返回true；
//3.如果不为1，再判断是否在hash表中有记录，如果没有的话，对应位置 + 1代表出现过这个数，如果有的话直接返回false；
//这里hash表我声明了一个820的空间，因为int型的最大值大概是2的10次方，不会超过10个9，那10个9的平方相加就是810；

int reverse(int n)    //输入一个n，返回的num值就是n的每一位平方相加
{
    int num = 0;
    while (n != 0)
    {
        num = num + (n % 10) * (n % 10);
        n = n / 10;
    }
    return num;
}

bool isHappy(int n) {
    int num = 0;
    num = reverse(n);    //先对给定的参数n做一次运算
    int* hash = (int*)calloc(sizeof(int), 820);
    while (num != 1)   //运算结果不为1的话就继续判断
    {
        if (hash[num] == 1)    //hash的这个位置，比如num=5，如果是第一次出现num=5，那么hash[5] = 0+1；
        {                     //第二次出现num=5的时候，会发现hash[5]已经等于1了，就说明5出现过，直接返回false；
            return false;
        }
        else
        {
            hash[num] ++;     //如果num没有出现过的话，也就是hash[num] = 0；这时候就给它加上1；
        }
        num = reverse(num);   //再做一次运算，在while循环里判断
    }
    return true;
}



//解题思路：
//方法：
//使用 “快慢指针” 思想，找出循环：“快指针” 每次走两步，“慢指针” 每次走一步，当二者相等时，即为一个循环周期。
//此时，判断是不是因为 1 引起的循环，是的话就是快乐数，否则不是快乐数。
//注意：此题不建议用集合记录每次的计算结果来判断是否进入循环，因为这个集合可能大到无法存储；
//另外，也不建议使用递归，同理，如果递归层次较深，会直接导致调用栈崩溃。不要因为这个题目给出的整数是 int 型而投机取巧。

//C++

class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while (n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow != fast);

        return slow == 1;
    }
};
