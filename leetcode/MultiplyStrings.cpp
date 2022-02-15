/**
 * @file MultiplyStrings.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "common.h"
class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        int m = num1.size(), n = num2.size();
        vector<int> vals(m + n);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1, sum = mul + vals[p2];
                vals[p1] += sum / 10;
                vals[p2] = sum % 10;
            }
        }
        for (int val : vals) {

            if (!res.empty() || val != 0) res.push_back(val + '0');
        }
        return res.empty() ? "0" : res;
    }

    string multiply(string num1, char c) {
        string result(num1.size()+1, '0');
        int carry_ = 0;
        int cur_result = 0;
        for (int i = num1.size()-1; i >= 0; i--) {
            cur_result = (c - '0') * (num1[i] - '0') + carry_;
            cout << cur_result << endl;

            if (cur_result / 10) carry_ = cur_result / 10;
            else carry_ = 0;
            result[i+1] = cur_result % 10 + '0';
        }
        if (carry_) {
            result[0] = '0' + carry_;
            return result;
        } else {
            return result.substr(1, num1.size());
        }
    }
};

int main()
{
    cout << Solution().multiply("15987", "187259") << endl;

        
}