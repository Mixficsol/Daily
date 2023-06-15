这个题是一个bfs搜索加上一个状态压缩，每一把钥匙对应每一扇门，那么我们就可以利用二进制存
我们目前拥有的钥匙数量，如果捡到一把钥匙就用之前的拥有钥匙的二进制与这个做|运算，如果碰
到一扇门那么我们就用我们目前拥有钥匙的二进制与门进行&运算判断能否开门，其他的部分和正常
bfs一样


#include <bits/stdc++.h>

#define INF 0x7fffffff
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, 0, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
#define Maxn 110
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
	int x;
	int y;
	int step;
	int key;
};

char map1[Maxn][Maxn];
int vis[Maxn][Maxn][22];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
fin st;
int door[4] = {'B', 'Y', 'R', 'G'};
char Key[4] = {'b', 'y', 'r', 'g'};

void bfs() {
	format(vis);
	queue<fin> Q;
	fin p, q;
	st.key = 0;
	st.step = 0;
	vis[st.x][st.y][st.key] = 1;
	Q.push(st);
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		if (map1[p.x][p.y] == 'X') {
			cout << "Escape possible in " << p.step << " steps." << endl;
 			//printf("Escape possible in %d steps.\n", p.step);
			return; 
		}
		for (int i = 0; i < 4; i++) {
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			q.step = p.step + 1;
			q.key = p.key;
			if (q.x < 1 || q.x > n || q.y < 1 || q.y > m || map1[q.x][q.y] == '#') {
				continue;
			}
			if (isupper(map1[q.x][q.y]) && map1[q.x][q.y] != 'X') {
				for (int j = 0; j < 4; j++) {
					if (map1[q.x][q.y] == door[j]) {
						if (q.key & (1 << j)) {
							if (!vis[q.x][q.y][q.key]) {
								vis[q.x][q.y][q.key] = 1;
								Q.push(q);
							}
							break;
						}
					}
				}
			}
			else if (islower(map1[q.x][q.y])) {
				for (int j = 0; j < 4; j++) {
					if (map1[q.x][q.y] == Key[j]) {
						if ((q.key & (1 << j)) == 0) {
							q.key += (1 << j);
						}
						if (!vis[q.x][q.y][q.key]) {
							vis[q.x][q.y][q.key] = 1;
							Q.push(q);
						}
					}
				}
			} else {
				if (!vis[q.x][q.y][q.key]) {
					vis[q.x][q.y][q.key] = 1;
					Q.push(q);
				}
			}
		}
	}
	cout << "The poor student is trapped!" << endl;
}

int main(int argc, char *argv[]) {
	while (cin >> n >> m && n + m) {
		for (int i = 1; i <= n; i++) {
			scanf("%s", map1[i] + 1);
			for (int j = 1; j <= m; j++) {
				if (map1[i][j] == '*') {
					st.x = i;
					st.y = j;
				}
			}
		}
		bfs();
	}
	return 0;
}
