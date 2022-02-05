/**
 * @file PalindromeNumber.cpp
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
    bool isPalindrome(int x) {
        

        // while (x) {
        //     x2 = x2 * 10 + x % 10;  // signed integer overflow
        //     x /= 10;
            
        // }
  

        if (x < 0 || (x%10 == 0 && x != 0)) return false;
        int x1 = x;
        int x2 = 0;
        while (x > x2) {
            x2 = x2 * 10 + x % 10;  
            x /= 10;
            
        }
        cout << x << ", " << x2 << endl;

        if (x <= 0) { 
            x = x1;
            x2 = 0;
            while (x) {
                x2 = x2 * 10 + x % 10;  // will not overflow
                x /= 10;
            }
            
            return x2 == x1;
        } else {
            return  x == x2 / 10 || x == x2;
        }
    }
};

int main() 
{
    cout << Solution().isPalindrome(121) << endl;
    cout << Solution().isPalindrome(12321) << endl;
    cout << Solution().isPalindrome(1023) << endl;
    cout << Solution().isPalindrome(10) << endl;
    cout << Solution().isPalindrome(11) << endl;
    cout << Solution().isPalindrome(1030100) << endl;
    cout << Solution().isPalindrome(1001) << endl;

}