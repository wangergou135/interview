/**
 * @file MedianofTwoSortedArrays.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "common.h"
// still can not deal with some corner case
class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m == 0  && n == 0) return 0;
        if (m == 0 ) {
            
            int index = (n-1)/2 + 1 > n - 1 ? n - 1  : (n-1)/2 + 1;
            if (n % 2 == 0) return (nums2[(n-1)/2] + nums2[index])*0.5;
            else return nums2[(n-1)/2];
        } 
        if (n == 0 ) {
            
            int index = (m-1)/2 + 1 > m - 1 ? m - 1  : (m-1)/2 + 1;

            if (m % 2 == 0) return (nums1[(m-1)/2] + nums1[index])*0.5;
            else return nums1[(m-1)/2];
        } 

        int curIgnored = 0;
        int left1 = 0, left2 = 0;
        int right1 = m - 1, right2 = n - 1;
        int mid1 = 0, mid2 = 0;
        int totalIgnore = (m + n)/2;

        while(curIgnored < totalIgnore) {
            mid1 = (left1 + right1) / 2;            
            mid2 = (left2 + right2) / 2;
            if (mid1 + mid2 == 0) {
                break;
            }

            if (nums1[right1] > nums2[right2]) {

                curIgnored += right1 - mid1;
                right1 = mid1 ;
            } else if (nums1[right1] < nums2[right2]) {

                curIgnored += right2 - mid2 ;
                right2 = mid2 ;
            } else {
                curIgnored += right2 - mid2 + right1 - mid1;
                right2 = mid2 ;
                right1 = mid1 ;
            }
            // cout << "curIgnored:" << curIgnored << endl;
            // cout << mid1 << " mid:" << mid2 << endl;
            // cout << left1 << " nums1:" << right1 << endl;
            // cout << left2 << " nums2:" << right2 << endl;
        }

        cout << curIgnored<< " totalIgnore============:" << totalIgnore << endl;
        cout << right1 << " right1:" << right2 << ", " << curIgnored << endl;

        int median1, median2;

        while (curIgnored < totalIgnore) {
            if (nums1[right1] > nums2[right2]) { // ignore right1

                right1--;
                curIgnored++;
            } else if (nums1[right1] < nums2[right2]) {
                // if (right1 < m - 1) right1++;
                // else right2++;
                right2--;
                curIgnored++;
            } else {
                curIgnored++;
                right2 --;
                // if (right1 < m - 1)
                //     return nums1[right1 + 1];
                // else if (right2 < n - 1)
                //     return nums2[right2+1];
                // else 
                //     return nums1[right1];
            }
        // cout << right1 << " ++++:" << right2 << ", " << totalIgnore << endl;

        }
        cout << right1 << " right1:" << right2 << ", " << totalIgnore << endl;
        if (right1<0 && right2<0) {
            return (nums1[0] + nums2[0] ) * 0.5;
        } else if (right1<0) {
            if ((m+n)%2) {
                return nums1[right1+1] < nums2[right2] ? nums1[right1+1] : nums2[right2];
            } else {
                return (nums1[right1+1] + nums2[right2]) * 0.5;
            }
        } else if (right2<0) {
            if ((m+n)%2) {
                return nums1[right1] < nums2[right2+1] ? nums1[right1] : nums2[right2+1];
            } else {
                return (nums1[right1] + nums2[right2+1]) * 0.5;
                
            }
        } else {
            int index1 = right1 + 1;
            int index2 = right2 + 1;
            if ((m+n)%2) {
                if (index2 <= n - 1 && index1 <= m-1)
                    return nums1[index1] < nums2[index2] ? nums1[index1] : nums2[index2];
                else if (index2 > n - 1) {
                    return nums1[index1] < nums2[right2] ? nums1[index1] : nums2[right2];
                } else if (index1 > m - 1) {
                    return nums1[right1] < nums2[index2] ? nums1[right1] : nums2[index2];

                }
            } else {
                if (index1 > m - 1) {
                    median2 =  nums2[index2];
                }
                else if (index2 > n - 1) {
                    median2 =  nums1[index1];
                } else {
                    median2 = nums1[index1] < nums2[index2] ? nums1[index1] : nums2[index2];
                }
                median1 = nums1[right1] > nums2[right2] ? nums1[right1] : nums2[right2];
                // cout << "median1:" << median1 << endl;
                // cout << "median2:" << median2 << endl;
                return (median1 + median2) * 0.5;  
            }
            // cout << right1 << " right1:" << right2 << endl;
            // cout << right1 << " right1:" << right2 << endl;
            // cout << left1 << " left1:" << left2 << endl;
           
    
        }
        return 0;

    }
};

int main()
{
    vector<int> a = { 1, 3, 5, 7 };
    vector<int> b = { 2, 4, 6, 8 };
    vector<int> c = { 2, 4, 6, 8, 9 };
    // cout << Solution().findMedianSortedArrays(a, b) << endl;
    // cout << Solution().findMedianSortedArrays(a, c) << endl;
    // cout << Solution().findMedianSortedArrays({1, 3}, {2}) << endl;
    // cout << Solution().findMedianSortedArrays({0, 1}, {0, 1}) << endl;
    // cout << Solution().findMedianSortedArrays({1, 3}, {2, 7}) << endl;
    // cout << Solution().findMedianSortedArrays({1, 2}, {3, 4}) << endl;
    // cout << Solution().findMedianSortedArrays({1, 2}, {1, 1}) << endl;
    // cout << Solution().findMedianSortedArrays({1}, {}) << endl;
    // cout << Solution().findMedianSortedArrays({0, 0}, {0}) << endl;
    // cout << Solution().findMedianSortedArrays({2, 2, 4, 4}, {2, 2, 4, 4}) << endl;
    // cout << Solution().findMedianSortedArrays({1}, {1}) << endl;
    cout << Solution().findMedianSortedArrays({1, 2, 3}, {1, 2}) << endl;
    cout << Solution().findMedianSortedArrays({1}, {2, 3}) << endl;
}