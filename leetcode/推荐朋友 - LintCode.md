- 拼多多笔试第三题
- 除了题目具体方法值得注意外，数据的输入格外注意

## 题目

```
描述
给n个人的朋友名单，告诉你user，请找出user最可能认识的人。（他和user有最多的共同好友且他不是user的朋友）

n <= 500。
好友关系是相互的。（b若出现在a的好友名单中，a一定出现在b的好友名单中）
每个人的好友关系不超过 m 条，m <= 3000。
如果有两个人和user的共同好友数目一样，编号更小的那个认为是最可能认识的人。
如果user和所有陌生人都没有共同好友，输出-1。

样例
给出 list = [[1,2,3],[0,4],[0,4],[0,4],[1,2,3]], user = 0, 返回 4。

解释：
0和4不是朋友，并且他们有3个共同好友。所以4是0最可能认识的人。

给出 list = [[1,2,3,5],[0,4,5],[0,4,5],[0,5],[1,2],[0,1,2,3]], user = 0, 返回 4。

解释：
虽然5和0有3个共同好友，4和0只有2个共同好友，但是5是0的好友，所以4是0最可能认识的人。
```

## 解析

- 思路: 首先找到不是user朋友的人，再根据user的朋友名单，计算出和user的共同好友数，结果返回最多共同好友的人。
- 输入：

```
5 0
1 2 3
0 4
0 4
0 4
1 2 3

```

```C++

#if 1

#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;

int recommendFriends(vector<vector<int>> &friends, int user) {
	// Write your code here 
	if (friends.empty())
		return -1;
	int num = friends.size();
	//res存放不是user的朋友的人与user共同好友的个数
	map<int, int> res;
	if (friends[user].empty())
		return -1;
	//dic[i]=1表示i是user或者是user的朋友,dic[i]=0表示i不是user的朋友
	vector<int> dic(num, 0);
	dic[user] = 1;
	for (auto c : friends[user])
	{
		dic[c] = 1;
	}
	//找到不是user好友的人
	for (int i = 0; i < num; ++i)
	{
		if (dic[i] == 0)
			res[i] = 0;
	}
	//根据user的好友名单更新res
	for (auto c : friends[user])
	{
		for (auto t : friends[c])
		{
			if (res.find(t) != res.end())
				res[t]++;
		}
	}
	int Max = 0;
	int person = -1;
	//找到有最多共同好友的人
	for (auto c : res)
	{
		if (c.second > Max)
		{
			Max = c.second;
			person = c.first;
		}
	}
	return person;
}


int main()
{
	int N, id;
	string str;
	getline(cin, str);
	stringstream ss(str);
	ss >> N >> id;

	vector<vector<int>> vec;
	//for (int i = 0; i < N; i++)
	//{
	//	vector<int> temp;
	//	int user;
	//	getline(cin, str);
	//	stringstream s(str);
	//	while (s>>user) //以空格进行划分
	//	{
	//		temp.push_back(user);
	//	}
	//	vec.push_back(temp);
	//}

	while (getline(cin, str)) //其实可都可以不知道行数
	{
		vector<int> temp;
		int user;
		stringstream s(str);
		while (s >> user)
		{
			temp.push_back(user);
		}
		vec.push_back(temp);
	}

	cout << recommendFriends(vec, id) << endl;

	return 0;
}

int test()
{
	//int N,id;
	//cin >> N >> id; //直接输入用户数和需要查找的用户id ; 这样就会产生换行符

	int N;
	vector<int> in;
	char c;
	while ((c = cin.get()) != '\n')
	{
		cin.unget();
		cin >> N; 
		in.push_back(N);
	}
	
	vector<vector<int>> vec;
	for (int i = 0; i < in[0]; i++)
	{
		vector<int> temp;
		int user;
		
		while ((c=cin.get())!= '\n') //文件结果没有换行符了，所以陷入死循环
		{
			cin.unget();
			cin >> user;
			temp.push_back(user);
		}
		if (temp.size()!=0)
		{
			vec.push_back(temp);
		}
		
	}

	cout << recommendFriends(vec, in[1]) << endl;

	return 0;
}


#endif
```

## 题目参考：

- [推荐朋友 - LintCode](https://blog.csdn.net/zhaohengchuan/article/details/80364732)
- [HDU - 4039 The Social Network （BFS）](https://blog.csdn.net/CrazyForsaken/article/details/78575057)
