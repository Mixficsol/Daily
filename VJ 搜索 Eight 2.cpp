这个题目是bfs求八数码问题，这次求的是最小的字典序，所以就不能反向搜索，得正向搜索；
我这里用的是曼哈顿距离求得你搜索的深度，然后判断是否可以，超过limit的话就不能继续
搜索下去，用了剪枝，然后ida*可以使时间降低从而不会超时


#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, 0, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ms(a,b) memset((a), (b), sizeof((a)))
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
#define maxn 1000010

using namespace std;

int M[maxn];
int t[maxn];
char path[100];
int k, next1;
int a[9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int dir[4][2] = { 1, 0, 0, -1, 0, 1, -1, 0 };
char Dir[4] = {'d', 'l', 'r', 'u' };

int cantor(int s[]) {   // 康拓展开求序列值
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int cnt = 0;
		for (int j = i + 1; j < 9; j++)
			if (s[j] < s[i]) {
				cnt++;
			}
		sum += cnt * a[8 - i];
	}
	return sum + 1;
}

int solve(int s[])  {    // 求得深度
	int distance = 0;
	for (int i = 0; i < 9; i++) {
		if (s[i] != 9) {
			int x = i / 3;
			int y = i % 3;
			int sx = t[s[i]] / 3;
			int sy = t[s[i]] % 3;  
			distance += abs(x - sx) + abs(y - sy);
		}
	}
	return distance;
}

bool dfs(int X, int deep, int pre, int limit) {
	int h = solve(M);
	if (deep + h > limit) {
		next1 = min(next1, deep + h);
		return false;
	}
	if (h == 0) {
		path[deep] = '\0';
		cout << "Case " << k << ": " << deep << endl;
		cout << path << endl;
		return true;
	}
	int x = X / 3;
	int y = X % 3;
	for (int i = 0; i < 4; i++) {
		if (i + pre == 3) {
			continue; 
		}
		int sx = x + dir[i][0];
		int sy = y + dir[i][1];
		if (sx >= 0 && sx <= 2 && sy >= 0 && sy <= 2) {
			int Y = sx * 3 + sy;
			swap(M[X], M[Y]);
			path[deep] = Dir[i];
			if (dfs(sx * 3 + sy, deep + 1, i, limit)) {
				return true;
			}
			swap(M[X], M[sx * 3 + sy]);
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char str[100];
	int T, x;
	cin >> T;
	for (k = 1; k <= T; k++) {
		cin >> str;
		for (int i = 0; i < 9; i++) {
			if (str[i] == 'X') {
				M[i] = 9;
				x = i;
			} else {
				M[i] = str[i] - '0';
			}
		}
		cin >> str;
		for (int i = 0; i < 9; i++) {
			if (str[i] == 'X') {
				t[9] = i;
			} else {
				t[str[i] - '0'] = i;
			}
		}
		for (int i = solve(M); ; i = next1) {   
			next1 = INF;
			if (dfs(x, 0, INF, i)) {
				break;
			}
		}
	}
	return 0;
}
