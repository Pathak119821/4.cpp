#include <iostream>
using namespace std;

// Function to display the game board
void displayBoard(char board[3][3]) {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--\n";
    }
}

// Function to check if the current player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to update the game board with the player's move
bool makeMove(char board[3][3], int row, int col, char player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false;
    }
    board[row][col] = player;
    return true;
}

// Function to switch players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    cout << "Tic-Tac-Toe Game\n";
    displayBoard(board);

    while (!gameWon && !gameDraw) {
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column: 1-3): ";
        cin >> row >> col;
        row--; col--; // Adjust for 0-indexing

        if (makeMove(board, row, col, currentPlayer)) {
            displayBoard(board);
            gameWon = checkWin(board, currentPlayer);
            if (gameWon) {
                cout << "Player " << currentPlayer << " wins!\n";
            } else {
                gameDraw = checkDraw(board);
                if (gameDraw) {
                    cout << "The game is a draw!\n";
                } else {
                    currentPlayer = switchPlayer(currentPlayer);
                }
            }
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    } else {
        cout << "Thanks for playing!\n";
    }

    return 0;
}
