// Student name: Eric Leung
// Student ID: 260720788
// COMP322 Assignment 1

#include <iostream>
#include <string.h>
#include "functions.h"
using namespace std;

// Q.1
void greetAndInstruct() {
    
    // Print welcome message
    cout << "=========== Hello and welcome to the A.I. Tic-Tac-Toe game: HUMAN V.S. COMPUTER =========== " << endl;
    
    cout << "" << endl;

    // Print instructions
    cout << "The board is numbered from 1 to 27 as per the following:" << endl;

    cout << "" << endl;

    // Print numnbered boards 
    cout << "1 | 2 | 3             10 | 11 | 12            19 | 20 | 21 " << endl;
    cout << "----------            ------------            ------------ " << endl;
    cout << "4 | 5 | 6             13 | 14 | 15            22 | 23 | 24 " << endl;
    cout << "----------            ------------            ------------ " << endl;
    cout << "7 | 8 | 9             16 | 17 | 18            25 | 26 | 27 " << endl;

    cout << "" << endl;
    cout << "Player starts first. Simply input the number of the cell you want to occupy. Player’s move is marked with X. Computer’s move is marked with O." << endl;
    cout << "" << endl;
    cout << "Start? (y/n):" << endl;

    char userInput;

    // Loop to ensure user enters only 'y' or 'n'
    while (true) {
        cin >> userInput;
        if (userInput == 'n') {
            break;
            return;
        }
        else if (userInput == 'y') {
            // game start
        }
        else {
            cout << "Please enter either 'y' or 'n': " << endl;
            continue;
        }
    }
}

// Q.2
void displayBoard(char board[]) {
    
    // Print current state of game board:
    cout << "Game board as of now: " << endl;
    cout << "" << endl;

    // First row
    cout << board[0] << " | " <<  board[1] << " | " << board[2];
    cout << "               " << board[9] << " | " << board[10] << " | " << board[11];
    cout << "               " << board[18] << " | " << board[19] << " | " << board[20] << endl;

    cout << "----------            ------------             ----------- " << endl;

    // Second row
    cout << board[3] << " | " <<  board[4] << " | " << board[5];
    cout << "               " << board[12] << " | " << board[13] << " | " << board[14];
    cout << "               " << board[21] << " | " << board[22] << " | " << board[23] << endl;    

    cout << "----------            ------------             ----------- " << endl;

    // Third row
    cout << board[6] << " | " <<  board[7] << " | " << board[8];
    cout << "               " << board[15] << " | " << board[16] << " | " << board[17];
    cout << "               " << board[24] << " | " << board[25] << " | " << board[26] << endl;
}   

// Q.3 
// After every move we need to check if the move is legal and 
// if so we have to check whether we have a winner
bool checkLegal(int cellNbre, char board[]) {
    // Check if user inputs an illegal cell number for the move (out of bound) or the cell is already occupied
    
    if (cellNbre <= 0 && cellNbre <= 27) {  // This means the user desired cell number is in the range of possible cells
        if (board[cellNbre] == ' ') {
            return true;
        }
        else {
            cout << "WARNING: This cell is already occupied, please pick another cell." << endl;
            return false;
        }
    }
    cout << "WARNING: Please input a cell number between 0 and 27." << endl;
    return false;
}

// Auxilary function for checkWinner (Horizontal cases)
bool checkHorzitonalW(char board[]) {
    
    // Left to right on the same layer
    for (int i = 0; i < 27; i += 3){

        // We check the both two cells to the right of i on the same layer
        if ((board[i] == board[i + 1]) && (board[i + 1] == board[i + 2])) {
            return true;
        }
    }

    // Horizontal: Top to bottom 
    for (int j = 0; j < 9; j += 3) {

        // From the top left side to the bottom right
        if ((board[j] == board[j + 10]) && (board[j + 10] == board[j + 20])) {
            return true;
        }

        // From the top right side to the bottom left
        else if ((board[(j + 2)] == board[(j + 2) + 8]) && (board[(j + 2) + 8] == board[(j + 2) + 16])) {
            return true;
        }
    }

    // Horizontal: bottom to top
    for (int k = 18; k < 27; k += 3) {

        // From bottom left to the top right
        if ((board[k] == board[k - 8]) && (board[k - 8] == board[k - 16])) {
            return true;
        }

        // From bottom right to the top left
        else if ((board[k + 2] == board[(k + 2) - 10]) && (board[(k + 2) - 10] == board[(k + 2) - 20])) {
            return true;
        }
    }

    return false;
}

// Auxilary function for checkWinner (Veritcal cases)
bool checkVertical (char board[]) {

    // Check each coloumn on the same layer
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 27; j += 9) {
            if ((board[j] == board[j + 3]) && (board[j + 3] == board[j + 6])) {
                return true;
            }
        }
    }

    // From top to bottom 
    for (int i = 0; i < 3; i++) {
        if ((board[i] == board[i + 12]) && (board[i + 12] == board[i + 24])) {
            return true;
        }
    }

    // From bottom to top
    for (int i = 18; i < 20; i++) {
        if ((board[i] == board[i - 6]) && (board[i - 6] == board[i - 12])) {
            return true;
        }
    }

    // Vertical directly
    for (int i = 0; i < 9; i++) {
        if ((board[i] == board[i + 9]) && (board[i + 9] == board[i + 18])) {
            return true;
        }
    }

    return false;   
}

// Auxilary function for checkWinner (Diagonal cases)
bool checkDiagonal (char board[]) {

    
    return false;
}

// Check for winner 
bool checkWinner(char board[]) {
    
    // Check for horizontal win
    if (checkHorzitonalW(board)){
        cout << "True" << endl;
        return true;
    }
    cout << "false" << endl;
    return false;
}