/*
 * nqueen_bit_operator.cpp
 *
 * This file is a bit version implementation for N queen
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
    upper_lim = (1 << n) - 1;
    vector<string> cur(n, string(n, '.'));
    _solveNQueens(cur, 0, 0, 0, 0);
    return res;
  }

private:
  void _solveNQueens(vector<string>& cur, int bit_r, int bit_ld, int bit_rd, int row_idx) {
    if (row_idx == cur.size()) {
      res.push_back(cur);
    } else {
      int pos = upper_lim & (~(bit_r | bit_ld | bit_rd ));
      while (pos)
	{
	  int p = pos & (~pos + 1);
	  pos = pos - p;
	  _set_queen(cur, index, p, 'Q');
	  _solveNQueens(cur, bit_r | p, (bit_ld | p) << 1, (bit_rd | p) >> 1,  row_idx+1);
	  _set_queen(cur, index, p, '.');
	}
    }
  }

  void _set_queen(vector<string>& board, int row, int state, char c) {
    int col = 0;
    while (!(state & 1)) {
      state >>= 1;
      col++;
    }
    board[row][col] = c;
  }

  vector<vector<string>> res;
  int upper_lim;
};
