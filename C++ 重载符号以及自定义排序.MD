# 问题引入
> 每次写关于容器排序的题目的时候我都是不知道怎么去排序，比如map里面的怎么按照key排序或者按照value排序，虽然之前有看过需要重载符号，但是我一直都不知道到底什么是重载符号以及它有什么作用，今天我查阅了很多资料终于搞懂了这个困扰我已久的问题，以下就讲了怎么去自定义排序。

# 问题描述

> 在讲自定义排序之前我们需要知道在C++容器中(vector, list ,deque)这种容器叫线性容器，(map,set)这种容器叫做集合容器，sort算法只能对于线性容器进行排序，所以我们不能使用sort去对集合容器进行排序，map里面存储的元素是pair，不是线性存储的，它是的底层是红黑树，所以对于map的排序我们得把map中的元素放到线性容器(比如vector)中，然后利用vector再对元素进行排序，所以得满足容器中的元素是可比较的，然后就引出了对于符号的重载，一般对于排序的重载我们一般是对这个符号进行重载,经过代码测试，我知道map默认是按照key的升序进行排列的(set也是)，value的排列的随机的(按照插入的顺序)，当在map<string, int, greater<string> >加入了greater<string>以后会进行key的降序排列，原来map的本身定义时是map<string, int ,less<string> >是这样的，less<类型名>代表升序，而greater<类型名>代表降序.那么如果我想让key值相等时value按照升序排列该怎么办呢？
 
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
 > 所谓的构造排序就是指在容器构造时进行排序，STL里面提供了两个函数less<类型名>，greater<类型名>,less代表的是升序排序，这个是默认的排序，而greater
 > 代表的是降序排序，需要注意的是无论是greater还是less都只能写一个，可以是对key的排列也可以是对value的排列，那么如果我想按照value进行排序怎么办呢
 > 那么我们需要用到结构体，也就是我们的自定义排序了
  <img width="555" alt="截屏2021-10-22 01 28 14" src="https://user-images.githubusercontent.com/73943232/138327547-cfc39611-7f73-4f95-9424-bc728d340986.png">
 
 ## map自定义排序
 > 这里可以看出key.num是按照升序排列，key.i是按照升序排列，而i是按插入顺序排列，这里就用到了重载，这里重载的是(),这里我用的随机数进行的测试
 如果我也想对插入的i也进行排序呢？下面就是对i也进行排列
 
 <img width="886" alt="截屏2021-10-22 01 36 41" src="https://user-images.githubusercontent.com/73943232/138328778-b98a2a65-f8d8-474c-80dd-e4a144fa7048.png">
<img width="922" alt="截屏2021-10-22 01 35 57" src="https://user-images.githubusercontent.com/73943232/138328685-5bd035b9-a13f-4cb3-bd6d-e311c8de154d.png">


 
## map结构体排序

 > 之前说过map属于集合容器是不能进行sort排序的，要排序的话得用vector进行排序，这里就用到了vector，我们去定义一个bool cmp去设置我们需要的排序方式
 (bool cmp一般是放在sort里面的，而struct cmp是放在构造容器时里面的）我们把map放进vector里面然后排序就得到了结果.
<img width="1063" alt="截屏2021-10-22 01 47 09" src="https://user-images.githubusercontent.com/73943232/138330314-cf864b80-025a-468e-b41f-3d8173923676.png">
<img width="1063" alt="截屏2021-10-22 01 47 37" src="https://user-images.githubusercontent.com/73943232/138330387-3ebe6c9a-97ac-45b9-bc77-6985c738d7e7.png">
 
 ## set构造排序
 > set的构造排序和map一样，这里就不说了下面有两个例子

 <img width="1064" alt="截屏2021-10-22 01 51 55" src="https://user-images.githubusercontent.com/73943232/138330944-3c2d9a7a-a216-486e-8fb5-9f977aa1654b.png">
<img width="1060" alt="截屏2021-10-22 01 55 16" src="https://user-images.githubusercontent.com/73943232/138331404-b5d7e3d2-7381-48dc-a5de-cb8aca00e255.png">

## 练习
 
 > 为了检测自己是否真的弄懂了，我想了个题目，就是学生成绩进行排序，我的想法是成绩按照倒序排列就是成绩高的学生在前面，成绩相同就按照名字的长度进行
 排序，名字长度大的在前面，名字长度一样的就按照名字的字典序排序，下面就是我写的代码
<img width="1064" alt="截屏2021-10-22 01 55 55" src="https://user-images.githubusercontent.com/73943232/138331496-8be2832f-0f69-4a40-8b6f-2c6401de8ec9.png">
<img width="1066" alt="截屏2021-10-22 01 58 06" src="https://user-images.githubusercontent.com/73943232/138331778-e349bd36-8a92-4fc5-ad51-7947713fea71.png">

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
 
