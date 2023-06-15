这个题我首先用的是邻接表存的父子关系，然后就是一个典型的背包问题的搜索，从
最开始的子结点开始寻找最优的情况然后不断往上面去更新数据最终找到父节点的最优情况
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int son[1010];
int dp[1010][1010]; //以i为根选j门课的最优情况
vector<int> v[1010];
vector<int>::iterator it;
void solve(int i) {
 	dp[i][0] = 0;
 	for (vector<int>::iterator it = v[i].begin(); it != v[i].end(); ++it) { //取出父节点里面所有的子节点
 		int p = *it; 
 		solve(p); // 子节点再往下面找子节点
 		for (int j = m + 1; j > 0; j--) { //m个可选课程
 			for (int k = 0; k < j; k++) { // 从只能选一个的最优情况开始考虑典型的背包思想
 				dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[p][k]);
 			}
 		}
 	}
}
int main(int argc, char *argv[]) {
 	int x, y;
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 		cin >> x >> y;
 		v[x].push_back(i); //vector储存各父结点以下的儿子结点
 		dp[i][1] = y;
 	}
 	solve(0);
 	cout << dp[0][m + 1] << endl;
 	return 0;
}
