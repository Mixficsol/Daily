写这个题之前我们必须要知道的是对于一个字符串，当他添加或者删除一个字符可以成为回文串时
，这两者就都是等价的了，所以开始我们就得找到删除和增添的最小值，这题是一个区间dp问题从
枚举长度终点起点开始，要注意的就是当前后的字符相等时此时更长的那一个的代价就是更小的那一个的代价。
#include <iostream>
using namespace std;
int n, m, ans;
int a[2010], b[2010];
char c;
char s[2010];
int dp[2010][2010];
int main(int argc, char *argv[]) {
 	int x, y;
 	ans = 0;
 	cin >> n >> m;
 	cin >> s;
 	for (int i = 0 ; i < n; i++) {
 		cin >> c >> x >> y;
 		a[c - 'a'] = x;
 		b[c - 'a'] = y;
 		a[c - 'a'] = min(x, y);
 	}
 	for (int i = 1; i < m; i++) {
 		for (int j = i - 1; j >= 0; j--) {
 			if (s[j] == s[i]) {
 				dp[j][i] = dp[j + 1][i - 1];
 			} else {
 				dp[j][i] = min(dp[j][i - 1] + a[s[i] - 'a'], dp[j + 1][i] + a[s[j] - 'a']);
 			}
 		}
 	}
 	cout << dp[0][m - 1] << endl;
 	return 0;
}
