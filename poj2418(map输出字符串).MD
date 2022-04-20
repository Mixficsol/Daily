日期 2022 / 04 / 20

<img width="1168" alt="截屏2022-04-20 10 37 12" src="https://user-images.githubusercontent.com/73943232/164135811-b88f2243-b904-4e99-ae00-dc5667d63568.png">

# 题目
## Hardwood Species
>Time Limit: 10000MS		Memory Limit: 65536K
>
>Total Submissions: 30559		Accepted: 11430
### Description
>Hardwoods are the botanical group of trees that have broad leaves, produce a fruit or nut, and generally go dormant in the winter. 
>America's temperate climates produce forests with hundreds of hardwood species -- trees that share certain biological characteristics. Although oak, maple and cherry all are types of hardwood trees, for example, they are different species. Together, all the hardwood species represent 40 percent of the trees in the United States. 
>On the other hand, softwoods, or conifers, from the Latin word meaning "cone-bearing," have needles. Widely available US softwoods include cedar, fir, hemlock, pine, redwood, spruce and cypress. In a home, the softwoods are used primarily as structural lumber such as 2x4s and 2x6s, with some limited decorative applications. 
>Using satellite imaging technology, the Department of Natural Resources has compiled an inventory of every tree standing on a particular day. You are to compute the total fraction of the tree population represented by each species.
### Input
>Input to your program consists of a list of the species of every tree observed by the satellite; one tree per line. No species name exceeds 30 characters. There are no more than 10,000 species and no more than 1,000,000 trees.
### Output
>Print the name of each species represented in the population, in alphabetical order, followed by the percentage of the population it represents, to 4 decimal places.
### Sample Input
>Red Alder
>
>Ash
>
>Aspen
>
>Basswood
>
>Ash
>
>Beech
>
>Yellow Birch
>
>Ash
>
>Cherry
>
>Cottonwood
>
>Ash
>
>Cypress
>
>Red Elm
>
>Gum
>
>Hackberry
>
>White Oak
>
>Hickory
>
>Pecan
>
>Hard Maple
>
>White Oak
>
>Soft Maple
>
>Red Oak
>
>Red Oak
>
>White Oak
>
>Poplan
>
>Sassafras
>
>Sycamore
>
>Black Walnut
>
>Willow
### Sample Output

>Ash 13.7931
>
>Aspen 3.4483
>
>Basswood 3.4483
>
>Beech 3.4483
>
>Black Walnut 3.4483
>
>Cherry 3.4483
>
>Cottonwood 3.4483
>
>Cypress 3.4483
>
>Gum 3.4483
>
>Hackberry 3.4483
>
>Hard Maple 3.4483
>
>Hickory 3.4483
>
>Pecan 3.4483
>
>Poplan 3.4483
>
>Red Alder 3.4483
>
>Red Elm 3.4483
>
>Red Oak 6.8966
>
>Sassafras 3.4483
>
>Soft Maple 3.4483
>
>Sycamore 3.4483
>
>White Oak 10.3448
>
>Willow 3.4483
>
>Yellow Birch 3.4483

## 解题思路
> 题目的大意就是给出若干个字符串，然后输出各个字符串的占比，结果保留到小数点后4位，思路很简单，就是利用一个map容器进行存储，cnt计数，问题在于这个输入的结束怎么表示
> 这里用的是getline(cin,s)读到文件尾结束，还有一个问题就是map不能输出string类型的字符串，然后网上查了一下可以用c_str()这个成员方法输出.

## 代码演示
```cpp
#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int main() {
  map<string, double> m;
  map<string, double>::iterator iter;
  string s;
  int cnt = 0;
  while (getline(cin, s)) {
    m[s]++;
    cnt++;
  }
  for (iter = m.begin(); iter != m.end(); iter++) {
    printf("%s %.4f\n", (iter->first).c_str(), (iter->second) * 100.0 / cnt);
  }
  return 0;
}

