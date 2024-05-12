#include <stdio.h>
#include <stdbool.h>

bool isSafe(int row, int col, int n, bool board[][n], bool blocks[][n]) {
    // Check for attacks in the same row and column
    for (int i = 0; i < col; i++) {
        if (board[row][i] || blocks[row][i]) {
            return false;
        }
    }

    // Check for attacks in diagonals
    for (int i = 1; i <= row && col - i >= 0; i++) {
        if (board[row - i][col - i] || blocks[row - i][col - i]) {
            return false;
        }
    }
    for (int i = 1; i <= row && col + i < n; i++) {
        if (board[row - i][col + i] || blocks[row - i][col + i]) {
            return false;
        }
    }

    return true;
}

void solveNQueens(int col, int n, bool board[][n], bool blocks[][n], int *solutions) {
    if (col == n) {
        (*solutions)++; // Increment solutions count
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, n, board, blocks)) {
            board[row][col] = true;
            solveNQueens(col + 1, n, board, blocks, solutions);
            board[row][col] = false; // Backtrack
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens (n): ");
    scanf("%d", &n);

    bool board[n][n];
    bool blocks[n][n]; // Additional array to represent blocked positions

    // Initialize boards
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = false;
            blocks[i][j] = false; // Initially no blocks
        }
    }

    // Specify blocked positions (modify this section as needed)
    // For example, block the (2, 3) position:
    blocks[2][3] = true;

    int solutions = 0;
    solveNQueens(0, n, board, blocks, &solutions);

    if (solutions > 0) {
        printf("Number of solutions with blocks: %d\n", solutions);
    } else {
        printf("No solution found with given blocks.\n");
    }

    return 0;
}
