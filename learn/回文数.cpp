#include <iostream>
#include <unordered_map>

using namespace std;
//如何将数字反转
//1.字符串方法
//2.数学方法
bool reverse(int x);
int main()
{
    bool a = reverse(121);
    cout << a << endl;
    return 0;
}

bool reverse(int x)
{
    char a = 'a';
    if (x < 0) return false;
    if (x >= 0 && x < 10) return true;
    int tail;//sum用来反转的总值，tail用来收集数字
    int y = x;
    long sum = 0;
    while (x != 0)
    {
        tail = x % 10;
        sum = sum * 10 + tail;
        x = x/10;
    }
    return y == sum;
}

