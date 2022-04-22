日期 2022 / 04 / 22
<img width="987" alt="截屏2022-04-22 11 19 49" src="https://user-images.githubusercontent.com/73943232/164589725-e550d2b6-3b80-4cec-84ed-775114327335.png">

# 题目
## Shaolin

>Time Limit: 3000/1000 MS (Java/Others)    Memory Limit: 65535/32768 K (Java/Others)
>
>Total Submission(s): 6467    Accepted Submission(s): 2804
>
## Problem Description
>Shaolin temple is very famous for its Kongfu monks.A lot of young men go to Shaolin temple every year, trying to be a monk there. The master of Shaolin evaluates a young man mainly by his talent on understanding the Buddism scripture, but fighting skill is also taken into account.
>When a young man passes all the tests and is declared a new monk of Shaolin, there will be a fight , as a part of the welcome party. Every monk has an unique id and a unique fighting grade, which are all integers. The new monk must fight with a old monk whose fighting grade is closest to his fighting grade. If there are two old monks satisfying that condition, the new monk will take the one whose fighting grade is less than his.
>The master is the first monk in Shaolin, his id is 1，and his fighting grade is 1,000,000,000.He just lost the fighting records. But he still remembers who joined Shaolin earlier, who joined later. Please recover the fighting records for him.
>
## Input
>There are several test cases.
>In each test case:
>The first line is a integer n (0 <n <=100,000),meaning the number of monks who joined Shaolin after the master did.(The master is not included).Then n lines follow. Each line has two integer k and g, meaning a monk's id and his fighting grade.( 0<= k ,g<=5,000,000)
>The monks are listed by ascending order of jointing time.In other words, monks who joined Shaolin earlier come first.
>The input ends with n = 0.
>
## Output
>A fight can be described as two ids of the monks who make that fight. For each test case, output all fights by the ascending order of happening time. Each fight in a line. For each fight, print the new monk's id first ,then the old monk's id.
> 
## Sample Input
>3
>
>2 1
>
>3 3
>
>4 2
>
>0 
>
## Sample Output
>2 1
>
>3 2
>
>4 2

# 解题思路
> 这个题目意思是少林寺每个和尚有两个属性，一个是独有的id，一个是战斗等级，每个和尚进来都要与一个战斗等级最接近的和尚对决，题目的要求是给出每个和尚进来时的id和战斗等级
> 需要打印出每组和尚对决的id，刚开始只有一个和尚，id是1，战斗力1000000000，我们知道map是默认利用key进行升序排序的，我们可以利用这一点进行排序，用例输入id和战斗等级
> 我们把他们插入map里面，然后利用迭代器寻找到他们的位置，在找到的位置前后进行大小比较.

# 代码演示
```cpp
#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;

int main() {
  int n, x, y;
  while (cin >> n && n) {
    mp.clear();
    mp[1000000000] = 1;
    while (n--) {
      cin >> x >> y;
      mp[y] = x;
      map<int, int>::iterator it = mp.find(y);
      int ans;
      if (it == mp.begin()) {
        ans = (++it)->second;
      } else {
        map<int, int>::iterator it2 = it;
        it2--;
        it++;
        if (y - it2->first <= it->first - y) {
          ans = it2->second;
        } else {
          ans = it->second;
        }
      }
      cout << x << ' ' << ans << endl;
    }
  }
  return 0;
}
```


