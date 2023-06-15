这是一个八数码问题，就是求一段序列，判断是否能从一个序列进行平移操作得到这个序列并输出方法
用到的是康托展开和逆康托展开，先bfs进行预处理得到康拓序列，利用逆康拓展开找到所有有解状态
的路径。然后输出数据进行判断即可



#include <bits/stdc++.h>

#define INF 0x7fffffff
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, 0, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
#define maxn 500000
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

char Dir[4] = {'d', 'u', 'r', 'l'};
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<char> v[maxn];
int vis[maxn];
const int a[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
const int n = 9;
const int aim = 46233;

int cantor(int s[]) {   // 康托展开
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		cnt = 0;
		for (int j = i + 1; j < n; j++) {
			if (s[i] > s[j]) {
				cnt++;
			}
		}
		sum += a[n - 1 - i] * cnt;
	}
	return sum;
}

void revercantor(int hash, int s[], int &x) {   // 逆康拓展开
	int visi[n] = {};
	int temp;
	for (int i = 0; i < n; i++) {
		temp = hash / a[n - 1 - i];
		for (int j = 0; j < n; j++) {
			if (!visi[j]) {
				if (temp == 0) {
					s[i] = j;
					if (j == 0) {
						x = i;
					}
				    visi[j] = 1;
				    break;
				}
				temp--;
			}
		}
		hash %= a[n - 1 - i];
	}
}

void bfs() {
	queue<int> q;
	q.push(aim);
	vis[aim] = 1;
	int t[n], space;
	while (q.size()) {
		int hash1 = q.front();
		q.pop();
		revercantor(hash1, t, space);
		for (int i = 0; i < 4; i++) {
			int tx = space / 3 + dir[i][0];
			int ty = space % 3 + dir[i][1];
			if (tx < 0 || tx > 2 || ty < 0 || ty > 2) {
				continue;
			}
			int k = tx * 3 + ty;
			t[space] = t[k];
			t[k] = 0;
			int hash2 = cantor(t);
			if (!vis[hash2]) {
				vis[hash2] = 1;
				q.push(hash2);
				v[hash2] = v[hash1];
				v[hash2].push_back(Dir[i]);
			}
			t[k] = t[space];
			t[space] = 0;
 		}
	}
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bfs();
	char c;
	int f[n];
	while (cin >> c) {
		if (c == 'x') {
			f[0] = 0;
		} else {
			f[0] = c - '0';
		}
		for (int i = 1; i < n; i++) {
			cin >> c;
			if (c == 'x') {
				f[i] = 0;
			} else {
				f[i] = c - '0';
			}
		}
		int hash = cantor(f);
		if (vis[hash]) {
			for (int i = v[hash].size() - 1; i >= 0; i--) {
				cout << v[hash][i];
			}
			cout << endl;
		} else {
			cout << "unsolvable" << endl;
		}
 	}
    return 0;
}
