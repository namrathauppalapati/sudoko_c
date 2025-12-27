#include <stdio.h>

int grid[9][9] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

/* Display Sudoku Grid */
void display() {
    int i, j;
    printf("\nSudoku Board:\n");
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

/* Check if number is valid */
int isValid(int row, int col, int num) {
    int i, j;

    // Check row and column
    for(i = 0; i < 9; i++) {
        if(grid[row][i] == num || grid[i][col] == num)
            return 0;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(grid[startRow + i][startCol + j] == num)
                return 0;
        }
    }
    return 1;
}

/* Check if Sudoku is complete */
int isComplete() {
    int i, j;
    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(grid[i][j] == 0)
                return 0;
    return 1;
}

int main() {
    int row, col, num;

    printf("=== Sudoku Game in C ===\n");
    printf("Enter row column number (1-9)\n");
    printf("Enter 0 0 0 to exit\n");

    while(1) {
        display();

        printf("\nEnter row col num: ");
        scanf("%d %d %d", &row, &col, &num);

        if(row == 0 && col == 0 && num == 0) {
            printf("Game Exited.\n");
            break;
        }

        row--; col--;

        if(row < 0 || row > 8 || col < 0 || col > 8 || num < 1 || num > 9) {
            printf("Invalid input!\n");
            continue;
        }

        if(grid[row][col] != 0) {
            printf("Cell already filled!\n");
            continue;
        }

        if(isValid(row, col, num)) {
            grid[row][col] = num;
        } else {
            printf("Invalid move!\n");
        }

        if(isComplete()) {
            display();
            printf("\n?? Congratulations! You solved the Sudoku ??\n");
            break;
        }
    }

    return 0;
}

