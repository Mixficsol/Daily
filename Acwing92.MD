日期 2021 / 10 / 19
# 题目
[题目链接]<https://www.acwing.com/problem/content/94/>
> 从 1∼n
>  这 n
> 个整数中随机选取任意多个，输出所有可能的选择方案。
> 
> 输入格式
> 
> 输入一个整数 n
> 
> 输出格式
> 
> 每行输出一种方案。
> 
> 同一行内的数必须升序排列，相邻两个数用恰好 1个空格隔开。
> 对于没有选任何数的方案，输出空行。
> 本题有自定义校验器（SPJ），各行（不同方案）之间的顺序任意。
> 
> 数据范围
> 
> 1≤n≤15
> 
> 输入样例：
> 
> 3
> 输出样例：
> 
> 
> 3
> 2
> 2 3
> 1
> 1 3
> 1 2
> 1 2 3

## 解题思路
> 这个是一个dfs类型的题，题目大意就是选择n，然后需要你找出1~n里面的所有排列情况
> 利用dfs我们可以从1开始枚举，对于下一个我们可以有两种选择，一是选择它放进此排列
> 中，另一种自然是不放入，当前枚举的数字大于n的时候停止，然后输出这个排列，这样
> 从1开始枚举的话就不需要担心乱序的情况。

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

int used[21];
int n;

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			w = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}

void dfs(int u) {
	if (u > n) {
		for (int i = 1; i <= n; i++) {
			if (used[i] == 1) {
				cout << i << ' ';
			}
		}
		cout << endl;
		return;
	}
	used[u] = 1;
	dfs(u + 1);
	used[u] = 0;
	
	used[u] = 2;
	dfs(u + 1);
	used[u] = 0;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	dfs(1);
	return 0;
	
}
```
