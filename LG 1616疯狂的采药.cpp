这个题是完全背包问题这里面的物品是可以多次采用的所有我第二次的for循环就得改成(int j = w[i]; j <= t; j++）来实现最终的答案
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
