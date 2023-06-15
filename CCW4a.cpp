#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

int t, n, c, m;
char a[51];
int mark[1100000];

struct fin {
	int num;
	int len;
	string psw;
};

void bfs() {
	queue<fin> q;
	fin x, y;
	x.num = 0;
	x.len = 0;
	x.psw = "";
	mark[x.num] = 1;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < m; i++) {
			int k, sum;
			if (a[i] >= '0' && a[i] <= '9') {
				k = a[i] - '0';
			} else {
				k = a[i] - 'A' + 10;
			}
			sum = x.num * c + k;
			if (x.num == 0 && k == 0) {
				continue;
			}
			if (sum % n == 0) {
				cout << x.psw + a[i] << endl;
				return;
			}
			sum = sum % n;
			if (mark[sum]) {
				continue;
			}
			mark[sum] = 1;
			y.psw = x.psw + a[i];
			y.num = sum;
			y.len = x.len + 1;
			q.push(y);
			if (y.len > 500) {
				cout << "give me the bomb please" << endl; 
				return;
			}
		}
	}
	cout << "give me the bomb please" << endl; 
}

int main(int argc, char *argv[]) {
	scanf("%d", &t);
	while (t--) {
		memset(mark, 0, sizeof(mark));
		scanf("%d%d", &n, &c);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf(" %c", &a[i]);
		}
		/*for (int i = 0; i < 3; i++) {
			cout << a[i] << " ";
		}*/
		sort(a ,a + m);
		if (n == 0) {
			if (a[0] == '0') {
				cout << 0 << endl;
			} else {
				cout << "give me the bomb please" << endl;
			}
			continue;
		}
		bfs();
	}
	return 0;
}
