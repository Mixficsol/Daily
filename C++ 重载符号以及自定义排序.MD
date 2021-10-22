# 问题引入
> 每次写关于容器排序的题目的时候我都是不知道怎么去排序，比如map里面的怎么按照key排序或者按照value排序，虽然之前有看过需要重载符号，但是我一直都不知道到底什么是重载符号以及它有什么作用，今天我查阅了很多资料终于搞懂了这个困扰我已久的问题，以下就讲了怎么去自定义排序。

# 重载定义
> C++ 允许在同一作用域中的某个函数和运算符指定多个定义，分别称为函数重载和运算符重载。
重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，但是它们的参数列表和定义（实现）不相同。
当您调用一个重载函数或重载运算符时，编译器通过把您所使用的参数类型与定义中的参数类型进行比较，决定选用最合适的定义。选择最合适的重载函数或重载运算符的过程，称为重载决策。
# 问题描述

> 在讲自定义排序之前我们需要知道在C++容器中(vector, list ,deque)这种容器叫线性容器，(map,set)这种容器叫做集合容器，sort算法只能对于线性容器进行排序，所以我们不能使用sort去对集合容器进行排序，map里面存储的元素是pair，不是线性存储的，它是的底层是红黑树，所以对于map的排序我们得把map中的元素放到线性容器(比如vector)中，然后利用vector再对元素进行排序，并且得满足容器中的元素是可比较的，一般对于自定义排序我们需要对符号进行重载,经过代码测试，我知道map默认是按照key的升序进行排列的(set也是)，value的排列的随机的(按照插入的顺序)，当在map<string, int, greater < string > >加入了greater < string > 以后会进行key的降序排列，map的默认定义时是map<string, int ,less < string > >是这样的(即默认是按照key升序排列的)，less<类型名>代表升序，而greater<类型名>代表降序.
 
# 博客参考
  [博客链接]<https://blog.csdn.net/qq_30603195/article/details/86660263?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.tagcolumn&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.tagcolumn>
  > STL所提供的各式各样算法中，sort()是最复杂最庞大的一个。这个算法接受两个RandomAccestlerators（随机存取迭代器），然后将区间内的所有元素以渐增方式由小到大重新排列。第二个版本则允许用户指定一个仿函数（functor），作为排序标准，STL的所有关系型容器主要包括set和map这两种容器（associative containers）都拥有自动排序功能（底层结构采用RB-tree，所以不需要用到这个sort算法。至于序列式容器（squence containers）中的 stack、queue 和priority-queue都有特别的出入口，不允许用户对元素排序。剩下vector.deque和list，前两者的迭代器属于RandomAccessiterators，适合使用sort算法，list的迭代器则属于Bidirectioinallterators,适合使用sort算法.list的迭代器则属于Bidirectionallterators,不在STL标准之列的slist,其迭代器更属于ForwardIIterators,不在STL标准之列的slist,其迭代器更属于ForwardIIterators,都不适用与sort算法，如果要对list或slist排序，应该使用它们自己提供的member functions sort().
> 
  [博客链接]<https://blog.csdn.net/qq_30603195/article/details/86660263?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.tagcolumn&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.tagcolumn>



```cpp
#include<iostream>
#include<map>
using namespace std;
typedef struct tagIntPlus
{
    int num,i;
}IntPlus;
//自定义比较规则
//注意operator是(),不是＜
struct Cmp
{
    bool operator () (IntPlus const &a,IntPlus const &b)const
    {
        if(a.num!=b.num)
            return a.num<b.num;
        else return a.i<b.i;
    }
};
int main()
{
    srand((unsigned)time(NULL));
    //注意此处一定要有Cmp，否则无法排序会报错
    multimap<IntPlus,int,Cmp>mp;
    int n;
    cin>>n;
    int a,b;
    IntPlus intplus;
    for(int i=0; i<n; i++)
    {
        a=rand()%4;
        b=rand()%4;
        intplus.num=a;
        intplus.i=b;
        mp.insert(pair<IntPlus,int>(intplus,i));
    }
    map<IntPlus,int>::iterator iter;
    for(iter=mp.begin(); iter!=mp.end(); iter++)
        cout<<iter->first.num<<" "<<iter->first.i<<" "<<iter->second<<endl;
    return 0;
}


```
<img width="667" alt="截屏2021-10-22 01 26 29" src="https://user-images.githubusercontent.com/73943232/138327345-95ea1713-2dd9-40f7-ad28-8ec6ddd7d08b.png">

# 笔记
## map构造排序
 > 所谓的构造排序就是指在容器构造时进行排序，STL里面提供了两个函数less<类型名>，greater<类型名>,less代表的是升序排序，这个是默认的排序，而greater
 > 代表的是降序排序，可以是对key的排序也可以是对value的排序,需要注意的是无论是greater还是less都只能写一个(写成map<类型名， 类型名， greater<类型名>，greater<类型名> >这样是会报错的).
 
 ```cpp
 #include <bits/stdc++.h>

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int, greater<string> > m;
	map<string, int, less<string> > m1;
	map<string, int, greater<int> > m2;
	map<string, int, less<int> > m3;
	map<string, int> m4;
	m["cs"] = 3;
	m["ds"] = 2;
	m["as"] = 1;
	map<string,int>::iterator it = m.begin();
	while (it != m.end()) {
		cout << it->first <<  " " << it->second << endl;
		it++;
	}
	
}
 ```
 
 ## map自定义排序(博客那篇的代码)
 >  我们知道map里面储存的元素是pair，类似于结构体.可以看出key.num相同时是按照num.i的升序进行排列，至于int的值则是按照插入的顺序进行排列的，这里重载
的是（）号，并且a.num < b.num是表示的是升序，这个排序方向和我之前在重载<符号的时候刚刚好是相反的.(即重载<号的时候x<y代表的是降序)，这里我用的随机数进行的测试
 如果我也想对插入的i也进行排序呢？
 
 ```cpp
 #include <bits/stdc++.h> // map按值value排序

using namespace std;

typedef struct Mixficsol {
	int num;
	int i;
} Mix;

typedef pair<Mix,int> PAIR;

struct Cmp {
	bool operator () (Mix const &a, Mix const &b) const {
		if (a.num != b.num) {
			return a.num < b.num; // key.num按照正序排列
		} else {
			return a.i > b.i; // num相同按照key.i正序排列
		}
	}
};

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	srand((unsigned)time(NULL));
	multimap<Mix,int,Cmp> mp;
	int n, a, b;
	cin >> n;
	Mix M;
	for (int i = 0; i < n; i++) {
		a = rand() % 4;
		b = rand() % 4;
		M.num = a;
		M.i = b;
		mp.insert(pair<Mix,int>(M,i));
	}
	map<Mix,int>::iterator iter;
	cout << "排序后: " << endl;
	for (iter = mp.begin(); iter != mp.end(); iter++) {
		cout << iter->first.num << " | " << iter->first.i << " | " << iter->second << endl;
	}
	return 0;
}


 ```
<img width="927" alt="截屏2021-10-22 11 34 12" src="https://user-images.githubusercontent.com/73943232/138389292-0909b573-dcb7-4051-9492-10f341b69bcc.png">


 
## map结构体排序

 > 之前说过map属于集合容器是不能进行sort排序的，要排序的话得用vector进行排序，这里就用到了vector，我们去定义一个bool cmp去设置我们需要的排序方式
 (bool cmp一般是放在sort里面的，而struct cmp是放在构造容器时里面的）我们把map放进vector里面然后排序就得到了结果.
 
 ```cpp
 #include <bits/stdc++.h> // map按值value排序

using namespace std;

typedef struct Mixficsol {
	int num;
	int i;
} Mix;

typedef pair<Mix,int> PAIR;

struct Cmp {
	bool operator () (Mix const &a, Mix const &b) const {
		if (a.num != b.num) {
			return a.num < b.num; // key.num按照正序排列
		} else {
			return a.i < b.i; // num相同按照key.i正序排列
		}
	}
};

bool cmp(PAIR const &a, PAIR const &b) {
	if (a.first.num != b.first.num) {
		return a.first.num < b.first.num;
	} else {
		if (a.first.i != b.first.i) {
			return a.first.i < b.first.i;
		} else {
			return a.second > b.second; //key值相同按照value(i)倒序排列
		}
	}
}
int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	srand((unsigned)time(NULL));
	multimap<Mix,int,Cmp> mp;
	int n, a, b;
	cin >> n;
	Mix M;
	for (int i = 0; i < n; i++) {
		a = rand() % 4;
		b = rand() % 4;
		M.num = a;
		M.i = b;
		mp.insert(pair<Mix,int>(M,i));
	}
	map<Mix,int>::iterator iter;
	cout << "排序前: " << endl;
	for (iter = mp.begin(); iter != mp.end(); iter++) {
		cout << iter->first.num << " | " << iter->first.i << " | " << iter->second << endl;
	}
	cout << "排序后: " << endl;
	vector<PAIR> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first.num << " | " << v[i].first.i << " | " << v[i].second << endl;
	}
	return 0;
}
 ```
<img width="969" alt="截屏2021-10-22 11 35 08" src="https://user-images.githubusercontent.com/73943232/138389364-81857b7f-d1d1-439c-b9f2-4f524c3221b6.png">

 
 ## set构造排序
 > set的构造排序和map一样，这里就不说了下面有两个例子

```cpp
#include <bits/stdc++.h>

using namespace std;


int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	srand((unsigned)time(NULL));
	int a;
	set<int> s;
	set<int, less<int> > s1;
	set<int, greater<int> > s2;
	for (int i = 0; i < 5; i++) {
		a = rand() % 4;
		s.insert(a);
	}
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	return 0;
}
```

```cpp
#include <bits/stdc++.h>

bool cmp(string const& a, string const& b) {
	return a.size() > b.size();	  // 按照字符串的大小进行倒序排列即size大的排列在前面
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	set<string, greater<string> > s; // 按照string的字典序倒序排列
	set<string, less<string> > s1; // 按照string的字典序顺序排列(默认是使用less)
	set<string> s2; // 按照string的字典序顺序排列	
	s.insert("abcd");
	s.insert("dcba");
	s.insert("123456");
	vector<string> v(s.begin(),s.end()); // 由于set不是顺序容器所以得先存入vector进行排序
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;  // 最终的排序结果是字符串大的排列在最前面，字符串长度一样的按照字典序进行倒序排列
	}
	cout << s.size() << endl;
	return 0;
}
```

## 练习
 
 > 为了检测自己是否真的弄懂了，我想了个题目，就是学生成绩进行排序，我的想法是成绩按照倒序排列就是成绩高的学生在前面，成绩相同就按照名字的长度进行
 排序，名字长度大的在前面，名字长度一样的就按照名字的字典序排序，下面就是我写的代码
 
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

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			w = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}

typedef struct student {
	int grade;
	string name;
}stu;

struct cmp {
	bool operator () (stu const &a, stu const &b) const {
		if (a.grade != b.grade) {
			return a.grade > b.grade; // 成绩按照倒序排列
		} 
		else if (a.name.size() != b.name.size()) { // 成绩一样按照名字长度排序,长度大的排在前面
			return a.name.size() > b.name.size();
		} else {
			return a.name < b.name; // 长度一样按照字典序排序，字典序小的排在前面
		} 
	}
};

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	stu Stu;
	cin >> n;
	set<stu,cmp> s;
	for (int i = 0; i < n; i++) {
		cin >> Stu.name >> Stu.grade;
		s.insert(Stu);
	}
	set<stu,cmp>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << iter->name << ' ' << iter->grade << endl;
	}
	return 0;
}
 ```
<img width="963" alt="截屏2021-10-22 11 37 26" src="https://user-images.githubusercontent.com/73943232/138389589-4ccb162b-a0de-4e90-aca3-8124720133ff.png">


 # 总结
 > 对于关联容器的排序可以说今天算搞懂了吧，有几个要注意的点是
 >
 > 1.bool cmp是放在sort里面的，而sturct cmp是放在构造容器时里面的
 >
 > 2.less是升序，greater是降序
 >
 > 3.less和greater在构造容器时只能写入一个
 >
 > 4.重载<和重载()所对应的X < Y排序不同，在重载<时，x < y代表是升序，而在重载()时x < y代表的是降序
 
