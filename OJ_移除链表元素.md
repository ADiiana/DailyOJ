# OJ_移除链表元素

链接：https://leetcode-cn.com/problems/remove-linked-list-elements/submissions/

## 题目描述

>删除链表中等于给定值 **val** 的所有节点。
>
>**示例:**
>
>```C
>输入: 1->2->6->3->4->5->6, val = 6
>输出: 1->2->3->4->5
>```

<font size = 5 color = red >思路：</font>（C++代码的思路）

1. 如果链表一开始就是要移除的val结点，就先移除，直到链表的第一个结点不是val值

2. 如果链表中有两个结点，判断第二个结点：

   ①若不为空且满足条件，删除（置为空），并返回head。

   ②若为空，返回head。

   ③若不为空且不满足条件，*执行第3步*。

3. 判断链表的第3个结点是否为空：

   ①若为空，返回head。

   ②若不为空且满足条件，删除第三个结点，返回head。

   ③若不为空且不满足条件，*执行第4步*。

4. 从head开始定义三个标兵依次是（before、cur、latter）此时，before一定不是要删除的结点，从cur开始判断：

   ①若cur的val值满足条件，删除cur，并将latter赋值给cur，latter的下一个赋值给latter。

   ②若cur的val值不满足条件，三个标兵依次往前走一步，直到latter为空，*执行第5步*

5. 判断最后一个结点，即latter的值是否满足条件，满足则删除，否则直接返回head。

## 代码

~~~C++
// C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL)
            return NULL;
        
        while(head->val == val && head != NULL){
            head = head->next;
            if(head == NULL){
                return NULL;
            }
        }
        
        struct ListNode* before = head;
        
        if(head->next == NULL){
            return head;
        }
        
        struct ListNode* cur = head->next;
        
        if(cur->next == NULL){
            if(cur->val == val){
                before->next = NULL;
                return head;
            }
        }
        struct ListNode* latter = cur->next;
        
        while(cur != NULL && latter != NULL){
            if(cur->val == val){
                before->next = latter;
                cur = latter;
                latter = latter->next;
            }
            else{
                before = cur;
                cur = latter;
                latter = latter->next;
            }
        }
        if(cur->val == val){
            cout << cur->val <<endl;
            before->next = NULL;
        }
        return head;
    }
};
~~~

~~~C
// C 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL)
        return NULL;
    
    struct ListNode* previous = head;
    struct ListNode* current = previous->next;
    
    while(previous->val == val){
        //free(head);
        head = current;
        previous = head;
        if(previous == NULL)
            return NULL;
        current = previous->next;
    }
    
    while(current != NULL){
        struct ListNode* latter = current->next;
        if(current->val == val){
            //删除操作
            previous->next = latter;
            //free(current);
            current = latter;
            if(latter == NULL)
                return head;
            latter = latter->next;
            continue;
        }
        //移动指针
        previous = current;
        current = latter;
        if(latter == NULL)
            break;
        latter = latter->next;
        
    }
    return head;
}

~~~

