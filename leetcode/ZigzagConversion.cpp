
/**
 * @file ZigzagConversion.cpp
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
    string convert(string s, int numRows) {
        int numPerV = (numRows << 1) - 2;
        if (numPerV == 0) numPerV = 1;
        
        int curSIndex = 0;  // s
        int curRNum = 0;  // result
        string result(s.size(), '\0');
        for (int i = 0; i < numRows ; i++) {
            curSIndex = 0;
            while (curSIndex * numPerV + i< s.size()) {
                result[curRNum++] = s[i + curSIndex * numPerV];
                curSIndex++;

                if (i > 0 && i < numRows-1 && curSIndex*numPerV-i < s.size()) {
                    result[curRNum++] = s[curSIndex * numPerV - i];
                }

            }
            
            
        }
        return result;
    }
};

int main()
{
    cout << Solution().convert("PAYPALISHIRING", 3) << endl;
    cout << Solution().convert("PAYPALISHIRING", 4) << endl;
    cout << Solution().convert("A", 1) << endl;
}