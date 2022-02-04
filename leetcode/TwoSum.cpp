/**
 * @file TwoSum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * Given an array of integers nums and an integer target, return indices of the two numbers 
 * such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * 
     2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
 */

#include "common.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        
        while ( start < end ) {
            if (nums[start] + nums[end] > target) end--;
            else if (nums[start] + nums[end] < target) start++;
            else return {start, end};
        }

        return {0, 0};
    }

    vector<int> twoSum_(vector<int>& nums, int target) {
        vector<int> result = {0, 0};
        map<int, int>  dict {};

        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(target - nums[i]) != dict.end()) {
                return {i, dict[target - nums[i]]};
            } else {
                dict[nums[i]] = i;
            }
        }
            
        return result;
    }
};

int main() 
{
    // vector<int>::value_type a = 1;
    vector<int> nums = {2, 7, 11, 15};

    print_1d_container(Solution().twoSum(nums, 9));

    nums = {2, 3, 3, 4};

    print_1d_container(Solution().twoSum_(nums, 6));
    return 1;
}