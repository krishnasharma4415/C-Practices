#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLAYERS 2

// Define the structure for a player
typedef struct Player
{
    char username[50];
    int score;
} Player;

// Define the structure for game statistics
typedef struct GameStats
{
    int gamesPlayed;
    int ties;
    int playerWins[MAX_PLAYERS];
} GameStats;

// Define the structure for a cell in the Tic-Tac-Toe board
typedef struct Cell
{
    char value;
} Cell;

// Define the structure for the Tic-Tac-Toe game
typedef struct TicTacToe
{
    Cell board[3][3];
    Player players[MAX_PLAYERS];
    int currentPlayerIndex;
    GameStats stats;
} TicTacToe;

// Function to display the Tic-Tac-Toe board
void displayBoard(TicTacToe *game)
{
    printf("\nTic-Tac-Toe Board:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", game->board[i][j].value);
        }
        printf("\n");
    }
}

// Function to initialize player profiles
void initializePlayers(TicTacToe *game)
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        printf("Enter username for Player %d: ", i + 1);
        scanf("%s", game->players[i].username);
        game->players[i].score = 0;
    }
}

// Function to switch to the next player
void switchPlayer(TicTacToe *game)
{
    game->currentPlayerIndex = (game->currentPlayerIndex + 1) % MAX_PLAYERS;
}

// Function to update player scores
void updateScores(TicTacToe *game, int winnerIndex)
{
    game->players[winnerIndex].score++;
    game->stats.playerWins[winnerIndex]++;
}

// Function to update game statistics
void updateStatistics(TicTacToe *game, bool isTie)
{
    game->stats.gamesPlayed++;
    if (isTie)
    {
        game->stats.ties++;
    }
}

// Function to check if a player has won
bool checkWin(TicTacToe *game, char playerSymbol)
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((game->board[i][0].value == playerSymbol && game->board[i][1].value == playerSymbol && game->board[i][2].value == playerSymbol) ||
            (game->board[0][i].value == playerSymbol && game->board[1][i].value == playerSymbol && game->board[2][i].value == playerSymbol))
        {
            return true;
        }
    }

    // Check diagonals
    if ((game->board[0][0].value == playerSymbol && game->board[1][1].value == playerSymbol && game->board[2][2].value == playerSymbol) ||
        (game->board[0][2].value == playerSymbol && game->board[1][1].value == playerSymbol && game->board[2][0].value == playerSymbol))
    {
        return true;
    }

    return false;
}

// Function to check if the board is full (a tie)
bool checkTie(TicTacToe *game)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game->board[i][j].value == ' ')
            {
                return false; // Empty cell found, the game is not a tie
            }
        }
    }
    return true; // All cells are filled, the game is a tie
}

// Function to perform a player's move
void makeMove(TicTacToe *game)
{
    int row, col;
    printf("Enter row and column (1-3) for %s (X): ", game->players[game->currentPlayerIndex].username);
    scanf("%d %d", &row, &col);

    // Adjust indices to match array indexing (1-based to 0-based)
    row--;
    col--;

    // Check if the cell is empty
    if (game->board[row][col].value == ' ')
    {
        game->board[row][col].value = (game->currentPlayerIndex == 0) ? 'X' : 'O';
        switchPlayer(game);
    }
    else
    {
        printf("Cell already occupied. Try again.\n");
    }
}

// Function to reset the Tic-Tac-Toe board
void resetBoard(TicTacToe *game)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            game->board[i][j].value = ' ';
        }
    }
}

// Function to display player scores
void displayScores(TicTacToe *game)
{
    printf("\nPlayer Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        printf("%s: %d\n", game->players[i].username, game->players[i].score);
    }
}

// Function to display game statistics
void displayStatistics(TicTacToe *game)
{
    printf("\nGame Statistics:\n");
    printf("Total Games Played: %d\n", game->stats.gamesPlayed);
    printf("Ties: %d\n", game->stats.ties);
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        printf("%s Wins: %d\n", game->players[i].username, game->stats.playerWins[i]);
    }
}

int main()
{
    TicTacToe game;
    game.currentPlayerIndex = 0;
    game.stats.gamesPlayed = 0;
    game.stats.ties = 0;
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        game.stats.playerWins[i] = 0;
    }

    // Initialize player profiles
    initializePlayers(&game);

    int choice;
    do
    {
        displayBoard(&game);
        makeMove(&game);

        if (checkWin(&game, (game.currentPlayerIndex == 0) ? 'X' : 'O'))
        {
            printf("%s wins!\n", game.players[game.currentPlayerIndex].username);
            updateScores(&game, game.currentPlayerIndex);
            updateStatistics(&game, false);
            displayScores(&game);
            displayStatistics(&game);
            resetBoard(&game);
        }
        else if (checkTie(&game))
        {
            printf("It's a tie!\n");
            updateStatistics(&game, true);
            displayScores(&game);
            displayStatistics(&game);
            resetBoard(&game);
        }

        printf("Enter 0 to exit or any other number to continue: ");
        scanf("%d", &choice);

    } while (choice != 0);

    return 0;
}
