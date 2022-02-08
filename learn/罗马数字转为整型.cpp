#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  //自己的
    int  get_value(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
          return 50;
          break;
        default:
            break;
        }
    }   
    
    int romanToInt(string s)
    {
        unordered_map<char , int > map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int sum = 0,temp1=map[s[0]],temp2;
        for(int  i = 1 ; i < s.size() ; ++i)
        {
            temp2 = map[s[i]];
            if (temp1 == temp2) temp1 += temp2;
            else if (temp1 > temp2 || temp1 == 0) {
                sum += temp1;
                temp1 = temp2;
            }
            else {
            sum += temp2 - temp1;
            temp1 = 0;
            temp2 = 0;
        }
        }
        if (temp1 != 0) sum += temp1;
        return sum;
    }

};