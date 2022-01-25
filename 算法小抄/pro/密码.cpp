#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int openLock( vector<string> deadlines , string target );
string upNum(string num , int k);
string downNum(string num , int k);

int main(){
    string s = "0000";
    vector<string> deadlines;
    deadlines.push_back("1010");
    deadlines.push_back("1111");
    int step = openLock(deadlines,"2361");
    cout << step << endl;
    return 0;
}


int openLock( vector<string> deadlines , string target )
{
    unordered_set<string> deads;
    for(int i = 0 ; i < deadlines.size() ; i++){
        deads.insert(deadlines[i]);
    }
    unordered_set<string> visited;//存放已经访问过的数组
    queue<string> q;//用来BFS

    int  step = 0 ;//记录步数
    q.push("0000");

    while(!q.empty())
    {
        int sz = q.size();//因为是广度优先遍历所以需要
        for(int i = 0 ; i < sz ; i++){
            //去出对头元素
            string  temp = q.front();
            q.pop();
            if(deads.count(temp)) continue;
            if(temp == target){
                return step;
            }
            for (int j = 0; j < 4; j++)
            {
                string up = upNum(temp, j);
                if(visited.count(up)==0){
                    visited.insert(up);
                    q.push(up);
                }
                string down = downNum(temp, j);
                if(visited.count(down)==0){
                    visited.insert(down);
                    q.push(down);
                }
            }
        }
        step++;
    }
    return -1;
}

string upNum(string num , int k){
    if(num[k]=='9'){
        num[k] = '0';
    }else{
        num[k]++;
    }

    return num;
}

string downNum(string num , int k){
    if(num[k]=='0'){
        num[k]='9';
    }else{
        num[k]--;
    }
    return num;
}
