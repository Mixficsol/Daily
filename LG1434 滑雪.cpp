这个题我用的是深搜，对于每一个点来说往下面搜索，为了防止TLE我们得采用记忆化搜索找到的点之间返回
之前最优的答案，然后我们遍历从每一个结点开始滑雪的路径，然后通过两层for循环来找到最终的答案

#include <iostream>
#include <cmath>
using namespace std;
int r, c, ans;
int sx[] = {1, 0, -1, 0};
int sy[] = {0, 1, 0, -1};
int a[1010][1010];
int dp[1010][1010];
int solve(int x, int y) {
 	if (dp[x][y]) {
 		return dp[x][y];
 	}
 	dp[x][y] = 1;
 	for (int i = 0; i < 4; i++) {
 		int tx = sx[i] + x;
 		int ty = sy[i] + y;
 		if (tx > 0 && ty > 0 && tx <= r && ty <= c && a[x][y] > a[tx][ty]) {
 			solve(tx, ty);
 			dp[x][y] = max(dp[x][y], dp[tx][ty] + 1);
 		}
 	}
 	return dp[x][y];
}
int main(int argc, char *argv[]) {
 	cin >> r >> c;
 	for (int i = 1; i <= r; i++) {
 		for (int j = 1; j <= c; j++) {
 			cin >> a[i][j];
 		}
 	}
 	for (int i = 1; i <= r; i++) {
 		for (int j = 1; j <= c; j++) {
 			ans = max(ans, solve(i, j));
 		}
 	}
 	cout << ans << endl;
 	return 0;
}
