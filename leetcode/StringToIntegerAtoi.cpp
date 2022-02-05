/**
 * @file StringToIntegerAtoi.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "common.h"
class Solution {
public:
    int myAtoi(string s) {
        bool isNegative = false;
        int cur_index = 0;
        while(s[cur_index] == ' ')
            cur_index++;
        if (s[cur_index] == '-') {
            cur_index++;
            isNegative = true;
        } else if (s[cur_index] == '+') {
            cur_index++;
            isNegative = false;
        }
        
        int result = 0;
        while (s[cur_index] >= '0' && s[cur_index] <= '9') {
            // must be if {} else  {}
            if (!isNegative) {
                if(result > INT_MAX / 10 || 
                    (result == INT_MAX / 10 && s[cur_index] - '0' >= INT_MAX % 10)) 
                    return INT_MAX;
            }
            else {  //  must be <= INT_MIN % 10 
                if(-result <INT_MIN / 10 || (-result == INT_MIN/10 && '0'-s[cur_index]<=INT_MIN % 10)) 
                    return INT_MIN;

            }

            result = result * 10 + (s[cur_index] - '0');
            cur_index++;
        }
        if (isNegative)
            return result*(-1);
        else 
            return result;
    }
};

int main()
{
    cout << Solution().myAtoi("-91283472332") << endl;
    cout << Solution().myAtoi("-2147483648") << endl;
    cout << INT_MAX << endl;
}