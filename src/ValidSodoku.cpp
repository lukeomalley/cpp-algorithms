#include <iostream>
#include <unordered_set>
#include <vector>

/**
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 *
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 */
class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    // Store a set for each row, col, and 9x9 cell
    std::vector<std::unordered_set<int>> rows(9), cols(9), blocks(9);
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        auto cell = board[i][j];

        if (cell == '.') {
          continue;
        }

        int curr = board[i][j] - '0';

        std::cout << curr << std::endl;

        if (rows[i].count(curr) || cols[j].count(curr) ||
            blocks[(i / 3) * 3 + j / 3].count(curr)) {
          return false;
        }

        rows[i].insert(curr);
        cols[j].insert(curr);
        blocks[(i / 3) * 3 + j / 3].insert(curr);
      }
    }

    return true;
  }
};

int main() { return 0; }
