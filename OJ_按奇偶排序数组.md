# OJ_按奇偶排序数组

链接：https://leetcode-cn.com/problems/sort-array-by-parity/

>题目描述：
>
>给定一个非负整数数组 `A`，返回一个由 `A` 的所有偶数元素组成的数组，后面跟 `A` 的所有奇数元素。
>
>你可以返回满足此条件的任何数组作为答案。
>
> 
>
>**示例：**
>
>```
>输入：[3,1,2,4]
>输出：[2,4,3,1]
>输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
>```
>
> 
>
>**提示：**
>
>1. `1 <= A.length <= 5000`
>2. `0 <= A[i] <= 5000`

<font color = red size = 4>思路(两种方法):</font>

- 方法一：重新开辟一个和数组A大小相同的空间tmp，遍历数组，偶数放在tmp的前端，奇数放在tmp后边。
- 方法二：类似于快速排序的思路——同时从数组两头遍历，从数组头判断是偶数就继续遍历，从数组尾部，是奇数就继续遍历，如果不满足条件就交换两数。

~~~c
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
**重新开辟一块大小相同的空间，遍历数组，是偶数就将
**该数存到数组的前面，是奇数
**就存到数组的后边。
***/
int* sortArrayByParity(int* A, int ASize, int* returnSize) {

    *returnSize = ASize;
    int* tmp = (int*)malloc(sizeof(int)*(ASize));
    int i = 0;
    int begin = 0;
    int end = ASize - 1;
    for(i = 0; i < ASize; i++){
        if(A[i]%2 == 0){
            tmp[begin] = A[i];
            begin++;
        }
        else{
            tmp[end] = A[i];
            end--;
        }
    }
    return tmp; 
}
~~~

~~~C
/******code_2******/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int begin = 0;
    int end = ASize - 1;
    *returnSize = ASize;
    while(begin != end){
        while(begin < end && begin != end){
        if(A[begin] % 2 != 0){
           break;
        }
         begin++;
    }
        while(end >= 0 && begin != end){
            if(A[end] % 2 == 0){
                break;
            }
            end--;
        }
        int tmp = A[end];
        A[end] = A[begin];
        A[begin] = tmp;
    }
    return A;
}
~~~

