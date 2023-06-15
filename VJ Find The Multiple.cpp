这个题就是一个简单的搜索，之前用队列广搜过一次但是超时了所以改成了深搜虽然也不知道我为什么会超时。。。。。
深搜的话就很好理解了，就是乘10还有乘10加1

#include<iostream>
#include<string.h>
using namespace std;
int n;
int k;

void dfs(long long num, long long x){
	if (k) {
		return;
	}
	if (num % n == 0) {
		cout << num << endl;
		k = 1;
		return;
	}
	if (x >= 19){
		return;
	}
	dfs(num * 10, x + 1);
	dfs(num * 10 + 1, x + 1);
}

int main(int argc, char *argv[]) {
	while (cin >> n && n) {
		k = 0;
		dfs(1, 1);
	}
	return 0;
} 
