这个题我刚开始想的时候感觉完全没有思路，因为我不知道从哪里下手，如果从搜索开始想的话我只能想到广搜，
结果看了下题解说的是吧加一减一和交换着三种情况都用队列存起来然后一次一次去确认有没有目标的答案，果然
广搜的话还是得用队列来存储。

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
 
struct fin {
	int target[5];
	int step;
};

char a[11], b[11];
int pass[5];
int vis[11][11][11][11];
 
 
int solve() {
	bool flag;
	queue<fin> q;
	fin x, y;
	node tem, nex;
	for (int i = 0; i < 4; i++) {
		x.target[i] = a[i] - '0';       
		pass[i] = b[i] - '0';             
	}
	x.step = 0;                  
	q.push(x);				
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) {
		x = q.front();        
		q.pop();              
		flag = true;
		for (int i = 0; i < 4; i++) {
			if (x.target[i] != pass[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {            
			return tem.step;
		}		
		for (int j = 0; j < 4; j++) {   
			y = x;        
			if (x.target[j] == 9) {
				y.target[j] = 1;   
			} else {
				y.target[j] = x.target[j] + 1;
			}			
			if (!vis[y.target[0]][y.target[1]][y.target[2]][y.target[3]]) {
				vis[y.target[0]][y.target[1]][y.target[2]][y.target[3]] = 1;
				y.step = x.step + 1;  
				q.push(y);
			}
		}
		for (int j = 0; j < 4; j++) {   
			y = x;       
			if (x.target[j] == 1) {
				y.target[j] = 9;    
			} else {
				y.target[j] = x.target[j] - 1;
			}		
			if (!vis[y.target[0]][y.target[1]][y.target[2]][y.target[3]]) {
				vis[y.target[0]][y.target[1]][y.target[2]][y.target[3]] = 1;
				y.step = x.step + 1;  
				q.push(y);
			}
		}		
		for (int k = 0; k < 3; k++) {  
			y = x;
			y.target[k] = x.target[k + 1];
			y.target[k + 1] = x.target[k];			
			if (!vis[y.target[0]][y.target[1]][y.target[2]][y.target[3]]) {
				vis[y.target[0]][y.target[1]][y.target[2]][y.target[3]] = 1;
				y.step = x.step + 1;   
				q.push(y);
			}	
		}	
	}
}

 
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << solve() << endl;
	}
	return 0;
}

