# 问题引入
> 每次写关于容器排序的题目的时候我都是不知道怎么去排序，比如map里面的怎么按照key排序或者按照value排序，虽然之前有看过需要重载符号，但是我一直都不知道
> 到底什么是重载符号以及它有什么作用，今天我查阅了很多资料终于搞懂了这个困扰我已久的问题，以下就讲了怎么去自定义排序。

# 问题描述

> 在讲自定义排序之前我们需要知道在C++容器中(vector, list ,deque)这种容器叫线性容器，(map,set)这种
容器叫做集合容器，sort算法只能对于线性容器进行排序，所以我们不能使用sort去对集合容器进行排序，map里面存
储的元素是pair，不是线性存储的，它是的底层是红黑树，所以对于map的排序我们得把map中的元素放到线性容器(比
如vector)中，然后利用vector再对元素进行排序，所以得满足容器中的元素是可比较的，然后就引出了对于符号的重载，一般对于排序的重载
我们一般是对 < 这个符号进行重载,经过代码测试，我知道map默认是按照key的升序进行排列的(set也是)，value的排列
的随机的(按照插入的顺序)，当在map<string, int, greater<string> >加入了greater<string>以后会进行key的降序排列，原来map
的本身定义时是map<string, int ,less<string> >是这样的，less<类型名>代表升序，而greater<类型名>代表降序.那么如果我想让key值相等时value按照升序排列
该怎么办呢？
 
# 博客参考
  [博客链接]<https://blog.csdn.net/qq_30603195/article/details/86660263?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.tagcolumn&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.tagcolumn>
> 我们知道map里面储存的元素是pair，类似于结构体.那么就应该去重载符号使它按照我们的想法排序
这里我参考了网上的一篇博客,可以看出key相同时是按照i的升序进行排列，至于int的值则是按照插入的顺序进行排列的，这里我发现他重载
的是（）号，并且a.num < b.num是表示的是升序，这个和我在重载<符号的时候刚刚号是相反的.
到这里关于key的排序就已经结束了，我们目前掌握的是根据key排序，key相等时再考虑value.但是如果我开始就
考虑value呢，所以我得知道map按值value的排序，

<img width="714" alt="截屏2021-10-22 01 25 36" src="https://user-images.githubusercontent.com/73943232/138327220-9de2fade-fc58-430b-ba91-434e536c5a22.png">
<img width="720" alt="截屏2021-10-22 01 26 11" src="https://user-images.githubusercontent.com/73943232/138327303-d1418321-7f22-4760-8d6c-f3bdb31aaa4f.png">
<img width="667" alt="截屏2021-10-22 01 26 29" src="https://user-images.githubusercontent.com/73943232/138327345-95ea1713-2dd9-40f7-ad28-8ec6ddd7d08b.png">

# 笔记
## map构造排序
  <img width="555" alt="截屏2021-10-22 01 28 14" src="https://user-images.githubusercontent.com/73943232/138327547-cfc39611-7f73-4f95-9424-bc728d340986.png">
> 所谓的构造排序就是指在容器构造是进行排序，STL里面提供了两个函数less<类型名>，greater<类型
如vector)中，然后利用vector再对元素进行排序，所以得满足容器中的元素是可比较的，然后就引出了对于符号的重载，一般对于排序的重载min
如vector)中，然后利用vector再对元素进行排序，所以得满足容器中的元素是可比较的，然后就引出了对于符号的重载，一般对于排序的重载敏
如vector)中，然后利用vector再对元素进行排序，所以得满足容器中的元素是可比较的，然后就引出了对于符号的重载，一般对于排序的重载
