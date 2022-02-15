/**
 * @file SpiralMatrix.cpp
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        vector<int>  result;
        spiralOrder(matrix, 0, result);
        return result;
    }

    void spiralOrder(vector<vector<int>>& matrix, int begin_index, vector<int>& result)
    {
        if (begin_index >= (matrix[0].size()+1)/2 || begin_index >= (matrix.size()+1)/2) return;
        cout << begin_index << endl;
        for (int i = begin_index; i < matrix[0].size() - begin_index; i++ ) {
            result.push_back(matrix[begin_index][i]);
        }
        for (int i = begin_index + 1; i < matrix.size() - begin_index - 1; i++ ) {
            result.push_back(matrix[i][matrix[0].size() - begin_index - 1]);
        }
        if (begin_index + 1 > matrix.size() - begin_index - 1  ) return;

        for (int i = begin_index; i < matrix[0].size() - begin_index; i++ ) {
            result.push_back(matrix[matrix.size()-begin_index - 1][matrix[0].size() - i - 1]);
        }

        if (begin_index == matrix[0].size() - begin_index - 1) return;
        for (int i = begin_index + 1; i < matrix.size() - begin_index - 1; i++ ) {
            result.push_back(matrix[matrix.size() - i - 1][begin_index]);
        }

        spiralOrder(matrix, begin_index+1, result);
    }
};

int main() 
{
    vector<vector<int>> matrix {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<vector<int>> matrix1 {
        {1, 2, 3},
        {5, 6, 7},
    };
    vector<vector<int>> matrix2 {
        {1},
        {5},
        {7}
    };

    print_1d_container(Solution().spiralOrder(matrix));
    print_1d_container(Solution().spiralOrder(matrix1));
    print_1d_container(Solution().spiralOrder(matrix2));
}