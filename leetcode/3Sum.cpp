/**
 * @file 3Sum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "common.h"

class Solution {
public:
    // o(n^3)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;

        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;

        int sum_ = 0;
        for (int i = 0; i <= right - 2; i++) {
            for (int j = i + 1; j <= right - 1; j++) {
                for (int k = j+1; k <= right; k++) {
                    sum_ = nums[i] + nums[j] + nums[k];
                    if (sum_ == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                }
                
            }
            
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }

    // their solution o(n^2)
    vector<vector<int>> threeSum_(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;

        sort(nums.begin(), nums.end());
        const int target = 0;

        auto last = nums.end();

        for (auto i = nums.begin(); i < last-2; ++i) {
            auto j = i+1;
            if (i > nums.begin() && *i == *(i-1)) continue;
            auto k = last-1;
            while (j < k) {
                if (*i + *j + *k < target) {
                    ++j;
                    while(*j == *(j - 1) && j < k) ++j;
                } else if (*i + *j + *k > target) {
                    --k;
                    while(*k == *(k + 1) && j < k) --k;
                } else {
                    result.push_back({ *i, *j, *k });
                    ++j;
                    --k;
                    while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j; //{==j; --k;}
                } 
            } 
        }
        return result;
    }
};

int main() 
{
    // vector<int>&& nums {-1,0,1,2,-1,-4};
    vector<int>&& nums {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    print_2d_container(Solution().threeSum(nums));
    // print_2d_container(Solution().threeSum_(nums));
}