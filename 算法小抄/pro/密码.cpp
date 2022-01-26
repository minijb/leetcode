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
    unordered_set<string> visited; //����Ѿ����ʹ�������
    queue<string> q;               //����BFS

    int step = 0; //��¼����
    q.push("0000");
    visited.insert("0000");
    while (!q.empty())
    {
        int sz = q.size(); //��Ϊ�ǹ�����ȱ���������Ҫ
        for (int i = 0; i < sz; i++)
        {
            //ȥ����ͷԪ��
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

//��Ҫע�����˫��bfs��visited��ӵĵط���ͬ��������
/**
 * @brief 
 * ˫��bfs����ʹq1,q2���ظ����ֲſ����жϽ���
 * ������bfs���뱣֤�Լ�������û���ظ����ֲſ����ж��Ƿ�ﵽĿ��
 * ������ߵ�visited.insert�����ӵ�λ�ò�ͬ!!!!!!!!
 */
int double_openLock(vector<string> deadlines, string target)
{
    unordered_set<string> deads;
    for (int i = 0; i < deadlines.size(); i++)
    {
        deads.insert(deadlines[i]);
    }
    //��ʹ��queueʹ��set�����ж�Ԫ���Ƿ����
    //����˼���ǣ�ʹ��set�����һ���Ԫ�أ�֮ǰ��Ԫ�ز��������set�У����ǳ�����queue��
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
            //���q2����q1��ֵ˵������BFS������ô�Ϳ��Ա����ҵ�·��
            if (q2.count(s))
                return step;
            visited.insert(s);
            //����һ���bfs�ڵ���뵽temp��
            for (int j = 0; j < 4; j++)
            {
                string up = upNum(s, j);
                if (visited.count(up) == 0)
                { //����temp
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