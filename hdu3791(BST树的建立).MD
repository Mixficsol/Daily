日期 2022 / 04 / 17
<img width="1004" alt="截屏2022-04-17 11 02 41" src="https://user-images.githubusercontent.com/73943232/163698442-23cfc847-d688-49c9-ae80-e2d6ecbd3bd9.png">

# 题目
## 二叉搜索树
>
>Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
>
>Total Submission(s): 11184    Accepted Submission(s): 4862
>
## Problem Description
>判断两序列是否为同一二叉搜索树序列
>
## Input
>开始一个数n，(1<=n<=20) 表示有n个需要判断，n= 0 的时候输入结束。
>接下去一行是一个序列，序列长度小于10，包含(0~9)的数字，没有重复数字，根据这个序列可以构造出一颗二叉搜索树。
>接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断这两个序列是否能组成同一颗二叉搜索树。
> 
## Output
>如果序列相同则输出YES，否则输出NO
>
## Sample Input
>2
>
>567432
>
>543267
>
>576342
>
>0
>
## Sample Output
>YES
>
>NO

# 题目大意
> 题目的意思是给定一个原始的二叉搜索树的序列，接下来给出n个二叉搜索树序列，问给出的序列和原始的序列建的树是否一样.我刚开始的想法是把多组序列建的树利用
> 数组存起来，然后利用遍历方式(先序遍历，中序遍历，后序遍历)来判断他建的树是否一样.

# 代码演示
```cpp
#include <iostream>
#include <string>
using namespace std;

int a[15];
int b[15];
int tree[1010], tree1[1010]; // 用来存建树的序列

void Build_Tree(int tree[], int pos, int value) { //建树
  if (tree[pos] == -1) {
    tree[pos] = value;
    return;
  }
  if (value < tree[pos]) {
    Build_Tree(tree, pos * 2, value);
  } else {
    Build_Tree(tree, pos * 2 + 1, value);
  }
}

int main() {
  int n, m;
  string s;
  while (cin >> n && n) {
    cin >> s;
    memset(tree, -1, sizeof(tree));
    for (int i = 0; i < s.size(); i++) {
      Build_Tree(tree, 1, s[i] - '0');
    }
    while (n--) {
      cin >> s;
      memset(tree1, -1, sizeof(tree1));
      for (int i = 0; i < s.size(); i++) {
        Build_Tree(tree1, 1, s[i] - '0');
      }
      bool flag = true;
      for (int i = 0; i < 1010; i++) {
        if (tree[i] != tree1[i]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
```









