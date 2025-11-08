#include <iostream>
#include <vector>
using namespace std;

// Function to print the chessboard
void printBoard(const vector<vector<int>>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int n = board.size();
    
    // Check this column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }
    
    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >=0 && j >=0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    
    // Check upper right diagonal
    for (int i = row -1, j = col + 1; i >=0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    
    return true;
}

// Backtracking function to place queens
bool placeQueens(vector<vector<int>>& board, int row) {
    int n = board.size();
    if (row == n) return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (placeQueens(board, row + 1)) {
                return true;
            }
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    int n, firstRow, firstCol;
    cout << "Enter board size (n): ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    cout << "Enter first queen position (row and column, 0-indexed): ";
    cin >> firstRow >> firstCol;
    if (firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n) {
        cout << "Invalid first queen position." << endl;
        return 1;
    }
    board[firstRow][firstCol] = 1;

    // Start backtracking from firstRow + 1, placing remaining queens
    if (placeQueens(board, 0)) {
        board[firstRow][firstCol] = 1; // Keep the first queen placed
        cout << "Final N-Queens board:\n";
        printBoard(board);
    } else {
        cout << "Solution doesn't exist with first queen fixed at (" << firstRow << ", " << firstCol << ").\n";
    }

    return 0;
}
