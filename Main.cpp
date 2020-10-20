#include <cmath>
#include <iostream>
#include <vector>

bool isValid(std::vector<int> &columnPlacements);
std::vector<std::vector<int>> nQueens(int n);
void solveNQueens(int n, int currentRow, std::vector<int> &columnPlacements, std::vector<std::vector<int>> &result);

int main() {

    const int N = 4;

    std::vector<std::vector<int>> result = nQueens(N);

    for (int i = 0; i < result.size(); i++) {
        std::cout << "Solution " << i + 1 << ": ";

        for (int j = 0; j < N; j++)
            if (j < result[i].size())
                std::cout << result[i][j];

        std::cout << std::endl;
    }

    return 0;
}

bool isValid(std::vector<int> &columnPlacements) {
    int rowId = columnPlacements.size() - 1;

    for (int rowIndex = 0; rowIndex < rowId; rowIndex++) {
        int difference = std::abs(columnPlacements[rowIndex] - columnPlacements[rowId]);

        if (difference == 0 || difference == (rowId - rowIndex))
            return false;
    }

    return true;
}

std::vector<std::vector<int>> nQueens(int n) {

    std::vector<std::vector<int>> result;
    std::vector<int> columnPlacements;

    solveNQueens(n, 0, columnPlacements, result);

    return result;
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