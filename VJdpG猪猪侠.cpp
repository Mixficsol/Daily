这题就是一个矩阵嵌套的模板题，思路是先把每一个长宽存起来然后进
行dp把每一个套在最外面的信封所能容纳的值求出然后再用一个数组把
路径存下来，最终求得最大的信封下所能套中的信封数以及路径
#include <iostream> // DAG dp 矩阵嵌套
#include <cstring>
using namespace std;
int n;
int dp[5100];
int path[5100];
struct fin{
 	int x;
 	int y;
} a[5100];
int solve(int k) {
 	if (dp[k]) {
 		return dp[k];
 	}
 	dp[k] = 1;
 	for (int i = 1; i <= n; i++) {
 		if (a[k].x < a[i].x && a[k].y < a[i].y) {
 			if (dp[k] < solve(i) + 1) {
 				dp[k] = dp[i] + 1;
 				path[k] = i;
 			}
 		}
 	}
 	return dp[k];
}
void Print(int i) {
 	cout << i << " ";
 	if (path[i]) {
 		Print(path[i]);
 	}
}
int main(int argc, char *argv[]) {
 	int ans, index1, k, m;
 	ans = 0;
 	cin >> n >> k >> m;
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i].x >> a[i].y;
 	}
 	for (int i = 1; i <= n; i++) {
 		if (k < a[i].x && m < a[i].y) {
 			solve(i);
 			if (ans < dp[i]) {
 				index1 = i;
 				ans = dp[i];
 			}
 		}
 	}
 	cout << ans << endl;
 	if (ans != 0) {
 		Print(index1);
 	}
 	return 0;
}
