# OJ_从中间输出链表

链接：https://leetcode-cn.com/problems/middle-of-the-linked-list/description/

>给定一个带有头结点 `head` 的非空单链表，返回链表的中间结点。
>
>如果有两个中间结点，则返回第二个中间结点。
>
> 
>
>**示例 1：**
>
>```
>输入：[1,2,3,4,5]
>输出：此列表中的结点 3 (序列化形式：[3,4,5])
>返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
>注意，我们返回了一个 ListNode 类型的对象 ans，这样：
>ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
>```
>
>**示例 2：**
>
>```
>输入：[1,2,3,4,5,6]
>输出：此列表中的结点 4 (序列化形式：[4,5,6])
>由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
>```
>
> 
>
>**提示：**
>
>- 给定链表的结点数介于 `1` 和 `100` 之间。

<font color = red size = 4>思路：</font>

​	这道题比较简单，遍历一遍链表，记录链表的结点个数，再根据奇偶数判断怎么取中间结点。这个思路和二叉树中由孩子结点判断父亲结点的思路一致，**一定记住是size-1而不是已经除2之后再-1**。

​	**另外，当链表中只有一个结点时直接返回1，没有中间结点。**

~~~C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    
    if(head == NULL){
        return NULL;
    }
    int size = SizeOfList(head);
    if(size == 1){
        return head;
    }
    
    struct ListNode* cur = head;
    printf("%d  ", size);
    
    if(size % 2 != 0){  //奇数个节点
         size--;
    }
    int num = size / 2;
    printf("%d", num);
    while(num){
            num--;
            cur = cur->next;
        }
    return cur;
}

int SizeOfList(struct ListNode* head){
    struct ListNode* cur = head;
    int size = 0;
    while(cur){
        size++;
        cur = cur->next;
    }
    return size;
}
~~~

