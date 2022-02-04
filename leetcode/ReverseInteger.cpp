/**
 * @file ReverseInteger.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a signed 32-bit integer x, return x with its digits reversed. 
 * If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 */
#include "common.h"

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0) {
            int m = x % 10;
            x = x / 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && m > INT_MAX % 10)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && m < INT_MIN % 10)) return 0;
            result = result * 10 + m;
        } 
        
        return result;
    }
};

int main()
{
    cout << Solution().reverse(130) << endl; 
    cout << Solution().reverse(-2147483648) << endl; 
}