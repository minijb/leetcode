#include <iostream>
#define INT_MAX  2147483647
#define INT_MIN  -2147483648
using namespace std;

int myAtoi(string s) {
  int flag = 1;
  int point = 0;
  int temp = 0;
  while (s[point] == ' ') {
    point++;
  }
  if (s[point] < 48 || s[point] > 57) {
    if (s[point] != 43 && s[point] != 45)
      return 0;
    else if (s[point] == 45)
      flag = -1;
    point++;
  }

while (s[point] >= 48 && s[point] <= 57) {
    
//当遇到最大值和最小值的时候要注意不能用超过来判断，一定要实现判断！！！
    if (temp > INT_MAX / 10 ||
        (temp == INT_MAX / 10 && (s[point] - '0') > INT_MAX % 10)) {
      return INT_MAX;
    }
    if (temp < INT_MIN / 10 ||
        (temp == INT_MIN / 10 && (s[point] - '0') > -(INT_MIN % 10))) {
      return INT_MIN;
    }
    temp = temp * 10 + flag * (s[point] - 48);
    point++;
  }
  return temp;
}
