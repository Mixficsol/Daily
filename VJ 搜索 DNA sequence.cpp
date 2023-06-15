这个题目是用到IDA迭代搜索，首先记录下最长的序列，然后一个一个加判断使用有排列好的情况
在dfs中利用pos来判断每个string中各个节点是否排列完成，然后在dfs后进行还原操作，最终
利用ans判断最终序列是否排列完成

#include <bits/stdc++.h>

#define INF 0x7fffffff
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, 0, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
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
	string s;
	int len;
} a[10];

string c = "ACGT";
int t, n, l, sum;
int pos[10];

int get() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, a[i].len - pos[i]);
	}
	return ans;
}

int dfs(int step) {
	if (step + get() > sum) {
		return 0;
	}
	if (!get()) {
		return 1;
	}
	int b[10];
	rep(i, 0, n - 1) {
		b[i] = pos[i];
	}
	rep(i, 0, 3) {
		int flag = 0;
		rep(j, 0, n - 1) {
			if (a[j].s[pos[j]] == c[i]) {
				flag = 1;
				pos[j]++;
			}
		}
		if (flag) {
			if (dfs(step + 1)) {
				return 1;
			}
			rep(i, 0, n - 1) {
				pos[i] = b[i];
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		l = 0;
		sum = 0;
		rep(i, 0, n - 1) {
			cin >> a[i].s;
			a[i].len = a[i].s.size();
			l = max(l, a[i].len);
			pos[i] = 0;
		}
		sum = l;
		while (1) {
			if (dfs(0)) {
				break;
			}
			sum++;
		}
		cout << sum << endl;
	}
	return 0;
}
