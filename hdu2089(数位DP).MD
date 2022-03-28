日期 2022 / 3 / 3

[参考资料链接]<https://www.cnblogs.com/young-children/articles/11351588.html>

[参考资料链接]<https://blog.csdn.net/dgq8211/article/details/9296953>
# 题目
> 杭州人称那些傻乎乎粘嗒嗒的人为62（音：laoer）。 
杭州交通管理局经常会扩充一些的士车牌照，新近出来一个好消息，以后上牌照，不再含有不吉利的数字了，这样一来，就可以消除个别的士司机和乘客的心理障碍，更安全地服务大众。 
不吉利的数字为所有含有4或62的号码。例如： 
62315 73418 88914 
都属于不吉利号码。但是，61152虽然含有6和2，但不是62连号，所以不属于不吉利数字之列。 
你的任务是，对于每次给出的一个牌照区间号，推断出交管局今次又要实际上给多少辆新的士车上牌照了。 

>Input
>
>输入的都是整数对n、m（0<n≤m<1000000），如果遇到都是0的整数对，则输入结束。 


>Output
>
> 对于每个整数对，输出一个不含有不吉利数字的统计个数，该数值占一行位置

>Sample Input
> 1 100
> 

>Sample Output
>
> 80

# 题目大意
> 给定一个区间，求出当中的数不含4以及62的数字有多少个

## 解题思路
> 这是一个数位dp的模板题目，首先我们需要用一个dp数组来解题,dp[i]表示i位数中符合要求的数字个数，例如求1~324中符合
> 要求的数字，我们用一个digit数组把324拆开，从百位开始遍历，这里我着重讲一下这个limit(最高标记位）例如当前我取到
> 的百位数字是3，那么我的下一位也就是十位只能最大取到2，那么这种情况我们的limit设置为1，但是如果我们这时候取到的百
> 位的数字是2，那么是不是我们的十位随便取多少都可以，最大可以取到9，这时我们把limit设置为0，所以我们规定当当前数位
> 已经取到最大的值时，下一个数位的limit设置为1，当前数位的limit也设置为1，若当前数位为0，那个此数位和下一个数位的
> limit都设置为0，还有一种情况就是当前数位的limit是1，但未取到最大值则下一个数位的limit就还是0总结下来就得到了代码
> 块中 limit && num == i这个来设置下一个数位的limit

>
```cpp
#include <iostream>

#define INF 0x7fffffff
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define dec(x, y, z) for (int x = y; x >= z; x--)
#define format(a) memset (a, -1, sizeof(a))
#define swap(a, b) (a ^= b ^= a ^= b)
#define ll long long int
#define ull unsigned long long int 
#define uint unsigned int
const int maxn = 1e6 + 10;
const int LEN = 12;
using namespace std;
int dp[LEN][2];  // dp[i]是i位数中符合要求的数字个数
int digit[LEN]; // 用来存各个数位


int dfs(int len, int limit, int state) { // len表示当前数位大小，limit表示最高标记位，state表示前一位是否为6
  int ans = 0, num; // ans用来记录答案，num用来记录当前数位可以取到的最大的值
  if (!len) { 
    return 1;
  }
  if (!limit && dp[len][state] != -1) { // 若当前数位可以取到最大值9，并且dp数组有值就直接返回值
    return dp[len][state];
  }
  num = limit ? digit[len] : 9;  // 这里的limit是0表示当前数位未取到最大值所以下一位一定可以取最大值，若当前数位以及取到最大值则下一个数位上能取到的最大值就是题目给的那个数位值
  for (int i = 0; i <= num; i++) {
    if (i== 4 || state && i == 2) {  // 若数位上是4或者62则跳过
      continue;
    }
    ans += dfs(len - 1, limit && num == i, i == 6); // 缩小len，判断下一位的limit值，判断此时数位是否是6
  }
  if (!limit) {
    dp[len][state] = ans; // 若当前数位能取到最大值则赋值dp
  }
  return ans;
}


int solve(int num) {
  int len = 0;
  while (num) {
    digit[++len] = num % 10; //给digit存值
    num /= 10;
  }
  return dfs(len, 1, -1);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  format(dp);
  cin >> n >> m;
  cout << solve(m) - solve(n - 1) << endl; 
  return 0;
}
