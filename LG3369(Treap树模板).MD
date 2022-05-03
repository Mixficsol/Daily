日期 2022 / 5 / 3
<img width="1104" alt="截屏2022-05-03 21 39 52" src="https://user-images.githubusercontent.com/73943232/166463633-20202bd4-669a-4f15-8fc1-071c4e0f76ab.png">

题目链接:<https://www.luogu.com.cn/problem/P3369>

# 题目
##  题目描述
>您需要写一种数据结构（可参考题目标题），来维护一些数，其中需要提供以下操作：
>插入x数
>删除x数(若有多个相同的数，因只删除一个)
>查询x数的排名(排名定义为比当前数小的数的个数+1。若有多个相同的数，因输出最小的排名)
>查询排名为x的数
>求x的前驱(前驱定义为小于xx，且最大的数)
>求x的后继(后继定义为大于xx，且最小的数)
## 输入输出格式
### 输入格式：
>第一行为n，表示操作的个数,下面n行每行有两个数opt和x，opt表示操作的序号( 1≤opt≤6 )
### 输出格式：
>对于操作3,4,5,6每行输出一个数，表示对应答案
### 输入输出样例
### 输入样例#1：
>10
>
>1 106465
>
>4 1
>
>1 317721
>
>1 460929
>
>1 644985
>
>1 84185
>
>1 89851
>
>6 81968
>
>1 492737
>
>5 493598
### 输出样例#1：
>106465
>
>84185
>
>492737
# 解题思路
>这个一个Treap树的模板题，包括了插入删除，查询等操作.题解写在注释里面了

# 代码演示
```cpp
#include <iostream>

#define INF 0x3f3f3f
#define L tree[i].left
#define R tree[i].right

using namespace std;
const int N = 1e5 + 5;

struct Tree {
  int left, right;  // 左右节点编号
  int key, val;  // key是键值大小，val表示由rand()函数分配的优先级，不断旋转保证编号大的点一定在编号小的点的上方	
  int cnt, size; // cnt表示键值key的点有多少个，size表示以i为根的树有多少个点
} tree[N];

int root, idx;	//  root表示根节点，idx代表节点编号

void pushup(int i) { // 统计以i为根节点的树一共有多少个点
  tree[i].size = tree[L].size + tree[R].size + tree[i].cnt; // 总的节点 = 左子树的节点 + 右子树的节点 + 该节点上重复的节点数
}

int getNode(int key) {	// 新建节点
  tree[++idx].key = key; //确定键值
  tree[idx].val = rand();	//随机分配优先级
  tree[idx].cnt = tree[idx].size = 1;	
  return idx;	// 返回节点编号		
}

void zig(int &i) {   //右旋
  int q; 
  q = L; // L表示tree[i].left
  L = tree[q].right; // 将tree[i].left设置为之前tree[i].left的右孩子
  tree[q].right = i; // 将旋转后的节点的右孩子设置为旋转前的根节点
  i = q; //将根节点设置为旋转后的节点
  pushup(R); // 重新统计节点个数
  pushup(i); // 重新统计节点个数
}

void zag(int &i) {    //左旋，原理与上面相似
  int q;
  q = R;
  R = tree[q].left;
  tree[q].left = i;
  i = q;
  pushup(L);
  pushup(i);
}

void insert(int &i, int key) {	
  if (!i) { //如果没有根节点，则新建根节点
	i = getNode(key);	
  }	
  else if (tree[i].key == key) { //如果键值大小和根节点一样就加到cnt
	tree[i].cnt++;	
  }
  else if (tree[i].key > key) {	//如果键值小于根节点则插入左孩子	
	insert(L, key);
	if (tree[L].val > tree[i].val) { // 如果当前节点的优先级大于根节点则右旋
	  zig(i);		
	}
  } else {		 //如果键值大于根节点则插入右孩子	
    insert(R, key);
	if (tree[R].val > tree[i].val) { // 如果当前节点的优先级小于根节点则左旋
	  zag(i);
	}
  }
  pushup(i);		
}

void remove(int &i, int key) {		
  if (!i) {
    return;	
  }			
  if (tree[i].key == key) {
    if (tree[i].cnt > 1) { //如果删除的点有重复个值则在cnt中减去
	  tree[i].cnt--;
	}	
	else if (L || R) {			
	  if (!R || tree[L].val > tree[R].val) {	
	    zig(i);
		remove(R, key);
	  } else {
		zag(i);
		remove(L,key);
	  }
	} else {
	  i = 0;
	}		
  }
  else if (tree[i].key > key) {
    remove(L, key);
  } else {
	remove(R, key);	
  }	
  if (i) {
    pushup(i);
  }	
}

int kth(int &i, int key) { // 查询当前键值key的排名
  if (!i) {
    return 0;
  }		
  if (tree[i].key == key) {
	return tree[L].size + 1;		
  }
  if (tree[i].key > key) {
	return kth(L, key);		
  }
  return tree[L].size + tree[i].cnt + kth(R, key);		
}

int find(int &i, int rank) {		
  if (!i) {
    return INF;			
  }
  if (tree[L].size >= rank) {
	return find(L, rank);	
  }
  if (tree[L].size + tree[i].cnt >= rank) {
	return tree[i].key;	
  }
  return find(R, rank - tree[L].size - tree[i].cnt);	
}

int getPrev(int &i, int key) { // 寻找key的前驱
  if (!i) {
    return -INF;			
  }
  if (key <= tree[i].key) { // 如果key小于当前节点的key则递归到左子树
	return getPrev(L, key);	
  }
  return max(tree[i].key, getPrev(R, key));	
}

int getNext(int &i, int key) {   // 寻找key的后继   
  if (!i) {
    return INF;			
  }
  if (tree[i].key <= key) {
    return getNext(R, key);
  }
  return min(tree[i].key, getNext(L, key));
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, x;
	cin >> k >> x;
	if (k == 1) {
	  insert(root, x);		
	}
	else if (k == 2) {
	  remove(root, x);		
	}
	else if(k == 3) {
	  cout << kth(root, x) << endl;
	}	
	else if (k == 4) {
	  cout << find(root, x) << endl;
	}
	else if (k == 5) {
	  cout << getPrev(root, x) << endl;
	} else {
	  cout << getNext(root, x) << endl;	
	}
  }
  return 0;
}
```
