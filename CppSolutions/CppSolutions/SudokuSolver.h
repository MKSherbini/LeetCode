#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sudoku-solver

class SudokuSolver {
public:
    // 654 ms, faster than 5.01% : 144.47 MB, less than 5.22%
    vector<vector<char>> solution(vector<vector<char>> board)
    {
        auto f = [&](this auto f, int i, int j) -> bool {
            if (j == 9) {
                i++;
                j = 0;
            }
            if (i == 9) {
                return 1;
            }

            int ret = 0;
            Printer::print(i, j);
            if (board[i][j] == '.') {
                vector<int> v(9);
                for (size_t k = 0; k < 9; k++) {
                    if (board[k][j] != '.')
                        v[board[k][j] - '1'] = 1;
                    if (board[i][k] != '.')
                        v[board[i][k] - '1'] = 1;
                }

                int boxi = (i / 3) * 3, boxj = (j / 3) * 3;
                for (size_t bi = 0; bi < 3; bi++)
                    for (size_t bj = 0; bj < 3; bj++) {
                        if (board[boxi + bi][boxj + bj] != '.')
                            v[board[boxi + bi][boxj + bj] - '1'] = 1;
                    }

                for (size_t k = 0; k < 9; k++)
                    if (v[k] == 0) {
                        board[i][j] = '1' + k;
                        ret |= f(i, j + 1);
                        if (ret)
                            return 1;
                        board[i][j] = '.';
                    }
            } else {
                ret |= f(i, j + 1);
            }

            return ret;
        };

        f(0, 0);
        return board;
    }
    vector<vector<vector<char>>> output = {
        { { '5', '3', '4', '6', '7', '8', '9', '1', '2' }, { '6', '7', '2', '1', '9', '5', '3', '4', '8' }, { '1', '9', '8', '3', '4', '2', '5', '6', '7' }, { '8', '5', '9', '7', '6', '1', '4', '2', '3' }, { '4', '2', '6', '8', '5', '3', '7', '9', '1' }, { '7', '1', '3', '9', '2', '4', '8', '5', '6' }, { '9', '6', '1', '5', '3', '7', '2', '8', '4' }, { '2', '8', '7', '4', '1', '9', '6', '3', '5' }, { '3', '4', '5', '2', '8', '6', '1', '7', '9' } }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<char>>> input1 = {
        { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, { '.', '.', '.', '.', '8', '.', '.', '7', '9' } }
    };
};