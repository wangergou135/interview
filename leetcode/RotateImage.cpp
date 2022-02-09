/**
 * @file RotateImage.cpp
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
    void rotate(vector<vector<int>>& matrix) {
        rotate_(matrix, 0, matrix.size()-1);
    }
private:
    void rotate_(vector<vector<int>>& matrix, int begin_index, int end_index) 
    {
        if (end_index - begin_index < 1) 
            return;
        for (int i = begin_index+1; i <= end_index; i++) {
            // printf("i = %d, begin_index = %d, end_index = %d\n", i, begin_index, end_index);
            swap(matrix[begin_index][i], matrix[end_index][end_index-i+begin_index]);
            swap(matrix[begin_index][i], matrix[end_index-i+begin_index][begin_index]);
            swap(matrix[end_index][end_index-i+begin_index], matrix[i][end_index]);
        }
        rotate_(matrix, begin_index+1, end_index-1);
    }
};

int main()
{
    vector<vector<int>> matrix {{1,2,3}, {4,5,6}, {7,8,9}};
    
    vector<vector<int>> matrix1 {{15,13,2,5}, {14,3,4,1}, {12,6,8,9}, {16,7,10,11}};
    print_2d_container(matrix1);
    Solution().rotate(matrix1) ;
    print_2d_container(matrix1);

}