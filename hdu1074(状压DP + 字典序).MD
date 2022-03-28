日期 2022 / 03 / 04

[参考链接]<https://blog.csdn.net/qq_37493070/article/details/77336109>
## 题目

>Doing Homework
>
>Ignatius has just come back school from the 30th ACM/ICPC. Now he has a lot of homework to do. Every teacher gives him a deadline of handing in the homework. If Ignatius hands in the homework after the deadline, the teacher will reduce his score of the final test, 1 day for 1 point. And as you know, doing homework always takes a long time. So Ignatius wants you to help him to arrange the order of doing homework to minimize the reduced score.
>
>Input 
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow. 
Each test case start with a positive integer N(1<=N<=15) which indicate the number of homework. Then N lines follow. Each line contains a string S(the subject’s name, each string will at most has 100 characters) and two integers D(the deadline of the subject), C(how many days will it take Ignatius to finish this subject’s homework). 
Note: All the subject names are given in the alphabet increasing order. So you may process the problem much easier.
>
>Output 
>
>For each test case, you should output the smallest total reduced score, then give out the order of the subjects, one subject in a line. If there are more than one orders, you should output the alphabet smallest one.
>
>Sample Input
> 
>2
> 
> 3 
> 
>Computer 3 3 
>
>English 20 1 
>
>Math 3 2 
>
>3 
>
>Computer 3 3 
>
>English 6 3 
>
>Math 6 3
>

>Sample Output 
>
>2 
>
>Computer 
>
>Math 
>
>English 
>
>3 
>
>Computer 
>
>English 
>
>Math


## 解题思路
> 这个题目其实只是一个状压压缩dp的入门题，但是我刚开始写的时候却困难重重，首先是这个题的题解刚开始看不懂，然后前前后后花了一个多小时去理解，题目的意思是一个学生要写作业
> 每科作业有两个属性，一个是完成该作业需要的时间，一个是这个作业的截止时间，问在多科作业中怎么写才能使扣的分数最少(ex：如果一个作业需要两天写完，但是截止时间是1天，那么
> 写完就会扣一分，超出几天写完就是扣几分，所以我们需要合理规划写作业顺序）题目还说了各科作业以字典序增大的顺序给出，需要我们在扣分一样多的情况下输出最小字典序的写作业顺序
> 这里我们对于每一科作业写完还是没写完用二进制位表示，假如有三门作业，101表示第1,3门作业写完了，第二门没写完，110，表示第1,2门作业写完了，第三门作业没写完。那么从000到
> 111我们需要遍历这么多次，dp思想的思路是：若要求1011的最优解，那么就可能是从1001,1010,0011这三个状态递推过来的。

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

struct task {
  string name; // 课程名字
  int cost; // 课程作业写完需要的时间
  int dead; // 该课程还有几天需要交
} work[20];

struct property {
  int father; // 父节点
  int course; //记录课程名字
  int score;  // 记录已经扣掉的分数
  int time;   // 做完作业需要的时间
} dp[1 << 15]; //该状态下完成的任务扣分的最优解

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    format(dp);
    for (int i = 0; i < n; i++) {
      cin >> work[i].name >> work[i].dead >> work[i].cost; //记录各个属性值
    }
    int end = 1 << n;
    for (int i = 1; i < end; i++) { // 这里枚举所有的情况从什么都没做的00000到都做了的11111
      dp[i].score = INF; // 初始化dp为最大值因为题目要求最小值
      for (int j = n - 1; j >= 0; j--) { // 这里因为题目的输入是由字典序逐渐增大来给的，所以要以最小字典序输出得从最左边(最后一门课）开始遍历1000，这里的1就是最后一门课，0001这里
        int temp = 1 << j;             // 的1就是第一节课
	if (temp & i) { // 确认前面的状态是什么，假如这里的i的二进制表示是1011，那么做完括号中的运算后他的值可能是1010，1001, 0011，这三种情况
	  int rec = i - temp; // 这里的减法就是把回到前一个状态，例如i是1011，temp是0010，那么减完就是1001，回到上面三种情况中的一种
	  int res = dp[rec].time + work[j].cost - work[j].dead; // res代表要扣的分数=之前写完作业已经用掉的天数 + 当前这个作业需要用的天数 - 当前这个作业需要的截止时间
	  if (res < 0) {
	    res = 0;  // 这种出现在截止时间特别长时，例如之前写作业用掉一天，当前作业需要2天，这个作业需要的截止时间是第100天，那么此时我们认为是不扣分的因为做完这个作业才第三天
	  }
	  if (res + dp[rec].score < dp[i].score) { // 如果出现了最优的扣分情况就赋值给当前状态下的dp
	    dp[i].score = res + dp[rec].score; // 最优扣分 = 之前的扣分 + 这次要扣的分数
	    dp[i].father = rec; // 当前作业的子节点就是之前作业的状态，例如当前最优状态是1011，是由1001这个状态得来的，那么1001就是1011的父节点
	    dp[i].course = j;  // 记录当前写的科目作业名字
	    dp[i].time = dp[rec].time + work[j].cost; // 计算写完这个作业已经用掉了多少天 = 之前作业需要的时间 + 当前作业需要的时间
         }
       }
     }
   }
   cout << dp[end - 1].score << endl; // 计算出总共扣的分数（end- 1)这个二进制就1111111，代表所有的作业都完成了
   stack<int> q; 
   int x = end - 1;
   while (dp[x].time) { // 从最后完成的作业开始往前找父节点
     q.push(dp[x].course); // 将最后完成的存入栈中，栈最上面的是最先完成的
     x = dp[x].father;
   }
   while (!q.empty()) {
     int y = q.top();
     cout << work[y].name << endl; // 依次打印出栈
     q.pop();
   }
  }
  return 0;
}










