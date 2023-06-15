这是一个深搜的题目，刚开始就是把每张牌赋值，然后用next_permutation求全排列，对于某一种排列
判断两个运算符之前是加括号还是不加括号，利用flag判断是否有解从而得出答案，注意的是需要判断除
数是否为0的情况



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
bool flag = false;
int a[10];

int get_sum(string ss) {
	if ('2' <= ss[0] && ss[0] <= '9') {
		return ss[0] - '0';
	}
	if (ss == "10") {
		return 10;
	}
	switch (ss[0]) {
		case 'A': return 1;
		case 'J': return 11;
		case 'Q': return 12;
		case 'K': return 13;
		default: return 0;
	}
}

void judge(int sum, int x, int index1) {  // 当前的值   下一个操作数   该操作数的下标
	if (index1 == 4) {
		if (sum + x == 24 || sum - x == 24 || sum * x == 24) {
			flag = true;
		}
		if (x != 0 && sum % x == 0 && sum / x == 24) {
			flag = true;
		}
		return;
	}
	judge(sum + x, a[index1 + 1], index1 + 1);  // 不加括号
	judge(sum - x, a[index1 + 1], index1 + 1);
	judge(sum * x, a[index1 + 1], index1 + 1);
	if (x != 0 && sum % x == 0) {
		judge(sum / x, a[index1 + 1], index1 + 1);
	} 
	judge(sum, x + a[index1 + 1], index1 + 1);  // 加括号
	judge(sum, x - a[index1 + 1], index1 + 1);
	judge(sum, x * a[index1 + 1], index1 + 1);
	if (a[index1 + 1] != 0 && x % a[index1 + 1] == 0) {
		judge(sum, x / a[index1 + 1], index1 + 1);
	}
}
int main(int argc, char *argv[]) {
	while (cin >> s) {
		flag = false;
		a[1] = get_sum(s);
		for (int i = 2; i <= 4; i++) {
			cin >> s;
			a[i] = get_sum(s);
		}
		sort(a + 1, a + 5);
		do {
			judge(a[1], a[2], 2);
		} while (!flag && next_permutation(a + 1, a + 5));
		if (flag) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
