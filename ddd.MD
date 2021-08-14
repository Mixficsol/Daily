# 仿QQ管理系统
## （1）功能的实现
##### 1.第一步就是完成登录和注册保存信息
```
void load() {
	axl:
	cout << "欢迎来到QQ登录中心,请问您是新用户吗: (Y/N)  ";
	cin >> c;
	if (c == 'Y') {
		ifstream fi("test.txt");
		set:
		cout << "欢迎来到注册中心请注册你的信息:" << '\n' << "accout:";
		cin >> insert;
		while (fi >> accout) {
			if (insert == accout) {
				cout << "该账户已经被注册过了,请再试一次吧" << endl;
				goto axl;
			}
		}
		ofstream fo("test.txt", ios::app);
		cout << "password:"; 
		accout = insert;
		cin >> password;
		if (password.length() < 6) {
			cout << "密码安全系数不够哦!请重新设置密码长度6位以上的密码" << endl;
			goto set;
		}
		fo << accout << endl;
		fo << password << endl;
		cout << "注册成功!  现在你可以登录QQ了!" << "\n" << "accout:";		
		fo.close();
		cout << accout << endl;
		cout << "password:";
		cin >> scan;
		while (password != scan) {
			cout << "密码错误,请再试一次\n";
			cout << "accout:";
			cout << accout;
			cout << '\n' << "password:";
			cin >> scan;
		}
		cout << "登录QQ成功!" << '\n';
	} 
	else if (c == 'N') {
		cout << "请输入您的QQ号以及密码: " << "\n" << "accout: ";		
		cin >> scan;	
		i = 1;
		flag = 1;	 
		ifstream fi("test.txt");
		while (fi >> accout) {
			if (scan == accout) {
				flag = 0;
				break;
			}
			i++;
		}
		if (flag) {
			cout << "该账户不存在哦!请再试一次" << endl;
			goto axl;
		}
		for (j = 0; j != i; j++) {
			fi >> password;
		}
		cout << "password:";
		cin >> scan;
		while (password != scan) {
			cout << "密码错误,请再试一次\n";
			cout << "accout:";
			cout << accout << endl;
			cout << "password:";
			cin >> scan;
		}
		cout << "登录QQ成功!" << '\n';
	} else {
		cout << "输入有误哦,请再输入一次吧!" << endl;
		goto axl;
	}
}

```

##### 2.创建父链表和子链表并且初始化
```
link creat() {      //  创建子链表
	link head;
	head = (link)malloc(LEN1);
	head->next = NULL;
	return head;
}

link1 creat1() {   //  创建父链表
	link1 head1;
	head1 = (link1)malloc(LEN2);
	head1->next = NULL;
	head1->con = NULL;
	return head1;
}

```
##### 3.创建完链表后就是实现我们的第一个功能也就是添加好友以及新建分组的功能，这里我使用的是尾插法进行好友信息和组名信息的输入
```
link ins(link head) {         // 尾插法
	link p2, p1;
	p2 = head;
	while (p2->next != NULL) {
		p2 = p2->next;
	}
	p1 = (link)malloc(LEN1);
	next:
	cout << "请在下面依次输出你想加的好友的姓名,QQ号以及年龄" << endl;
	cout << "姓名: ";
	cin >> p1->name;
	cout << "QQ号: ";
	cin >> p1->number;
	cout << "年龄: ";
	cin >> p1->age;
	if(cin.fail()) {
		cout << "输入有错误,请再试一次!" << endl;
		cin.clear();
		cin.ignore(1024, '\n'); 
		goto next;
	} else {
		p2 = p2->next = p1;
		p2->next = NULL;
		x++;
		return head;
	}
}

```
```
link1 ins1(link1 head1) {   //  新建好友列表功能(3)的实现,运用的是尾插法
	link1 p2, p1;
	p2 = head1;
	while (p2->next != NULL) {
		p2 = p2->next;
	}
	p1 = (link1)malloc(LEN2);
	cout << "请在下面输出新建组名" << endl;
	cout << "组名: ";
	cin >> p1->name;
	p2 = p2->next = p1;
	p2->next = NULL;
	p2->con = NULL;
	y++;
	return head1;
}

```
##### 4.把新建的好友以年龄的大小进行排序,我采用的是冒泡排序,代码如下：
