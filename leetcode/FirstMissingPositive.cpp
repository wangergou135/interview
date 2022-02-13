/**
 * @file FirstMissingPositive.cpp
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
    int firstMissingPositive(vector<int>& nums) {
        bucket_sort(nums);
        int i;
        for ( i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1) 
                return i+1;
        }
        return i+1;
    }
private:
    void bucket_sort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i+1 && nums[i] <= nums.size() && nums[i]>0  ) {
                if (nums[nums[i]-1] == nums[i]) break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }
    }
};

int main() 
{
    vector<int> nums1 {7,8,9,11,12};
    vector<int> nums2 {3,4,-1,1};

    cout << Solution().firstMissingPositive(nums1) << endl;
    cout << Solution().firstMissingPositive(nums2) << endl;
}