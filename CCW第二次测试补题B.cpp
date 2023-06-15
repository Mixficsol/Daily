这个题的意思是给出m个区段并且要求在规定时间内怎么选择区段使得价值最大，那么这题的
话我们就先排个序按照开始时间结束时间排序，最后通过两个for循环进行dp，就是一个正常
的背包dp问题。然后再找出最大值

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1010];
int n, m, r;
struct fin {
 	int value;
 	int begin;
 	int end;
} a[1010];
bool cmp(fin &a, fin &b) {
 	if (a.begin != b.begin) {
 		return a.begin < b.begin;
 	} else {
 		return a.end < b.end;
 	}
}
int main() {
 	while (scanf("%d %d %d", &n, &m, &r) != EOF) {
 		for (int i = 0; i < m; i++) {
 			scanf("%d %d %d", &a[i].begin, &a[i].end, &a[i].value);
 			a[i].end += r;
 		}
 		sort(a, a + m, cmp);
 		memset(dp, 0, sizeof(dp));
 		for (int i = m - 1; i >= 0; i--) {
 			dp[i] = a[i].value;
 			for (int j = i + 1; j < m; j++) {
 				if (a[j].begin >= a[i].end) {
 					dp[i] = max(dp[i], dp[j] + a[i].value);
 				}
 			}
 		}
 		int ans = 0;
 		for (int i = 0; i <= m - 1; i++) {
 			ans = max(dp[i], ans);
 		}
 		cout << ans << endl;
 	}
 	return 0;
}
