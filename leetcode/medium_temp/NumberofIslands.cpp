/**
 * @file NumberofIslands.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../common.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited {grid.size(), vector<bool>(grid[0].size(), false)};

        queue<pair<int,int>>  searchQueue;
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                if (visited[i][j]) continue;
                if (grid[i][j] == '1') {
                    
                    cout << i << ", " << j << ", " << visited[i][j] << endl;

                    searchQueue.push(pair<int, int>(i, j));
                    numIslands++;
                    while(!searchQueue.empty()) {
                        auto curItem = searchQueue.front();
                        searchQueue.pop();

                        // visited[curItem.first][curItem.second] = true;
                        // cout << searchQueue.size() << ", " << curItem.first << ", " << curItem.second << endl;
                        if (searchQueue.size()>100) exit(-1);
                        addSurroundings(curItem.first, curItem.second, searchQueue, visited, grid);
                    }
                } 
            }
        return numIslands;
    }
    
    void addSurroundings(int row, int col, queue<pair<int,int>>& searchQueue, vector<vector<bool>>& visited, 
        vector<vector<char>>& grid) {
        if (row-1 >= 0 && (!visited[row-1][col]) && grid[row-1][col]=='1') 
        {
            searchQueue.push(pair<int, int>(row-1, col));
            visited[row-1][col] = true;
        }
        if (row+1 < visited.size()  && (!visited[row+1][col]) && grid[row+1][col]=='1') {
            searchQueue.push(pair<int, int>(row+1, col));
            visited[row+1][col] = true;
        }
        if (col-1 >= 0  && (!visited[row][col-1]) && grid[row][col-1]=='1') {
            searchQueue.push(pair<int, int>(row, col-1));
            visited[row][col-1] = true;
        }
        if (col+1 < visited[0].size()  && (!visited[row][col+1]) && grid[row][col+1]=='1') {
            searchQueue.push(pair<int, int>(row, col+1));
            visited[row][col+1] = true;
        }
    }
};

class Solution1 {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                helper(grid, visited, i, j);
                ++res;
            }
        }
        return res;
    }
    void helper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0' || visited[x][y]) return;
        visited[x][y] = true;
        helper(grid, visited, x - 1, y);
        helper(grid, visited, x + 1, y);
        helper(grid, visited, x, y - 1);
        helper(grid, visited, x, y + 1);
    }
};

class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<int> dirX{-1, 0, 1, 0}, dirY{0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;
                ++res;
                queue<int> q{{i * n + j}};
                while (!q.empty()) {
                    int t = q.front(); q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int x = t / n + dirX[k], y = t % n + dirY[k];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y]) continue;
                        visited[x][y] = true;
                        q.push(x * n + y);
                    }
                }
            }
        }
        return res;
    }
};


vector<vector<char>> grid = {
  {'1','1','0','0','0', '1'},
  {'1','1','0','0','0', '1'},
  {'0','0','1','0','0', '1'},
  {'0','0','0','1','1', '0'}
};

decltype(grid) grid1 = {{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};

int main()
{
    print_2d_container(grid1);
    cout << Solution().numIslands(grid1) << endl;
}