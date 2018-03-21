
#include<iostream>
#include<math.h>

#include <vector>
#include <string>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <algorithm>
#include <functional>
#include <numeric> //accmulate

using namespace std;

// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//#define test01
//#define test02
#define test03

#ifdef test01

int getMaxLengthSub(string s1, string s2)
{
	int ret = 0;
	vector<vector<int> > vecs(s1.size() + 1, vector<int>(s2.size() + 1, 0));

	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1]) //�±�
			{
				vecs[i][j] = vecs[i - 1][j - 1] + 1;
			}
			else
			{
				vecs[i][j] = max(vecs[i - 1][j], vecs[i][j - 1]);
			}
		}
	}
	ret = vecs[s1.size()][s2.size()];
	return ret;
}

int main()
{
	//���ж�ά����f[i, j] ��ʾ X �� i λ�� Y �� j λ֮ǰ������������еĳ���

	string input;
	while (cin >> input)
	{
		string temp(input); //����һ��
		reverse(input.begin(), input.end());

		int max_com = getMaxLengthSub(input, temp);

		cout << (input.size() - max_com) << endl; //<<endl���˻��в���ͨ����������
	}

	return 0;
}

#endif // test01

#ifdef test02

void char_shift(string &src)
{
	string str;


	int end = src.size() - 1;
	for (int i = 0; i <= end;)
	{
		if (src[i] >= 'A'&&src[i] <= 'Z')
		{
			char temp = src[i];
			for (int j = i + 1; j < src.size(); j++)
			{
				src[j - 1] = src[j];
			}
			src[src.size()-1] = temp;
			end--;
		}
		else
		{
			i++; //û�д�д�ַ���ʱ���++
		}
	}


	return;
}

int main()
{
	string input;

	while (cin>>input)
	{
		char_shift(input);
		cout << input<<endl;
	}
	return 0;
}

#endif

#ifdef test03

void getMinMaxPair(vector<int> vec,int &min_pair,int &max_pair)
{

}

int main()
{
	int N;
	while (cin>>N)
	{
		vector<int> vec;
		int temp;
		for (int i = 0; i < N;i++)
		{
			cin >> temp;
			vec.push_back(temp);
		}

		int max_pair = 0, min_pair = 0;

		getMinMaxPair(vec,min_pair,max_pair);

		cout << min_pair << " " << max_pair << endl;
	}
	return 0;
}


//���ӣ�https://www.nowcoder.com/questionTerminal/af709ab9ca57430886632022e543d4c6
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int num, i, j;
	while (cin >> num)//����Ԫ�ص��ܸ���
	{
		if (num < 2)
		{
			cout << 0 << " " << 0 << endl;
			continue;
		}
		vector<int> arr;//arr��Ҫ����Ϊȫ�ֱ���,��Ȼȫ���������ݶ���������arr
		int length = num;
		int temp;
		while (num--)//����д��while(cin>>temp)����Ȼ��ȫ���������ݶ���һ���Դ�����arr
		{
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());//C++����������[begin,end)������Ԫ������

		//����СֵminVal
		int minVal = arr[1] - arr[0];
		for (i = 1; i < length - 1; ++i)
		{
			int cur = arr[i + 1] - arr[i];
			if (cur < minVal)
				minVal = cur;
		}
		//����Сֵ�ĸ���minCount
		int minCount = 0;
		if (minVal == 0)//arr�������Ԫ��ʱ
		{
			for (i = 0; i < length - 1; ++i)
			{
				for (j = i + 1; j < length; ++j)
				{
					if (arr[i] == arr[j])
						++minCount;
				}
			}
		}
		else//arr����Ԫ�����ʱ
		{
			for (i = 0; i < length - 1; ++i)
			{
				int cur = arr[i + 1] - arr[i];
				if (cur == minVal)
				{
					++minCount;
				}
			}
		}

		//�����ֵmaxVal
		int maxVal = arr[length - 1] - arr[0];
		//�����ֵ�ĸ���maxCount
		int maxCount = 0;
		if (maxVal == 0)//ȫ��Ԫ�ض����,�������ԭ��
		{
			maxCount = length*(length - 1) / 2;
		}
		else//�в�ͬ��Ԫ��,���ֵ�ĸ���=��С�ĸ���*���ĸ���
		{
			int smallCount = 0, bigCount = 0;
			for (i = 0; i < length; ++i)
			{
				if (arr[i] == arr[0])
					++smallCount;
				else if (arr[i] == arr[length - 1])
					++bigCount;
			}
			maxCount = smallCount*bigCount;
		}
		cout << minCount << " " << maxCount << endl;
	}
	return 0;
}
#endif