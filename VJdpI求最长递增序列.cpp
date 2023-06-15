这个题就是求一个最长的递增序列，用一般的方法就会超时，所以这里得采用二分的方
法，其中a数组我是用来存数据的，b数组用来存递增序列的长度然后最后求一个b的大
小就是递增序列的最大长度了
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n;
int a[100010], b[100010];
int main(int argc, char *argv[]) {
 	int k, m;
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 	}
 	b[++k] = a[1];
 	for (int i = 2; i <= n; i++) {
 		if (a[i] > b[k]) {
 			b[++k] = a[i];
 		} else {
 			m = lower_bound(b + 1, b + k + 1, a[i]) - b;
 			b[m] = a[i];
 		}
 	}
 	cout << k << endl;
 	return 0;
}
