# OJ_相交链表

 链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

## 题目描述

>编写一个程序，找到两个单链表相交的起始节点。
>
> 
>
>例如，下面的两个链表**：**
>
>```
>A:          a1 → a2
>                   ↘
>                     c1 → c2 → c3
>                   ↗            
>B:     b1 → b2 → b3
>```
>
>在节点 c1 开始相交。
>
> 
>
>**注意：**
>
>- 如果两个链表没有交点，返回 `null`.
>- 在返回结果后，两个链表仍须保持原有的结构。
>- 可假定整个链表结构中没有循环。
>- 程序尽量满足 O(*n*) 时间复杂度，且仅用 O(*1*) 内存。

<font color = red size = 5>思路:</font>

​	这道题有两个思路，一个是用链表，另一个用栈。

**链表：**

​	先计算两条链表的长度，计算出两条链表的差值，让比较长的一条链表先遍历，直到两条链表的长度相等，*再共同遍历两条链表，比较这两条的值是否相同，如果相同就返回这个结点，其它情况，就返回NULL*

​	栈的元素是链表节点的指针。

~~~C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int size_list(struct ListNode *head){
    
    struct ListNode* cur = head;
    int i = 0;
    
    while(cur){
        cur = cur->next;
        i++;
    }
    
    return i;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    
    struct ListNode* _a = headA;
    struct ListNode* _b = headB;
    
    while(_a == NULL || _b == NULL)
        return NULL;
    
    int ib = 0;
    int ia = 0;
    int size_b = 0;
    int size_a = 0;
    
    size_a = size_list(_a);
    size_b = size_list(_b);
    
    int c = abs(size_a - size_b);
    
    if(size_a > size_b){
        while(c && _a){
            _a = _a->next;
            c--;
        }
    }
    else{
        while(c && _b){
            _b = _b->next;
            c--;
        }
    }
    
    while(_a && _b){
        if(_a == _b){
            return _a;
        }
        _a = _a->next;
        _b = _b->next;
    }
    
    return NULL;

}
~~~



**用栈实现：**

​	将两条链表的元素分别入到两个栈里，计算出两个栈的大小，如果两个栈的大小不相同，pop出比较大的栈突出的元素，直到两个栈的元素相同，再同时pop出两个栈元素，同时比较这两个元素对应值是否相同，如果相同，就找到了相交链表结点，否则，返回NULL。

*这两种情况中相同的地方，是要先判断这两条链表是否为空，如果有一个为空，则返回NULL，如果遍历完两条链表，或者两个栈的元素都被pop空，也没有对应相同的结点，也返回NULL*