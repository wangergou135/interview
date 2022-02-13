/**
 * @file GroupAnagrams.cpp
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>  groups;
        string temp;
        for ( auto s : strs) {
            temp = s;
            sort(temp.begin(), temp.end());
            if (groups.find(temp) == groups.end()) {
                groups[temp] = {};
            } 
                
            groups[temp].push_back(s);

        }
        
        vector<vector<string>> result;
        
        for (auto item : groups) {
            result.push_back(item.second);
        }
        
        return result;
    }
};

int main() 
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    print_2d_container(Solution().groupAnagrams(strs));
}