这个题目是一个走迷宫的题目，但是引入炮台这个东西，所以我们先用struct存好每一个炮台的v和t
当我们遍历方向的时候，比如往北走，我们就需要向北判断是否有向南打来的炮，如果有炮台就计算他
从我们开始走到这个地方的时间和此时第一个炮是否到达这个方向，如果没到达就安全，如果到了，则
判断时间之前是否可以整除，可以整除说明不安全，然后照这个方式判断剩下的三个方向.


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

int dir[5][2] = {0, 1, 1, 0, 0, -1, -1, 0, 0, 0};
int map1[110][110];
bool vis[110][110][1010];

struct battery {
	char c;
	int t;
	int v;
} s[110][110];

struct fin {
	int x;
	int y;
	int step;
};

int n, m, k, l;
char ch;

void bfs() {
	fin a, b;
	queue<fin> q;
	int i, j, flag, dis, temp;
	a.x = a.y = a.step = 0;
	q.push(a);
	vis[0][0][0] = 1;
	while (q.size()) {
		a = q.front();
		q.pop();
		if (a.step > l) {
			break;
		}
		if (a.x == n && a.y == m) {
			cout << a.step << endl;
			return;
		}
		for (int i = 0; i < 5; i++) {
			b = a;
			b.x += dir[i][0];
			b.y += dir[i][1];
			b.step++;
			if (b.x < 0 || b.x > n || b.y < 0 || b.y > m) {
				continue;
			}
			
			if (!s[b.x][b.y].t && !vis[b.x][b.y][b.step] && b.step <= l) {   // 往北走看是否有向南射击的炮台
				flag = 1;
				for (int j = b.x - 1; j >= 0; j--) {
					if (s[i][b.y].t && s[j][b.y].c == 'S') {
						dis = b.x - j;
						if (dis % s[j][b.y].v) {
							break;
						}
						temp = b.step - dis / s[j][b.y].v;
						if (temp < 0) {
							break;
						} 
						if (temp % s[j][b.y].t == 0) {
							flag = 0;
							break;
						}
					}
					if (s[j][b.y].t) {
						break;
					}
				}
				if (!flag) {
					continue;
				}
				for (int j = b.x + 1; j <= n; j++) {
					if (s[i][b.y].t && s[j][b.y].c == 'N') {
						dis = j - b.x;
						if (dis % s[j][b.y].v) {
							break;
						}
						temp = b.step - dis / s[j][b.y].v;
						if (temp < 0) {
							break;
						} 
						if (temp % s[j][b.y].t == 0) {
							flag = 0;
							break;
						}
					}
					if (s[j][b.y].t) {
						break;
					}
				}
				if (!flag) {
					continue;
				}
				for (int j = b.y - 1; j >= 0; j--) {
					if (s[b.x][j].t && s[b.x][j].c == 'E') {
						dis = b.y - j;
						if (dis % s[b.x][j].v) {
							break;
						}
						temp = b.step - dis / s[b.x][j].v;
						if (temp < 0) {
							break;
						} 
						if (temp % s[b.x][j].t == 0) {
							flag = 0;
							break;
						}
					}
					if (s[b.x][j].t) {
						break;
					}
				}
				if (!flag) {
					continue;
				}
				for (int j = b.y + 1; j <= m; j++) {
					if (s[b.x][j].t && s[b.x][j].c == 'W') {
						dis = j - b.y;
						if (dis % s[b.x][j].v) {
							break;
						}
						temp = b.step - dis / s[b.x][j].v;
						if (temp < 0) {
							break;
						} 
						if (temp % s[b.x][j].t == 0) {
							flag = 0;
							break;
						}
					}
					if (s[b.x][j].t) {
						break;
					}
				}
				if (!flag) {
					continue;
				}
				vis[b.x][b.y][b.step] = 1;
				q.push(b);
			}
		}
	}
	cout << "Bad luck!" << endl;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string ss;
	int t, v, x, y;
	while (cin >> n >> m >> k >> l) {
		format(vis);
		format(s);
		for (int i = 0; i < k; i++) {
			cin >> ss >> t >> v >> x >> y;
			s[x][y].c = ss[0];
			s[x][y].t = t;
			s[x][y].v = v;
		}
		bfs();
	}
	return 0;
}
