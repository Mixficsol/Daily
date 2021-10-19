


```cpp
#include <bits/stdc++.h>

#define INF 0x7fffffff
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, 0, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
const int maxn = 1e6 + 10;
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

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a, b, c, p;
	cin >> a >> b >> p;
	c = 1;
	while (b) {
		if (b & 1) {
			c = c * a % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	cout << c % p << endl;
	return 0;
}
```
