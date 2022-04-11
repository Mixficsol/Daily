日期 2022 / 04 / 11
<img width="1056" alt="截屏2022-04-11 11 15 58" src="https://user-images.githubusercontent.com/73943232/162659362-6b829af2-68a4-457c-8382-8c192d9eabfa.png">

# 题目
## The order of a Tree
>
> Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
> Total Submission(s): 5111    Accepted Submission(s): 2543
>
### Problem Description
>As we know,the shape of a binary search tree is greatly related to the order of keys we insert. To be precisely:
>1.  insert a key k to a empty tree, then the tree become a tree with
>only one node;
>2.  insert a key k to a nonempty tree, if k is less than the root ,insert
>it to the left sub-tree;else insert k to the right sub-tree.
>We call the order of keys we insert “the order of a tree”,your task is,given a oder of a tree, find the order of a tree with the least lexicographic order that generate the same tree.Two trees are the same if and only if they have the same shape.
>
### Input
>There are multiple test cases in an input file. The first line of each testcase is an integer n(n <= 100,000),represent the number of nodes.The second line has n intergers,k1 to kn,represent the order of a tree.To make if more simple, k1 to kn is a sequence of 1 to n.
>
### Output
>One line with n intergers, which are the order of a tree that generate the same tree with the least lexicographic.
>
### Sample Input
>4
>
>1 3 4 2
>
### Sample Output
>1 3 2 4

# 解题思路
> 这个题目的意思是给出一个二叉搜索树(BST)的建树序列，要求得到一个字典序最小的建树序列，并且所建的树的结构和给出的建树序列所建的树结构一样，我们知道二叉搜索树有一个特点
> 即对于一个根节点来说，若他的左子树非空，那么它左子树上所有的结点大小都小于根节点，若他的右子树非空，那么它右子树上所有的结点大小都大于根节点.所以要求的字典序最小的序列
> 我们可以得出利用先序遍历，根左右进行遍历，由题目给出的序列建树，然后进行先序的遍历得到答案

# 代码演示
```cpp
#include <iostream>

using namespace std;

typedef struct Tree {
  Tree *left;
  Tree *right;
  int value;
}Tree;

Tree *root;

Tree* Create(int x) {  // 建树
  Tree* tree = (Tree*)malloc(sizeof(Tree));
  tree->left = NULL;
  tree->right= NULL;
  tree->value = x;
  return tree;
}

Tree* Insert(Tree *t, int x) {   // 插入
  if (t == NULL) {
      t = Create(x);
  } else {
    if (t->value > x) {
      t->left = Insert(t->left, x);
    } else {
      t->right = Insert(t->right, x);
    }
  }
  return t;
}

void Print(Tree *t) {  // 先序遍历
  if (t != NULL) {
    if (t == root) {
        cout << t->value;
    } else {
      cout << " " << t->value;
    }
    Print(t->left);
    Print(t->right);
  }
}

int main() {
  int n, x;
  while (cin >> n) {
    root = NULL;
    for (int i = 0; i < n; i++) {
      cin >> x;
      root = Insert(root, x);
    }
    Print(root);
    cout << endl;
  }
  return 0;
}








