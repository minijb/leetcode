#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int min(int a , int b);
//暴力解法
int maxArea1(vector<int> &height);
//双指针法,连个指针分别从在头尾向中间移动
// 哪边小 移动哪一边
int maxArea2(vector<int> &height);
int main() {}

int maxArea1(vector<int> &height) {
  int temp = 0;
  for (int i = 0; i < height.size(); ++i) {
    for (int j = i + 1; j < height.size(); ++j) {
      int area = min(height[i], height[j]) * (j - i);
      temp = (temp < area) ? area : temp;
    }
  }
  return temp;
}


int maxArea2(vector<int> &height)
{
    int low = 0 , high = height.size();
    int temp = (high - low) * min(height[low], height[high]);
    while(low!=high)
    {
        if(height[low] < height[high])
        {
            ++low;
        }else {
            --high;
        }
        int current = (high - low) * min(height[low], height[high]);
        temp = (temp < current) ? current : temp ;
    }
    return temp;
}

int min(int a , int b)
{
    return (a<b)?a:b;
}
