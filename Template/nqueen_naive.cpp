/*
 * nqueen_naive.cpp
 *
 * This file is a simple and naive implementation for N queen
 * puzzle, it will output every valid solutions.
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
    vector<string> board(n, string(n, '.'));
    _solveNQueens(board, 0);
    return res;
  }
  
private:

  void _solveNQueens(vector<string>& board, int row) {
    if (row == board.size()) {
      res.push_back(board);
      return;
    }
    for (int col = 0; col < board.size(); ++col) {
      if (is_valid(board, row, col)) {
	board[row][col] = 'Q';
	_solveNQueens(board, row + 1);
	board[row][col] = '.';
      }
    }
  }
  
  bool is_valid(vector<string>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
      if (board[i][col] == 'Q') return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
      if (board[i][j] == 'Q') return false;
    }
    return true;
  }

  vector<vector<string>>
