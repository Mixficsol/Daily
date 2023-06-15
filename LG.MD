# LG
## LG1616
> 题目背景
题目描述
LiYuxiang 是个天资聪颖LG子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同种类的草药，采每一种都需要一些时间，每一种也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总>价值最大。”

### 题解
> 这个题思路比较简单就是用的是01背包，不过刚开始还是WA了好几遍后来发现是数据的问题，在01背包里面，这里需要用到是滚动数组，选择的时候就是`dp[i - w[i]] > + v[i]`.不选的情况是`dp[i]`

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int w[10010], v[10010];
long long dp[10000010];

int main(int argc, char *argv[]) {
	long long t, m;
	cin >> t >> m;
	for (long long i = 1; i <= m; i++) {
		cin >> w[i] >> v[i];
	}
	for (long long i = 1; i <= m; i++) {
		for (int j = w[i]; j <= t; j++) { 
			if (j >= w[i]) {
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[t] << endl;
	return 0;
}
```

## LG 2196
> 在一个地图上有N(N≤20)，每个地窖中埋有一定数量的地雷。同时，给出地窖之间的连接路径。当地窖及其连接的数据给出之后，某人可以从任一处开始挖地雷，然后可以沿着指出的连接往下挖（仅能选择一条路径），当无连接时挖地雷工作结束。设计一个挖地雷的方案，使某人能挖到最多的地雷。

### 题解
> 这题用的是一个二维数组储存各地雷之间的连接情况然后dp[i] += a[i]去求dp的最大值 


```cpp
#include <iostream>

using namespace std;

int n, num;
int a[10010];
int b[1010][1010];
int dp[1010];
int pre[1010];

void solve(int k) {
	if (pre[k] == 0) {
		cout << k;
		return;
	}
	solve(pre[k]);
	cout << " " << k;
}

int main(int argc, char *argv[]) {
	int k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		b[i][i] = 1;
		for (int j = i + 1; j <= n ; j++) {
			cin >> b[i][j];
			b[j][i] = b[i][j];
		}
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (b[i][j] && dp[j] > dp[i]) {
				dp[i] = dp[j];
				pre[i] = j;
			}
		}
		dp[i] += a[i];
		if (dp[i] > num) {
			num = dp[i];
			k = i;
		}
	}
	solve(k);
	cout << endl << num << endl;
	return 0;
}
```

## LG 1216

> 写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以走到左下方的点也可以到达右下方的点。
>         7 
      3   8 
    8   1   0 
  2   7   4   4 
4   5   2   6   5 

### 题解
> 这题我是从下往上运用dp进行更新的，然后递推的公式就是：
`dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+s[i][j];`
所以最终的答案就在`dp[1][1]`
 
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int a[1010][1010];
int b[1010][1010];
int main(int argc, char *argv[]){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			b[i][j] = max(b[i + 1][j], b[i + 1][j + 1]) + a[i][j];
		}
	}
	cout << b[1][1] << endl;
	return 0;
}

```


## LG 1048
> 辰辰是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”
如果你是辰辰，你能完成这个任务吗？

### 题解
> 这个题就是一个简单的背包问题，每次选择都是当前最优的情况如果当前可选的话递推式就是：
`dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);`
否则就是之前的最优情况：
`dp[i][j]=dp[i - 1][j];`
```cpp
#include <iostream>

using namespace std;

int w[105], v[105];
int dp[105][1005];

int main(int argc, char *argv[]) {
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = t; j >= 0; j--) { 
			if (j >= w[i]) {
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			} else {
				dp[i][j]=dp[i - 1][j];
			}              
		}
	}
	cout << dp[m][t] << endl;
	return 0;
}
```
