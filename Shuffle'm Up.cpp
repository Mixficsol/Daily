这个题就是利用一个map来存之前出现过的字符串，如果在变换中遇到了之前的字符串则自动退出失败否则一直搜索下去

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>

using namespace std;
char a[110], b[110], c[220], s[220];

int main(){
	int i, j, ans, sum, n, flag, t, m;
	cin >> t;
	m = 1;
	while (t--) {
		flag = 0;
		ans = 0;	
		cin >> n;
		cin >> a;
		cin >> b;
		cin >> c;
		map<string, int> q;	
		//cout << n << endl;
		while (1) {
			ans++;	
			sum = 0;	
			for (i = 0; i < n; i++){
				s[sum++] = b[i];	
				s[sum++] = a[i];	
			}
			s[sum] = '\0';	
			if (strcmp(s, c) == 0) {
				break;	
			}
			if (q[s] == 1) {	
				flag = 1;	
				break;
			}
			q[s] = 1;	
			for (i = 0; i < n; i++){	
				a[i] = s[i];
				b[i] = s[i + n];
			}
			a[i] = b[i] = '\0';	
		}
		cout << m << " ";
		m++;
		if (!flag) {
			cout << ans << endl;	
		} else {
			cout << -1 << endl;
		}
	}		
	return 0;
}

