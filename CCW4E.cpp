这个题其实思路很简单的，可以直接爆搜解决，但是在测试的时候自己还是没有写出来
然后去看了下题解，发现是dfs直接过的，三个函数表示题目中对应的三种状态。



#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
char s[10];
ll ans = 1ll << 60；

void dfs3(ll a,ll b){
	ll temp = 0;
    if (s[2] == '+') {
	    temp = a + b;
	} else {
	    temp = a * b;
	}
    ans = min(ans, temp);
}

void dfs2(ll a,ll b,ll c){
	if (s[1] == '+'){
		dfs3(a + b, c);
		dfs3(a + c, b);
		dfs3(b + c, a);
	} else {
		dfs3(a * b, c);
		dfs3(a * c, b);
		dfs3(b * c, a);
	}
}

void dfs1(ll a, ll b, ll c, ll d){
	if (s[0] == '+'){
		dfs2(a + b, c, d);
        dfs2(a + c, b, d);
		dfs2(a + d, b, c);
		dfs2(b + d, a, c);
		dfs2(b + c, a, d);
		dfs2(c + d, a, b);
	} else {
		dfs2(a * b, c, d);
    dfs2(a * c, b, d);
		dfs2(a * d, b, c);
		dfs2(b * d, a, c);
		dfs2(b * c, a, d);
		dfs2(c * d, a, b);
	}
}

int main(int argc, char *argv[]) {
    int a, b, c, d;
    while (scanf("%d%d%d%d",&a, &b, &c, &d) != EOF){
        cin >> s[0] >> s[1] >> s[2];
        dfs1(a, b, c, d);
        cout << ans << endl;
    }
    return 0;
}


