#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main() {

    // Game start: Empty board
    char board[27];
    for (int i = 0; i < 27; i++) {board[i] = ' ';}

    // Greet User
    greetAndInstruct();

    // Display starting game board
    displayBoard(board);

    // Main game loop
    while (true) {

        // Take user desired move, ensure it's a legal move
        while(true) {

            cout << " " << endl;
            cout << "Please type in your input: " << endl;

            // string to store user desired move
            string userInput;
            cin >> userInput;
            int usersMove = stoi(userInput) - 1;

            // Check whether the user desired move is legal, if not keep looping until user enters a legal move
            if (checkIfLegal(usersMove, board)) {
                board[usersMove] = 'X';
                break;
            }
        }

        cout << " " << endl;

        // Show user the state of the board after his/her move
        displayBoard(board);

        cout << " " << endl;

        // Check for winner, if any
        if (checkWinner(board)) {
            break;
        }

        cout << " " << endl;

        // Computer's move
        computerMove(board);

        // Show user the state of the board after the computer's move
        displayBoard(board);

        cout << " " << endl;

        // Check for winner, if any
        if (checkWinner(board)) {
            break;
        }
        cout << " " << endl;
    }

    return 0;
}