#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int openLock(vector<string> deadlines, string target);
string upNum(string num, int k);
string downNum(string num, int k);
int double_openLock(vector<string> deadlines, string target);

int main()
{
    string s = "0000";
    vector<string> deadlines;
    deadlines.push_back("1010");
    deadlines.push_back("1111");
    int step = double_openLock(deadlines, "2361");
    cout << step << endl;
    return 0;
}

int openLock(vector<string> deadlines, string target)
{
    unordered_set<string> deads;
    for (int i = 0; i < deadlines.size(); i++)
    {
        deads.insert(deadlines[i]);
    }
    unordered_set<string> visited; //存放已经访问过的数组
    queue<string> q;               //用来BFS

    int step = 0; //记录步数
    q.push("0000");
    visited.insert("0000");
    while (!q.empty())
    {
        int sz = q.size(); //因为是广度优先遍历所以需要
        for (int i = 0; i < sz; i++)
        {
            //去出对头元素
            string temp = q.front();
            q.pop();
            if (deads.count(temp))
                continue;
            if (temp == target)
            {
                return step;
            }
            // visited.insert(temp);
            for (int j = 0; j < 4; j++)
            {
                string up = upNum(temp, j);
                if (visited.count(up) == 0)
                {
                    visited.insert(up);
                    q.push(up);
                }
                string down = downNum(temp, j);
                if (visited.count(down) == 0)
                {
                    visited.insert(down);
                    q.push(down);
                }
            }
        }
        step++;
    }
    return -1;
}

//需要注意的是双向bfs向visited添加的地方不同！！！！
/**
 * @brief 
 * 双向bfs必须使q1,q2有重复部分才可以判断结束
 * 而单向bfs必须保证自己队列中没有重复部分才可以判断是否达到目标
 * 因此两者的visited.insert语句添加的位置不同!!!!!!!!
 */
int double_openLock(vector<string> deadlines, string target)
{
    unordered_set<string> deads;
    for (int i = 0; i < deadlines.size(); i++)
    {
        deads.insert(deadlines[i]);
    }
    //不使用queue使用set快速判断元素是否存在
    //基本思想是，使用set存放下一层的元素，之前的元素不会出现再set中，而是出现在queue中
    unordered_set<string> q1;
    unordered_set<string> q2;
    unordered_set<string> visited;
    q1.insert("0000");
    q2.insert(target);
    int step = 0;
    while (q1.empty() == 0 && q2.empty() == 0)
    {
        unordered_set<string> temp;
        for (string s : q1)
        {
            if (deads.count(s))
                continue;
            //如果q2含有q1的值说明两个BFS相遇那么就可以表明找到路径
            if (q2.count(s))
                return step;
            visited.insert(s);
            //将下一层的bfs节点放入到temp中
            for (int j = 0; j < 4; j++)
            {
                string up = upNum(s, j);
                if (visited.count(up) == 0)
                { //放入temp
                    temp.insert(up);
                }
                string down = downNum(s, j);
                if (visited.count(down) == 0)
                {
                    temp.insert(down);
                }
            }
        }
        step++;
        q1 = q2;
        q2 = temp;
    }
    return -1;
}

string upNum(string num, int k)
{
    if (num[k] == '9')
    {
        num[k] = '0';
    }
    else
    {
        num[k]++;
    }

    return num;
}

string downNum(string num, int k)
{
    if (num[k] == '0')
    {
        num[k] = '9';
    }
    else
    {
        num[k]--;
    }
    return num;
}