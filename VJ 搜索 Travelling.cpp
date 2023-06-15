#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, 0, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
#define maxn 15
using namespace std;

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			w = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}

struct fin {
	int num;
	int state;
} start[maxn];

int n, m;
int cost[maxn][maxn];
int dp[maxn][60000];
int a[maxn];

void solve() {
	queue<fin> q;
	for (int i = 0; i < n; i++) {
		q.push(start[i]);
	}
	int ans = INF;
	while (q.size()) {
		fin t = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (i == t.num || cost[i][t.num] == INF) {
				continue;
			}
			if (!i && t.state % 3 == 2) {
				continue;
			}
			if (i && ((t.state % a[i + 1]) - (t.state % a[i])) / a[i] == 2) {
				continue;
			}
			if (dp[i][t.state + a[i]] > dp[t.num][t.state] + cost[t.num][i]) {
				dp[i][t.state + a[i]] = dp[t.num][t.state] + cost[t.num][i];
				fin k;
				k.num = i;
				k.state = t.state + a[i];
				q.push(k);
				bool flag = false;
				int tmp = t.state + a[i];
				if (dp[i][tmp] < ans) {
					for (int j = 0; j < n; j++) {
						if (tmp % 3 == 0) {
							flag = true;
							break;
						} else {
							tmp /= 3;
						}
					}
					if (!flag) {
						ans = dp[i][t.state + a[i]];
					}
				}
			}
		} 
	}
	if (ans == INF) {
		ans = -1;
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	a[0] = 1;
	int x, y, z;
	for (int i = 1; i < 12; i++) {
		a[i] = a[i - 1] * 3;
	}
	while (cin >> n >> m) {
		memset(cost, 0x3f, sizeof(cost));
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> z;
			cost[x - 1][y - 1] = cost[y - 1][x - 1] = min(cost[x - 1][y - 1], z);
		}
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i < n; i++) {
			dp[i][a[i]] = 0;
			start[i].num = i;
			start[i].state = a[i];
		}
		solve();
	}
}
