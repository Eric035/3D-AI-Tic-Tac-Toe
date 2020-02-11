#include <iostream>
#include "functions.h"
using namespace std;

int main(){
    
    char b[] = {'X', '0', '0', 'X', '0', 'X', '0', '0', 'X', '0', '0', '0', '0', 'X', '0', 'X', '0', '0', 'X', '0', 'X', '0', '0', 'X', '0', 'X', '0'};
    // cout << sizeof(b) / sizeof(b[0]) << endl;
    
    greetAndInstruct();
    displayBoard(b);
    
    return 0;
}