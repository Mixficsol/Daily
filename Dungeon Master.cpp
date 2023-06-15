这个题就是三维的bfs地图问题，一个模板而已。。。

#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;


int n, m, num, sx, tx, sy, ty, sz, tz;;
char map1[33][33][33];
int d[33][33][33];
int dx[]= {1, 0, -1, 0, 0, 0};
int dy[]= {0, 1, 0, -1 ,0 ,0};
int dz[]= {0, 0, 0, 0, 1, -1};

struct fin {
	int x;
	int y;
	int z;
};

int bfs() {
	queue<fin> q;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				d[i][j][k] = INF;
			}
		}
	}
	d[sx][sy][sz] = 0;
	fin Mic;
	Mic.x = sx;
	Mic.y = sy;
	Mic.z = sz;
	q.push(Mic);
	while (q.size()) {
		fin p = q.front();
		q.pop();
		if (p.x == tx && p.y == ty && p.z == tz) {
			break;			
		}
		for (int i = 0; i < 6; i++) {
			int lx = p.x + dx[i];
			int ly = p.y + dy[i];
			int lz = p.z + dz[i];
			if ((0 <= lx && lx < num) && (0 <= ly && ly < n) && (0 <= lz && lz < m) && map1[lx][ly][lz] != '#' && d[lx][ly][lz]==INF) {		
				Mic.x = lx;
				Mic.y = ly;
				Mic.z = lz;
				q.push(Mic);
				d[lx][ly][lz] = d[p.x][p.y][p.z] + 1;
			}
		}
	}
	return d[tx][ty][tz];
}

int main() {
	while (cin >> num >> n >> m){
		if (n==0 && m==0 && num == 0) {
			break;
		}
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					cin >> map1[i][j][k];
					if (map1[i][j][k] == 'S') {
						sx = i;
						sy = j;
						sz = k;
					}					
					if (map1[i][j][k]=='E') { 
						tx = i;
						ty = j;
						tz = k;	
					}				
				}
			}
		}
		int ans = bfs();
		if (ans == INF) {
			cout << "Trapped!" << endl;
		} else {
			cout << "Escaped in " << ans << " minute(s)." << endl;
		}
	}
	return 0;
}



