这个题的意思就是求一段最长的子序列的长度，我用的是set的容器即每一次把摧毁的炮台存进set容器
里面并且再用一个数组存着被摧毁的村庄编号以便于使用erase的时候可以方便的删除被拆除的村庄编
号在set里面当我们每次询问某个区间内的连续最长是多少就可以通过二分查找找到比查询值大的最小编号，
并且*it—就是比查询小的编号通过两者之差求得子序列长度

#include <iostream>
#include <set>
using namespace std;
int b[10010];
char a[2];
int j, n, m, k;
int main(int argc, char *argv[]) {
 	while (~scanf("%d%d", &n, &m)) {
 		set<int> mq;
 		for (int i = 1; i <= m; i++) {
 			scanf("%s", a);
 			if (a[0] == 'D') {
 				scanf("%d", &k);
 				b[++j] = k;
 				mq.insert(k);
 			}
 			else if (a[0] == 'Q') {
 				scanf("%d", &k);
 				set<int>::iterator it = mq.lower_bound(k);
 				int r, l;
 				r = (it == mq.end() ? n + 1 : *it);
 				l = (it == mq.begin() ? 0 : *(--it));
 				if (r == k) {
 					cout << 0 << endl;
 				} else {
 					cout << r - l - 1 << endl;
 				}
 			} else {
 				mq.erase(b[j--]);
 			}
 		}
 	}
 	return 0;
}
