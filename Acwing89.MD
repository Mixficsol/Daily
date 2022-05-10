### 日期 2021 / 10 / 19
# 题目
[题目链接]<https://www.acwing.com/problem/content/91/>

> 求a的b次方对p取模的值。
> 
> 输入格式
> 
> 三个整数 a,b,p,在同一行用空格隔开。
> 
> 输出格式
> 
> 输出一个整数，表示a^b mod p的值。
> 
> 数据范围
> 
> 0≤a,b≤109
> 
> 1≤p≤109
> 
> 输入样例：
> 
> 3 2 7
> 输出样例：
> 
> 2



## 解题思路
> 首先暴力解的话肯定会超出数据范围，所以用的是快速幂算法，我们知道任何一个正整数可以
> 唯一表示为若干指数不重复的2的次幂的和，如果要求a^b的话我们假设b为11，那么它(b)可以表示
> 为二进制为1011;x的11次方可以分解为x的1次乘x的2次再乘x的8次,我们通过对b进行>>运算
> 可以判断出当前位是否需要乘，从而得出答案。


## 代码演示
```cpp
#include <bits/stdc++.h>

#define INF 0x7fffffff
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, 0, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
const int maxn = 1e6 + 10;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c, p;
  cin >> a >> b >> p;
  c = 1;
  while (b) {
    if (b & 1) {
      c = c * a % p;
    }
    a = a * a % p;
    b >>= 1;
  }
  cout << c % p << endl;
  return 0;
}

