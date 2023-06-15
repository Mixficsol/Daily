这个题是我同学今天问我的，然后我自己就又做了一下，意思很简单就是一个数字序列中你每次最多挑两个完成求最小值（具体看题目吧题目是洛谷的）
然后我就用的dfs；	Left += b[i][j];bfs(i, j + 1);Left -= b[i][j];dfs就是一直搜到底然后一步一步的往回退回，思路很简单，写在
这里主要是方便自己以后回忆


#include <iostream>
#include <cmath>

#define INF 0x3f3f3f
using namespace std;

int a[5];
int b[5][70];
int ans, sum, Left, Right;

void bfs(int i, int j) {
	if (j > a[i]) {
		ans = min(ans, max(Left, Right));
		return;
	}
	Left += b[i][j];
	bfs(i, j + 1);
	Left -= b[i][j];
	Right += b[i][j];
	bfs(i, j + 1);
	Right -= b[i][j];
}

int main(int argc, char *argv[]) {
	sum = 0;
	for (int i = 1; i <= 4; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= a[i]; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 1; i <= 4; i++) {
		ans = INF;
		Right = Left = 0;
		bfs(i, 0);
		sum += ans;
	}
	cout << sum << endl;
	return 0;
}
