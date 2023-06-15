这个题用到的是康托展开，利用1，2，3，4，5，6，7，8进行排列，求出每一个排列组合对应的位置，
再用逆康托展开求出某一个位置所对应的排列方式，预处理之后再输出我们要求的值进行判断即可.



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
	char s[8];
};

int d[3][8] = {{7, 6, 5, 4, 3, 2, 1, 0}, {3, 0, 1, 2, 5, 6, 7, 4}, {0, 6, 1, 3, 4, 2, 5, 7}};
char str[8], fir[9], sec[9];
int vis[60010];
string ans[60010];
int a[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

int gethash(char s[]) {
	int cnt, i, j;
	int hash = 0;
	for (i = 0; i < 8; i++) {
		cnt = 0;
		for (j = i + 1; j < 8; j++) {
			if (s[j] < s[i]) {
				cnt++;
			}
		}
		hash += cnt * a[8 - i - 1];
	}
	return hash;
}

void bfs() {
	int i, j;
	queue<fin> q;
	fin a, b;
	for (i = 0; i < 8; i++) {
		a.s[i] = i + '1';
	}
	int k = gethash(a.s);
	q.push(a);
	vis[k] = 1;
	q.push(a);
	while (q.size()) {
		a = q.front();
		q.pop();
		int Hash = gethash(a.s);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 8; j++) {
				b.s[j] = a.s[d[i][j]];
			}
			k = gethash(b.s);
			if (vis[k]) {
				continue;
			}
			vis[k] = 1;
			ans[k] = ans[Hash] + (char)('A' + i);
			q.push(b);
		}
	}
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bfs();
	while (scanf("%s%s", fir, sec) != EOF) {
		for (int i = 0; i < 8; i++) {
			str[fir[i] - '1'] = i + '1';
		}
		for (int i = 0; i < 8; i++) {
			sec[i] = str[sec[i] - '1'];
		}
		int Ans = gethash(sec);
		cout << ans[Ans] << endl;
	}
	return 0;
}
