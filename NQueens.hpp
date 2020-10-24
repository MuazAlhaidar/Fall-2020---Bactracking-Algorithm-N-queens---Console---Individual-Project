#ifndef NQUEENS_HPP
#define NQUEENS_HPP

#include <cmath>
#include <iostream>
#include <vector>

namespace Bactracking_NQueens {

bool isValid(std::vector<int> &columnPlacements);
void solveNQueens(int n, int currentRow, std::vector<int> &columnPlacements,
                  std::vector<std::vector<int>> &result);
void printResult(const std::vector<std::vector<int>> result,
                 const int N);
std::vector<std::vector<int>> nQueens(int n);

bool isValid(std::vector<int> &columnPlacements) {
    int rowId = columnPlacements.size() - 1;

    for (int rowIndex = 0; rowIndex < rowId; rowIndex++) {
        int difference = std::abs(columnPlacements[rowIndex] - columnPlacements[rowId]);

        if (difference == 0 || difference == (rowId - rowIndex))
            return false;
    }

    return true;
}

void solveNQueens(int n, int currentRow, std::vector<int> &columnPlacements,
                  std::vector<std::vector<int>> &result) {

    if (currentRow == n)
        result.push_back(std::vector<int>(columnPlacements));
    else {

        for (int column = 0; column < n; column++) {

            columnPlacements.push_back(column);

            if (isValid(columnPlacements))
                solveNQueens(n, currentRow + 1, columnPlacements, result);

            columnPlacements.pop_back();
        }
    }
}

std::vector<std::vector<int>> nQueens(int n) {

    std::vector<std::vector<int>> result;
    std::vector<int> columnPlacements;

    solveNQueens(n, 0, columnPlacements, result);

    return result;
}

void printResult(const std::vector<std::vector<int>> result,
                 const int N) {
    for (int i = 0; i < result.size(); i++) {
        std::cout << "Solution " << i + 1 << ": ";

        for (int j = 0; j < N; j++)
            if (j < result[i].size())
                std::cout << result[i][j];

        std::cout << std::endl;
    }
}

} // namespace Bactracking_NQueens
#endif /* NQUEENS_HPP */
