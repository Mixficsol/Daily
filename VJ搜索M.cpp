这个题我刚开始觉得挺简单的就是普通的走迷宫问题，只不过用的是bfs，但是我真正去写的时候发现我有点搞不懂解决问题的条件，这个题的条件是答案不能大于t；
于是我想用是队列来存数据，但是我得再开一个结构体存每个点的信息，注释部分就是我写的，其实思路已经有了但是我现在给自己限时了，所以达到时间没写完就只能看题解了
发现题解跟我的思路是一样的于是又自己开始写了，这题的关键就是用队列存每个点的信息然后得到答案，条件和一般的走迷宫没什么两样；


#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

char a[12][12][3];
int used[12][12][3];
char c;
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};

int n, m, t, ans, tx, ty, dx, dy, T;


struct fin {
	int X;
	int Y;
	int Z;
	int step;
};

queue<fin> q;

void bfs() {
	memset(used, 0, sizeof(used));
	queue<fin> q;
	while (!q.empty()) {
		q.pop();
	}
	fin l;
	l.X = l.Y = 1;
	l.Z = 0;
	l.step = 0;
	q.push(l);
	used[1][1][0] = 1;
	while (!q.empty()) {
		fin d = q.front();
		q.pop();
		if (d.step > t) {
			continue;
		}
		if (a[d.X][d.Y][d.Z] == 3) {
			cout << "YES" << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			fin f;
			f.X = d.X + dirx[i];
			f.Y = d.Y + diry[i];
			f.Z = d.Z;
			f.step = d.step + 1;
			if (f.X < 1 || f.X > n || f.Y < 1 || f.Y > m) {  //不能过边界
				continue;
			}
			if (used[f.X][f.Y][f.Z]) {  //不能被走过
				continue;
			}
			if (!a[f.X][f.Y][f.Z]) { // 不能为墙
				continue;
			}
			if (a[f.X][f.Y][f.Z] == 2) {
				if (a[f.X][f.Y][!f.Z] == 0 || used[f.X][f.Y][!f.Z] || a[f.X][f.Y][!f.Z] == 2) { //传送后不能为墙，不能之前访问过，不能对面也为传送墙
					continue;
				}
				f.Z = !f.Z;
				q.push(f);
				used[f.X][f.Y][f.Z] = 1;
				used[f.X][f.Y][f.Z] = 1;
			} else {
				q.push(f);
				used[f.X][f.Y][f.Z] = 1;
			}
 		}
	}
	cout << "NO" << endl;
}
	/*if (sx == tx && st == ty) {
		ans = min(ans, )
	}
	for (int i = 0; i < 4; i++) {
		int flag = 0;
		int sx = x + dirx[i];
		int sy = y + diry[i];
		if (z = 2) {
			flag = 1;
		}
		if (sx > 0 && sx < n && sy > 0 && sy < m) {
			if (flag == 1 && used2[sx][sy]) {
				break;
			}
			if (flag == 0 && used1[sx][sy]) {
				break;
			}
			fin p;
			p.X = sx;
			p.Y = sy;
			p.step = 
		}
	}*/

int main(int argc, char *argv[]) {
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		char b[21];
		for (int k = 0; k < 2; k++) {
			for (int i = 1; i <= n; i++) {
				scanf("%s", b);
				for (int j = 1; j <= m; j++) {
					if (b[j - 1] == '#') {
						a[i][j][k] = 2;
					}
					else if (b[j - 1] == '*') {
						a[i][j][k] = 0;
					} 
					else if (b[j - 1] == '.' || b[j - 1] == 'S') {
						a[i][j][k] = 1;
					}
					else if (b[j - 1] == 'P') {
						a[i][j][k] = 3;
					}
				}
			}
		}
		/*cout << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << endl;
		}
		for (int i = 0; i < n; i++) {
			cout << b[i] << endl;
		}
		cout << tx << " " << ty << endl;*/
		/*fin x;
		x.X = 0;
		x.Y = 0;
		x.step = 0;
		q.push(x);
		bfs(0, 0, 1);*/
		bfs();
	}
}
