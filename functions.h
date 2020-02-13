// Header file for functions

void greetAndInstruct();
void displayBoard(char board[]);
// void isFull(char board[]);
bool checkIfLegal (int cellNbre, char board[]);
//bool checkHorizontal (char board[], char whoWon[]);
//bool checkVertical (char board[], char whoWon[]);
//bool checkDiagonal (char board[], char whoWon[]);
bool checkWinner(char board[]);
void computerMove(char board[]);