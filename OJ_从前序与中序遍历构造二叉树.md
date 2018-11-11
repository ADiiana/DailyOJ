# OJ_从前序与中序遍历构造二叉树

OJ链接：[根据一棵树的前序遍历与中序遍历构造二叉树。](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

> 题目表述
>
> 根据一棵树的前序遍历与中序遍历构造二叉树。
>
> **注意:**
> 你可以假设树中没有重复的元素。
>
> 例如，给出
>
> ```
> 前序遍历 preorder = [3,9,20,15,7]
> 中序遍历 inorder = [9,3,15,20,7]
> ```
>
> 返回如下的二叉树：
>
> ```C
>     3
>    / \
>   9  20
>     /  \
>    15   7
> ```

​	这道题用递归的思想，把一个树分成根节点，左子树，右子树。在相应的把左子树和右子树分成左右子树的根节点，左右子树的左右子树........以此类推

​	解决二叉树的问题，<font color = red>递归</font>的思想很重要。

​	已知一个数的前序遍历，也就是知道这棵树的根节点以及所有子树的根节点，之前做过一道题，已知一个数组，数组里存放的是这棵树前序遍历的结果，<font color = red>但在那个数组中，我们可以判断出哪个根节点是叶子节点</font>。可是这道题的前序遍历的结果并没有给出判断叶子结点的条件，能获取到的信息<font color = blue>知道前序遍历的第一个就是这棵树的根节点，以及每个子树的根节点</font>。<font color = brown size = 4>怎么能判断出每个子树的根结点有没有左右孩子以及左右孩子分别是哪个，就需要用到中序遍历。</font>

​	<font color = red size = 5>总结：</font>

- 由**前序遍历**得到每个子树的根节点：

  - 变量pindex用来追踪前序遍历数组中的结点，每次递归通过指针改变pindex的值

- 由**中序遍历**判断每个子树的左右孩子是否存在，以及左右孩子分别是哪个元素：
  - rootindex、inbegin、inend、用来追踪中序遍历数组中结点所在的下标，以及该节点左右子树的下标的范围。

  也就是说，我们用前序遍历的顺序，依赖于中序遍历来判断和构建这棵树，代码如下：

<font size = 4 color = purple>遇到的问题:</font>

- 写代码时，没有注意人家给的接口returnSize，而是自己定义了一个size变量，而实际上，OJ代码在运行时，只是调用人家自己的接口，这个时候，就算为计算出了size的大小，但是并没有赋值给共有的接口，程序还是编译不通过的。

~~~C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    //递归多少次，数组就有多大。
    *returnSize = myreturnSize(root);       //一定要注意人家给的函数接口
    int Size = *returnSize;     
    int* array = (int*)malloc(sizeof(int)*Size);
    int index = 0;
    
    _pre(root, array, &index);
    int i = 0;
    
    for(; i < Size; i++){
        printf("%d ",array[i]);
    }
    
    if(array == NULL)
        printf("4");
    
    return array;
}

void _pre(struct TreeNode* root, int* array, int* pindex){
    if(root == NULL)
        return;
    array[*pindex] = root->val;
   // printf("%d ", root->val);
    (*pindex)++;
    _pre(root->left, array, pindex);
    _pre(root->right, array, pindex);
}

int myreturnSize(struct TreeNode* root){
    if(root == NULL)
        return 0;
    return 1 + myreturnSize(root->left) + myreturnSize(root->right);
}

~~~















