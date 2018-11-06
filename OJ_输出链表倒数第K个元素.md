# OJ_输出链表倒数第K个元素

链接：https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

>输入一个链表，输出该链表中倒数第k个结点。

<font color = red size = 4>思路：</font>

​	这道简单的做法是用快慢指针，这是我学到的一个新技巧。

​	快指针先走**k**个结点，然后慢指针和快指针一起走，当快指针遍历完这条链表时，慢指针所指的结点就是这条链表的倒数第k个元素。

*在这个过程中需要注意的点：*

- 考虑链表为空时，返回NULL；
- 如果这条链表没有k个元素就要返回NULL；

~~~C++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        struct ListNode* pre = pListHead;
        struct ListNode* latter = pListHead;
        if(pre == NULL){
            return NULL;
        }
        while(k--){
            if(pre == NULL){
                return NULL;
            }
            pre = pre->next;
        }
        
        while(pre != NULL){
            latter = latter->next;
            pre = pre->next;
        }
        return latter;
    }
};
~~~