/**
 * @file LetterCombinationsofaPhoneNumber.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "common.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.size() == 0) 
            return {};
            
        vector<string> result;
        string letters(digits.size(), '\0');
        letterCombinations(digits, 0, digits.size()-1, letters, result);

        print_1d_container(result);
        return result;
    }

    void letterCombinations(string digits, int start, int end, string letters, vector<string>& result)
    {
        if (digits[start] == '1') return;
        if (start > end) {

            result.push_back(letters);
            return;
        }
        cout <<start <<  "       digits[start] - '0':" << (digits[start] - '0') << endl;

        for (auto c : numberToLetter[digits[start] - '0']) {
            cout << "start:" << start << endl;
            letters[start] = c;
            letterCombinations(digits, start+1, end, letters, result);
            letters[start] = '\0';
        }
    }
private:
    vector<string> numberToLetter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

};

int main()
{
    Solution().letterCombinations("23");
    Solution().letterCombinations("");
}