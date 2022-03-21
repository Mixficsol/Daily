日期 2022 / 03 / 21

[参考链接]<https://blog.csdn.net/qq_39861441/article/details/87566503>

[学习视频]<https://www.bilibili.com/video/BV1j64y1R7yK/?spm_id_from=333.788.recommend_more_video.-1>

## 题目
<img width="889" alt="截屏2022-03-21 20 32 08" src="https://user-images.githubusercontent.com/73943232/159261634-083ad032-f2e6-49da-a0da-2cba87013a31.png">

## 解题思路
> 这个题目是最大流的入门题，题意是题中N为水沟数，M为水沟的顶点，接下来Si,Ei,Ci分别是水沟的起点，终点以及其容量。求源点1到终点M的最大流速。做题之前我们需要知道三个属性分别是容量，空闲量
> 以及流量，容量指的是一个水管单位时间能流过的最大的水量，流量指的是单位时间内实际流过水管的水量，空闲量就是容量-流量即单位时间内还可以流过的水量.这题用的是Dinic算法，时间复杂度是O(V^2*E)
> 这里我们需要知道一个定理就从源流出的流量一定会等于在终点得到的流量(即没有水管漏水的情况下)Dinic的思路是构造一条反向边先BFS找到所有的增广路(即构造Level图)然后利用
> dfs进行求堵塞流，阻塞流指的是使所有水流不再能流过的流，阻塞流不一定是最大流，但是最大流一定是阻塞流.
![9D048AA77612CC74254576FE78610D6A](https://user-images.githubusercontent.com/73943232/159265117-07c2a6af-3e8c-4924-be72-8863124589f1.jpg)

## 代码演示
```cpp
#include <bits/stdc++.h>


#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, 0, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
const int maxn = 1e6 + 10;
const int INF = 0x3f3f3f3f;
using namespace std;
int map1[210][210]; //点i到j的空闲量
int n, m; 
int dis[210]; // 用于构造Level图
queue<int> q;


int bfs() {  // 用来构造Level图，即第几层
	while (!q.empty()) {
		q.pop();
	}
	format(dis);
	dis[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 1; i <= m; i++) {
			if (map1[t][i] && !dis[i]) {
				q.push(i);
				dis[i] = dis[t] + 1;
				if (i == m) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int dfs(int v, int cap) { //v是当前的点，cap是容量
	if (v == m) {
		return cap;
	}
	int tp = cap; // tp是空闲量
	for (int i = 1; i <= m && tp; i++) {
		if (map1[v][i] && dis[i] == dis[v] + 1) {
			int t = dfs(i, min(tp, map1[v][i]));
			map1[v][i] -= t;
			map1[i][v] += t; // 反向边的建立
			tp -= t;
		}
 	}
    return cap - tp; //容量-空闲量即就是流量
}



void Dinic() {
	int flow = 0;
	while (bfs()) {
		flow += dfs(1, INF);
	}
	cout << flow << endl;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y, z;
	while (cin >> n >> m) {
		format(map1);
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			map1[x][y] += z;
		}
		Dinic();
	}
}
