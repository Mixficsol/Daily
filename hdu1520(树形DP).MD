日期 2022 / 03 / 04

## 题目

>Description
>
>There is going to be a party to celebrate the 80-th Anniversary of the Ural State University. The University has a hierarchical structure of employees. It means that the supervisor relation forms a tree rooted at the rector V. E. Tretyakov. In order to make the party funny for every one, the rector does not want both an employee and his or her immediate supervisor to be present. The personnel office has evaluated conviviality of each employee, so everyone has some number (rating) attached to him or her. Your task is to make a list of guests with the maximal possible sum of guests' conviviality ratings.
>
> Input
>
>Employees are numbered from 1 to N. A first line of input contains a number N. 1 <= N <= 6 000. Each of the subsequent N lines contains the conviviality rating of the corresponding employee. Conviviality rating is an integer number in a range from -128 to 127. After that go N – 1 lines that describe a supervisor relation tree. Each line of the tree specification has the form: 
>L K 
>It means that the K-th employee is an immediate supervisor of the L-th employee. Input is ended with the line 
>0 0 
>
>Output
>
>Output should contain the maximal sum of guests' ratings.
>
> Sample Input
>
>7
>
>1
>
>1
>
>1
>
>1
>
>1
>
>1
>
>1
>
>1 3
>
>2 3
>
>6 4
>
>7 4
>
>4 5
>
>3 5
>
>0 0
>
> Sample Output
> 
>5

## 解题思路
> 给你一棵关系树，让你从中选择若干个人，这些人之间不能有直接的上下级关系，要求最后的到的权值最大.这里我用到的是树形DP，把这些人的上下级关系利用一颗
> 树表示，从根节点开始遍历，每次对这个结点进行选择或不选择的判断然后对他的子节点进行dfs，到底端时开始返回值，最终只需要解决根节点选择或不选择的问题
> 这里要注意的是当i结点不选择时，他的子节点也可以是选择或者不选择从中利用一个max取到最大值，而对于已经选择的结点，那么它的子节点是一定不能选择的。

```cpp
#include <bits/stdc++.h>

#define INF 0x7fffffff
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, -1, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
const int maxn = 1e6 + 10;
const int N = 7000;
using namespace std;
vector<int> v[N]; // 用来存每个结点的子节点
int dp[N][2]; // dp[i][1]选择第i结点的最优解，dp[i][0]不选第i结点的最优解
int father[N]; // 存取每个结点指向的父节点
int value[N]; // 存取每个结点的值

void dfs(int root) {
  dp[root][0] = 0;  // 不选根节点的情况
  dp[root][1] = value[root]; // 选择根节点的情况
  for (int i = 0; i < v[root].size(); i++) {
    int son = v[root][i];  // 提取出子节点
    dfs(son);  // 对子节点dfs
    dp[root][0] += max(dp[son][0], dp[son][1]); //根节点不选（子节点选或不选）
    dp[root][1] += dp[son][0]; //选择根节点且子节点不选
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, y, z;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      cin >> value[i]; // 存入各个节点的值
      format(father); // 初始化父节点使其为-1
      v[i].clear();  // 初始化容器
    }
    while (cin >> x >> y && x && y) {
      father[x] = y;  // 将x的父节点定义为y
      v[y].push_back(x); // 将x存进y节点容器中
    }
    z = 1;
    while (father[z] != -1) {
      z = father[z];   // 找到根节点
    }
    dfs(z);
    cout << max(dp[z][0], dp[z][1]) << endl;  // 从根节点判断答案
  }
  return 0;
} 
