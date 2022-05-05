### 日期 2022 / 5 / 5
<img width="1024" alt="截屏2022-05-05 14 12 01" src="https://user-images.githubusercontent.com/73943232/166870985-a94f2de2-85e1-4db8-877f-fd9095a11518.png">
[题目链接]<http://acm.hdu.edu.cn/showproblem.php?pid=2193>

# 题目
>An AVL tree is a kind of balanced binary search tree. Named after their inventors, Adelson-Velskii and Landis, they were the first dynamically balanced trees to be proposed. Like red-black trees, they are not perfectly balanced, but pairs of sub-trees differ in height by at most 1, maintaining an O(logn) search time. Addition and deletion operations also take O(logn) time. 
>Definition of an AVL tree 
>An AVL tree is a binary search tree which has the following properties: 
>1. The sub-trees of every node differ in height by at most one. 
>2. Every sub-tree is an AVL tree.

<img width="316" alt="截屏2022-05-05 14 12 53" src="https://user-images.githubusercontent.com/73943232/166871077-c9c1385c-6b29-4e48-aa06-667ee9ee06f0.png">


>Balance requirement for an AVL tree: the left and right sub-trees differ by at most 1 in height.An AVL tree of n nodes can have different height.
>For example, n = 7:
<img width="396" alt="截屏2022-05-05 14 13 01" src="https://user-images.githubusercontent.com/73943232/166871085-15644f3d-4ccd-4daa-8e38-531b61229cc2.png">


>So the maximal height of the AVL Tree with 7 nodes is 3.
>Given n,the number of vertices, you are to calculate the maximal hight of the AVL tree with n nodes.

## Input
>Input file contains multiple test cases. Each line of the input is an integer n(0<n<=10^9).
>A line with a zero ends the input.
 

## Output
>An integer each line representing the maximal height of the AVL tree with n nodes.
 

## Sample Input
>1
>
>2
>
>0
 

## Sample Output
>0
>
>1
 
# 解题思路
>题目的意思是要求给定n个结点，求出所能构建的AVL树的最大高度。我们知道关于平衡二叉树最小节点最大高度有一个公式，设height[i]为高度为i的平衡二叉树的最小结点数，则height[i] = height[i - 1] + height[i - 2] + 1；
>所以我们先进行打表，然后得到答案.

# 代码演示
```cpp
#include <iostream>

using namespace std;
const int maxn = 50;
int height[maxn];

int main() {
  int n;
  height[0] = 1;
  height[1] = 2;
  for (int i = 2; i < maxn; i++) {
    height[i] = height[i - 1] + height[i - 2] + 1;
  }
  while (cin >> n && n) {
    int cnt = -1;
    for (int i = 0; i < maxn; i++) {
      if (n >= height[i]) {
        cnt++;
      } else {
        break;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

```
