/**
 * @file LongestPalindromicSubstring.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * Given a string s, return the longest palindromic substring in s.
 *
    1 <= s.length <= 1000
    s consist of only digits and English letters.
 */

#include "common.h"

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        } 

        int max_length = 1;
        int max_begin = 0;

        int cur_index = 1;
        int begin_index = 0;

        auto func = [&]() {
            int cur_index_tmp = cur_index;
            int cur_length = 0;

            // make sure begin_index >= 0 is before &&
            while (begin_index >= 0 && s[begin_index] == s[cur_index_tmp]) { 
                cur_length = cur_index_tmp - begin_index + 1;

                begin_index--;
                cur_index_tmp++;
            }

            if (cur_length > max_length) {
                max_length = cur_length;
                max_begin = begin_index + 1;
            }
        };
        while (cur_index < s.size()) {

            if (s[cur_index] == s[cur_index-1]) {
                begin_index = cur_index - 1;
                func();
            }  

            if (cur_index >=2 && s[cur_index] == s[cur_index-2]) {
                begin_index = cur_index - 2;
                func();
            } 

            cur_index++;
        }
        
        return string({s.begin() + max_begin, s.begin() + max_begin + max_length});
    }

};


int main() 
{
    cout << Solution().longestPalindrome("cbabdabcbaee") << endl;
    cout << Solution().longestPalindrome("ab") << endl;
    cout << Solution().longestPalindrome("bb") << endl;
    cout << Solution().longestPalindrome("ccc") << endl;
    cout << Solution().longestPalindrome("aaaa") << endl;
    cout << Solution().longestPalindrome("babad") << endl;


}