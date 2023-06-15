这题是一个完全背包的变形，对于不能吃药的情况自然就是把输的经验给累加起来，对于能赢的情况选择吃药或者不吃药然后求出一个最大值，背包思想就是
#include <iostream>
using namespace std;
int win[1010], lose[1010], used[1010];
long long  dp[1010];
int n, x;
int main(int argc, char *argv[]) {
 	cin >> n >> x;
 	for (int i = 1; i <= n; i++) {
 		cin >> lose[i] >> win[i] >> used[i];
 	}
 	for (int i = 1; i <= n; i++) {
 		for (int j = x; j >= used[i]; j--) {
 				dp[j] = max(dp[j] + lose[i], dp[j - used[i]] + win[i]);
 		}
 		for (int j = used[i] - 1; j >= 0; j--) {
 			dp[j] += lose[i];
 		}
 	}
 	cout << dp[x] * 5 << endl;
 	return 0;
}
