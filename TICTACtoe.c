#include <stdio.h>

// Function to display the game board
void display_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if there is a winner
char check_winner(char board[3][3]) {
    int i;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }
    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    // If no winner
    return ' ';
}

// Function to check if the board is full
int board_full(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; // Board is not full
        }
    }
    return 1; // Board is full
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col, player = 1;
    char mark;

    display_board(board);

    // Main game loop
    do {
        // Determine current player's mark
        mark = (player == 1) ? 'X' : 'O';

        // Input move
        printf("Player %d, enter row (0-2) and column (0-2) to place %c: ", player, mark);
        scanf("%d %d", &row, &col);

        // Check if the chosen cell is valid and empty
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = mark;
            display_board(board);

            // Check for a winner
            char winner = check_winner(board);
            if (winner != ' ') {
                printf("Player %d wins!\n", player);
                break;
            }

            // Check for a draw
            if (board_full(board)) {
                printf("The game ends in a draw.\n");
                break;
            }

            // Switch to the other player
            player = (player == 1) ? 2 : 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    } while (1);

    return 0;
}
