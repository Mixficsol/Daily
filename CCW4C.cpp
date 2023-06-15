这个题是一道状态压缩dp利用的是把每一科目当成一个二进制的表示为然后利用两个for循环进行遍历，如果之前
做了这个作业的话就返回到上一层判断他的扣的分数和当前的状态进行比较得到最终的答案，然后利用now和past
存取路径输出完成的顺序


#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
 
const int INF = 1 << 30;
 
struct fin {
	string name;
	int dead;
	int cost;
} a[50];
 
struct Mix {
	int time;
	int score;
	int pre;
	int now;
} dp[1 << 15];
 
int main(int argc, char *argv[]) {
	int t, i, j, s, n, end;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> a[i].name >> a[i].dead >> a[i].cost;
		}
		end = 1 << n; //总共有多少种情况
		for (s = 1; s < end; s++) {
			dp[s].score = INF;
			for (i = n - 1; i >= 0; i--) {
				int k = 1 << i;
				if (s & k) {
					int past = s - k;
					int st = dp[past].time + a[i].cost - a[i].dead;
					if (st < 0) {
						st = 0;
					}
					if (st + dp[past].score < dp[s].score) {
						dp[s].score = st + dp[past].score;
						dp[s].now = i;
						dp[s].pre = past;
						dp[s].time = dp[past].time + a[i].cost;
					}
				}
			}
		}
		stack<int> S;
		int k = end - 1;
		cout << dp[k].score << endl;
		while (k) {
			S.push(dp[k].now);
			k = dp[k].pre;
		}
		while (!S.empty()) {
			cout << a[S.top()].name << endl;
			S.pop();
		}
	}
 
	return 0;
}

