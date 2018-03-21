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


int GetLongestComSub(string str1,string str2)
{
	int m = str1.size();
	int n = str2.size();

	vector<vector<int >> vecs(m + 1, vector<int>(n + 1, 0));
	int max_len = 0;

	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (str1[i]==str2[j])
			{
				vecs[i + 1][j + 1] = vecs[i][j]+1;
				if (max_len<vecs[i+1][j+1])
				{
					max_len = vecs[i+1][j+1];
				}
			}
		}
	}

	return max_len;
}
//
//��������:
//Sit it out G
//Sit down and shut up

//cin�����ַ������ܽ᣺
//
//�����ַ��������ո񡢻س���TAB����ʾһ������Ľ����������Ŀ��ַ��ᱻ���ԡ�
int main()
{
	string str1, str2;
	/*cin >> str1;
	cin >> str2;*/
	getline(cin, str1);
	getline(cin, str2);

	cout<<GetLongestComSub(str1,str2)<<endl;

	return 0;
}



int  GetMaxRect(vector<int>& vec)
{
	int max_area = vec[0];

	for (int i = 1; i < vec.size();i++)
	{
		int low = i - 1, high = i + 1;
		while (low >= 0 && vec[i] <= vec[low])
	        low--;	
		while (high<vec.size() && vec[i] <= vec[high])
			high++;
			
		max_area = max(max_area, vec[i] * (high - low-1));
	}

	return max_area;
}

//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> vec;
//	int temp = 0;
//	for (int i = 0; i < n;i++)
//	{
//		cin >> temp;
//		vec.push_back(temp);
//	}
//
//	cout << GetMaxRect(vec) << endl;
//
//	return 0;
//}


//int main()
//{
//	int n;
//	cin >> n;
//
//	int table[] = { 1, 5, 10, 20, 50, 100 }; //6�����
//	//���ֺܴ�ʱ��int��ʾ����  
//	vector<vector<long long>> dp(sizeof(table) / sizeof(int), vector<long long>(n + 1, 0)); //dp[i][j]��ʾ��ǰ��i+1���������ϳ�j���ķ�����
//	for (int j = 0; j <= n; j++)
//	{
//		dp[0][j] = 1;
//	}
//	for (int i = 1; i < 6; i++)
//	{
//		for (int j = 0; j <= n; j++)
//		{
//			for (int k = 0; k <= j / table[i]; k++) //j=0ʱ��dp[i][j] = dp[i - 1][j]
//			{
//				dp[i][j] += dp[i - 1][j - k*table[i]];
//			}
//		}
//	}
//
//	cout << dp[5][n] << endl;
//	return 0;
//}

///*��̬�滮
//��Ҫƴ�յ������n��
//ά��dp[i],��ʾȡ��iʱ�������Ŀ��dp[0]=1��
//�������a[6]={1,5,10,20,50,100}��
//dp[j]=dp[j]+dp[j-a[i]],Լ������j>a[i]��
//��Ϊ�����Ŀ���⣬������Ҫ�ֱ���ֻ�����1ʱ�����Ǯ��Ϊ1~n�ĸ��������dp[1]~dp[n],
//Ȼ�������1,5ʱ�����Ǯ��Ϊ1~n�ĸ��������dp[1]~dp[n],�������ơ��������������
//*/
//#include<iostream>  
//#include<vector>  
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int a[6] = { 1, 5, 10, 20, 50, 100 };
//	vector<long> dp(n + 1, 0);   //�����ֺܴ�ʱ��int��ʾ����  
//	dp[0] = 1;
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (j >= a[i])
//				dp[j] = dp[j] + dp[j - a[i]];   //jֵȡ�Ͳ�ȡ������������Ŀ֮��  
//		}
//	}
//	cout << dp[n] << endl;
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	
//	int* fn = new int[n];
//	fn[0] = 1;
//	fn[1] = 2;
//	
//	for (int i = 2; i < n;i++)
//	{
//		int ret = 0;
//		for (int j = 0; j < i;j++)
//		{
//			ret += fn[j];
//		}
//		fn[i] = ret + 1;
//	
//	}
//	cout << fn[n - 1] << endl;
//	return 0;
//}

