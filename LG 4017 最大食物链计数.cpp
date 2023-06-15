这个题我用的是拓扑排序，题目的意思是要求出最长的食物链个数，那么我的思路就是首先你求出入度为
0的点也就是生产者然后通过邻接表找到你的捕食者然后拓扑排序一层一层往上面找得到最终的结果有点
广搜的思想在里面

#include <iostream>
#include <queue>
const int mod = 80112002;
using namespace std;
int n, m, ans;
int a[5010], b[5010], c[5010];
int k[5010][5010];
int main(int argc, char *argv[]) {
 	int x, y;
 	queue<int> q;
 	cin >> n >> m;
 	for (int i = 1; i <= m; i++) {
 		cin >> x >> y;
 		k[x][y] = 1;
 		a[x]++;
 		b[y]++;
 	}
 	for (int i = 1; i <= n; i++) {
 		if (b[i] == 0) {
 			c[i] = 1;
 			q.push(i);
 		}
 	}
 	while (!q.empty()) {
 		int x = q.front();
 			q.pop();
 		for (int i = 1; i <= n; i++) {
 			if (k[x][i] == 0) {
 				continue;
 			}
 			c[i] += c[x];
 			c[i] %= mod;
 			b[i]--;
 			if (b[i] == 0) {
 				if (a[i] == 0) {
 					ans += c[i];
 					ans %= mod;
 					continue;
 				}
 				q.push(i);
 			}
 		}
 	}
 	cout << ans << endl;
 	return 0;
}
