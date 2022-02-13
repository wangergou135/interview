/**
 * @file Pow.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "common.h"
class Solution {
public:
    // failed when n == INT_MIN
    double myPow(double x, int n) {
        if (n == 0) return 1;
        bool isNegative = false;
        if (n<0) {
            isNegative = true;
            n = -n;
        }
        double half =  myPow(x, n/2);
        double result = 0;
        if (n%2) result = half*half*x;
        else result = half*half;
        
        if (isNegative) return 1/result;
        else return result;
    }

    double myPow_(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};

int main()
{
    cout << Solution().myPow(2.0d, 10) << endl;
    cout << Solution().myPow(2.0d, -10) << endl;
    cout << Solution().myPow(3.0d, 0) << endl;
}