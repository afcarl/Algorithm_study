/*
 * nqueen_opt_space.cpp
 *
 * This file is a version implementation for N queen
 * puzzle which take O(n) space instead of O(n^2) in
 * previosu naive version. It will output every valid 
 * solutions.
 *
 * Author: Qi Haozhi
 * Copyright (c) 2015 Qi Haozhi
 *
 * You can star the project via:
 * https://github.com/Oh233/Algorithm_study
 */

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> state(n, -1);
        _solveNQueens(state, 0);
        return res;
    }
    
private:

    void _solveNQueens(vector<int>& state, int row) {
        int n = state.size();
        if (row == n) {
            vector<string> tmp_res(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                tmp_res[i][state[i]] = 'Q';
            }
            res.push_back(tmp_res);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (is_valid(state, row, col)) {
                state[row] = col;
                _solveNQueens(state, row + 1);
                state[row] = -1;
            }
        }
    }
    
    bool is_valid(vector<int>& state, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (state[i] == col || abs(row - i) == abs(col - state[i])) return false;
        }
        return true;
    }

    vector<vector<string>> res;
};