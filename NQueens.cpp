#include "NQueens.hpp"
#include <iostream>

int main() {

    const int N = 4;

    std::vector<std::vector<int>> result;
    result = Bactracking_NQueens::nQueens(N);

    Bactracking_NQueens::printResult(result, N);

    return 0;
}
