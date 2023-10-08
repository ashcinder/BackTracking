#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
private:

    bool backtracking(vector<vector<char>>& board) {

        for (int i = 0;i < board.size();i++) {
            for (int j = 0;j < board[0].size();j++) {
                if (board[i][j] == '.') {
                    for (char k = '1';k <= '9';k++) {
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k;
                            if (backtracking(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;//当遍历的字符1到字符9以后，没有返回true，说明不匹配
                }
            }
        }
    }

    bool isValid(int row, int col, char k, vector < vector<char>>& board) {
        for (int i = 0;i < 9;i++) {//行以及列的判断
            if (board[i][col] == k||board[row][i]==k) {
                return false;
            }
        }

        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;//九宫格中左上角的位置

        for (int i = startrow;i < startrow + 3;i++) {
            for (int j = startcol;j < startcol + 3;j++) {
                if (board[i][j] == k) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};


class Solution {
private:
    vector<vector<vector<char>>> result;
    vector <vector<char>> path;


    bool isValid(int row, int col, char k, vector < vector<char>>& board) {
        for (int i = 0;i < 9;i++) {//行以及列的判断
            if (board[i][col] == k || board[row][i] == k) {
                return false;
            }
        }

        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;//九宫格中左上角的位置

        for (int i = startrow;i < startrow + 3;i++) {
            for (int j = startcol;j < startcol + 3;j++) {
                if (board[i][j] == k) {
                    return false;
                }
            }
        }

        return true;
    }

    void backtracking(vector<vector<char>>& board) {

        for (int i = 0;i < board.size();i++) {
            for (int j = 0;j < board[0].size();j++) {
                if (board[i][j] == '.') {
                    for (char k = '1';k <= '9';k++) {
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k;
                            backtracking(board);
                            board[i][j] = '.';
                        }
                        else {
                            return;
                        }
                    }
                }
            }
        }

        result.push_back(board);
    }
public:
    vector<vector<vector<char>>> solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
        return result;
    }
};