#include <iostream>
#include "functions.h"
using namespace std;

int main(){
    
    // char b[] = {'X', 'X', '0', 'X', '0', 'X', '0', '0', 'X', '0', ' ', '0', 'X', '0', '0', 'X', '0', '0', 'X', '0', ' ', '0', '0', 'X', '0', '0', ' '};
    char b[27];
    for (int i = 0; i < 27; i++) {
        b[i] = ' ';
    }
    
    greetAndInstruct();
    displayBoard(b);
    bool s = checkWinner(b);
    
    return 0;
}