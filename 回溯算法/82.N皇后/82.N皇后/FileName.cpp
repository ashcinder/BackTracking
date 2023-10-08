#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking( int row, int n) {
        if (row == n) {
            result.push_back(path);
            return;
        }

        for (int col = 0;col < n;col++) {
            if (isValid(row, col, n)) {
                path[row][col] = 'Q';
                backtracking(row + 1, n);
                path[row][col] = '.';
            }
            else {
                continue;
            }
        }
    }

    bool isValid(int row, int col, int n) {
        if (path[row][col] == 'Q') {
            return false;
        }
        
        int Direction_X[8] = {1,0,-1,0,1,1,-1,-1};
        int Direction_Y[8] = {0,1,0,-1,-1,1,1,-1};

        for (int i = 0;i < 8;i++) {
            int next_x = col + Direction_X[i];
            int next_y = row + Direction_Y[i];
            while(InRange(next_y, next_x, n)) {
                if (path[next_y][next_x] != 'Q') {
                    next_x += Direction_X[i];
                    next_y += Direction_Y[i];
                }
                else {
                    return false;
                }


            }
        }

        return true;
    }

    bool InRange(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n, string(n, '.'));//≥ı ºªØ∆Â≈ÃŒ™kong
        backtracking(0, n);
        return result;
    }
};