这个题就是一个连通图问题之前在挑战程序设计的那本书上看到过，所以这里的话我们就简单的利用广搜加上地图坐标进行
没到遇到@这个标志的时候就把他设置成另外一个字符从而进行筛选，最终得到答案，模板题吧算是

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
char map1[1000][1000];
int coo[][2] = { { -1, -1 }, { 0, 1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 1, 0 }, { 1, 1 }, { 1, -1 },};
int m, n;


void dfs(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int dx = x + coo[i][0];
		int dy = y + coo[i][1];
		if (map1[dx][dy] == '@') {
			map1[dx][dy] = '#';
			dfs(dx, dy);
		}
	}
}

int main(int argc, char *argv[]) {
	while (cin >> m >> n && m) {
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			getchar();
			for (int j = 1; j <= n; j++) {
				scanf("%c", &map1[i][j]);
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (map1[i][j] == '@') { 
					map1[i][j] = '#'; 
					dfs(i, j); 
					ans++; 
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

