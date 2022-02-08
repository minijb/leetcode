#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief
 * 方法一：横向扫描，对比顺序：S1-S2=>C1  C1-S3=>C2 ......
 * 时间复杂度：O(mn)
 */
string Compare(string s1, string s2);
int min(int a, int b);
string longestCommonPrefix1(vector<string>& strs);
/**
 *	纵向扫描：把vector没个字符串纵向排列，分别比较每行字母，遇到的第一列由不同的则结束
 */
string longestCommonPrefix2(vector<string>& strs);

int main() {
	vector<string> strs = { "ab","a" };
	cout << longestCommonPrefix2(strs) << endl;
	return 0;
}


int min(int a, int b) {
	return (a < b) ? a : b;
}

string Compare(string s1, string s2) {
	int min_size = min(s1.size(), s2.size());
	int  i = 0;//指向字符串的首位
	while (i < min_size && s1[i] == s2[i])
	{
		++i;
	}
	return s1.substr(0, i);
}

string longestCommonPrefix1(vector<string>& strs)
{
	if (!strs.size()) return "";
	else if (strs.size() == 1) return strs[0];
	string temp = Compare(strs[0], strs[1]);
	for (int i = 2; i < strs.size(); ++i)
	{
		temp = Compare(temp, strs[i]);
		//为了优化算法，当temp长度为0时直接结束循环
		if (!temp.size()) break;
	}
	return  temp;

}

string longestCommonPrefix2(vector<string>& strs)
{
	if (!strs.size()) return "";
	else if (strs.size() == 1) return strs[0];
	char temp;
	for (int i = 0; i < strs[0].size(); ++i)//此为横向移动
	{
		temp = strs[0][i];
		for (int j = 1; j < strs.size(); ++i)//strs[j][i]
		{
			if(strs[j][i]==NULL||strs[j][i]!=temp)//如果不同则返回
			{
				if (i == 0) return "";
				return strs[0].substr(0, i+1);
			}
		}
	}
	return strs[0];
}