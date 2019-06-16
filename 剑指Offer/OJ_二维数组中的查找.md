# OJ_二维数组中的查找

[二维数组中的查找](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

>在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。



<font color = red size = 5>思路：</font>

- 一行一行的查，只有找到了才返回true，遍历结束还找不到就返回false。这样做的时间复杂度太大O(n2)，会做一些无用的操作，方法二是优化。
- 对于每一行数组来说，都是有序的，所以可以在每一行使用二分查找接口，时间复杂度O(nlog2n)。

**题解：**

~~~C
/*方法一*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for(size_t i = 0; i < array.size(); i++){
            for(size_t j = 0; j < array[i].size(); j++){
                if(target == array[i][j]){
                    return true;
                }
            }
        }
    return false;
    }
};
~~~

~~~C
/*方法二*/
class Solution {
public:
    bool BinaryFind(int target, vector<int> arr, int begin, int end){
        while(begin <= end){
            int mid = (end + begin) >> 1; 
            if(target == arr[mid]){
                return true;
            }
            if(target < arr[mid]){
                end = mid - 1;
            }
            if(target > arr[mid]){
                begin = mid + 1;
            }
        }
        return false;
    }
    
    bool Find(int target, vector<vector<int> > array) {
        for(size_t i = 0; i < array.size(); i++){
            if(BinaryFind(target, array[i], 0, array[i].size() - 1)){
                return true;
            }
        }
        return false;
    }
};
~~~



