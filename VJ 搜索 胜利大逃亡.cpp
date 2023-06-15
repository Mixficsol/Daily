这是一道bfs的题目，同时还是一个状态压缩的题目，和普通bfs不同的是，题目中的钥匙和带锁的门
我利用二进制来存我们拥有的钥匙数目，比如1000代表我用第四把钥匙，那么当我遇到门的时候，我就
可以利用位运算&判断是否可以开门，其他的话就和正常的bfs差不多了，拿到钥匙就用之前的数和目前
的钥匙进行|运算，从而填充钥匙；


#include <iostream>
#include <queue>

using namespace std;

int n, m, t, sx, sy, ex, ey, flag, ans;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
int vis[25][25][5000];
char map[25][25];
char c;

struct fin {
	int x;
	int y;
	int time;
	int k;
};

void bfs() {
	queue<fin> q;
	fin a;
	a.x = sx;
	a.y = sy;
	a.time = 0;
	a.k = 0;
	q.push(a);
	while (q.size()) {
		fin b;
		b = q.front();
		q.pop(); 
		if (b.time >= t) {
			return;
		}
		if (b.x == ex && b.y == ey) {
			flag = 1;
			ans = b.time;
			break;
		}
		for (int i = 0; i < 4; i++) {
			fin c;
			c.x = b.x + dirx[i];
			c.y = b.y + diry[i];
			c.time = b.time + 1;
			c.k = b.k;
			if (c.x >= 0 && c.x < n && c.y >= 0 && c.y < m && map[c.x][c.y] != '*') {
				if ('a' <= map[c.x][c.y] && map[c.x][c.y] <= 'z') {
					c.k = c.k | (1 << (map[c.x][c.y] - 'a'));
					if (!vis[c.x][c.y][c.k]) {
						vis[c.x][c.y][c.k] = 1;
						q.push(c);
					}
				}
				else if ('A' <= map[c.x][c.y] && map[c.x][c.y] <= 'Z') {
					int k = c.k & (1 << (map[c.x][c.y] - 'A'));
					if (!vis[c.x][c.y][c.k] && k) {
						vis[c.x][c.y][c.k] = 1;
						q.push(c);
					}
				}
				else if (vis[c.x][c.y][c.k] == 0) {
					vis[c.x][c.y][c.k] = 1;
					q.push(c);
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	while (scanf("%d %d %d", &n, &m, &t) != EOF) {
		flag = 0;
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> c;
				map[i][j] = c;
				if (c == '@') {
					sx = i;
					sy = j;
				}
				if (c == '^') {
					ex = i;
					ey = j;
				}
			}
			getchar();			
		}
		bfs();
		memset(vis,0, sizeof vis);
		if (flag) {
			cout << ans << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
