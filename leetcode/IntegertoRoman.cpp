/**
 * @file IntegertoRoman.cpp
 * @author your name you@domain.com
 * @brief 
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright c 2022
 * 
 */
#include "common.h"

class Solution {
public:
    string intToRoman(int num)  {
        string result;
        while (num) {
            if (num >= 1000) {
                result += "M";
                num -= 1000;
            } else if (num >= 900) {
                result += "CM";
                num -= 900;
            } else if (num >= 500) {
                result += "D";
                num -= 500;
            } else if (num >= 400) {
                result += "CD";
                num -= 400;
            } else if (num >= 100) {
                result += "C";
                num -= 100;
            } else if (num >= 90) {
                result += "XC";
                num -= 90;
            } else if (num >= 50) {
                result += "L";
                num -= 50;
            } else if (num >= 40) {
                result += "XL";
                num -= 40;
            } else if (num >= 10) {
                result += "X";
                num -= 10;
            } else if (num >= 9) {
                result += "IX";
                num -= 9;
            } else if (num >= 5) {
                result += "V";
                num -= 5;
            } else if (num >= 4) {
                result += "IV";
                num -= 4;
            } else { 
                result += "I";
                num -= 1;
            }
        }
        return result;
    }

    // better solution
    string intToRoman_(int num)  {

        const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string roman;
        for (size_t i = 0; num > 0; ++i) {
            int count = num / radix[i];
            num %= radix[i];
            
            for (; count > 0; --count) roman += symbol[i];
        }
        return roman;
    }
};

int main()
{
    cout << Solution().intToRoman(4) << endl;;
    cout << Solution().intToRoman(14) << endl;
    cout << Solution().intToRoman(1994) << endl;
}