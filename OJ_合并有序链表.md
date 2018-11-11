# OJ_合并有序链表

链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/

>将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
>
>**示例：**
>
>```
>输入：1->2->4, 1->3->4
>输出：1->1->2->3->4->4
>```

<font color = red size = 4>思路:</font>

​	申请一个临时节点头tmp，以及返回值结点ret = tmp,判断链表A 和链表B 的值大小，如果链表A的值大，tmp的next = A；并将链表A指向下一个结点，再次与链表B比较，直到有一条链表遍历一遍。

​	判断是哪条链表不为空，再将这条链表链到tmp的后边。

​	函数返回ret->next;即可。

<font color = purple size = 4>代码中遇到的BUG:</font>

- tmp必须要给定一个值，再进行向下的遍历，不然是随机值，可能进入死循环。
- 要考虑，如果有一个链表为空，这个时候直接返回那个不为空的链表即可。

- 记录链表的头指针，便于返回。

~~~C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
        
    struct ListNode* tmp = NULL;
    struct ListNode* ret = tmp;
    
    if(l1 == NULL || l2 == NULL){
        if(l1){
            return l1;
        } 
        if(l2){
            return l2;
        }
    }
    if(l1 == NULL && l2 == NULL){
        return NULL;
    }
    if(l1->val < l2->val){
        tmp = l1;			//一定要先给tmp赋一个值
        printf("hello");
        l1 = l1->next;
    }
    else{
        printf("1 ");
        tmp = l2;
        l2 = l2->next;
    }
    ret = tmp;
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            printf("2 ");
            tmp->next = l1;
            tmp = tmp->next;
            l1 = l1->next;
            
        }else{
            printf("3 ");
            tmp->next = l2;
            l2 = l2->next;
            tmp = tmp->next;
        }
    }
    if(l1 != NULL){
        tmp->next = l1;
    }
    if(l2 != NULL){
        tmp->next = l2;
    }
    printf("%d", tmp->val);
    return ret;
}
~~~

