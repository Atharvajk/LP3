#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check all positions in the same column
    for (int i = 0; i < n; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
     // Check the lower-left diagonal (bottom-left diagonal)
    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the lower-right diagonal (bottom-right diagonal)
    for (int i = row, j = col; i < n && j < n; ++i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int n, int firstRow, int firstCol) {
    if (row == n)
        return true;

    // If this row already has the first queen, skip to the next row
    if (row == firstRow) 
        return solveNQueens(board, row + 1, n, firstRow, firstCol);

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;  // Place queen
            if (solveNQueens(board, row + 1, n, firstRow, firstCol))
                return true;
            board[row][col] = 0;  // Backtrack
        }
    }
    return false;
}

void placeFirstQueenAndSolve(int n, int firstRow, int firstCol) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    board[firstRow][firstCol] = 1;  // Place the first queen at the specified location

    // Start solving from row 0 while skipping the pre-placed queen's position
    if (solveNQueens(board, 0, n, firstRow, firstCol)) {
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    int n = 4;   // You can change n for different board sizes
    int firstRow = 2, firstCol = 3;  // Coordinates to place the first queen

    placeFirstQueenAndSolve(n, firstRow, firstCol);
    return 0;
}
