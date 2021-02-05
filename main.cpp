//
//  main.cpp
//  tic-tac-toe
//
//  Created by Gregory, Sam (ELS-OXF) on 31/01/2021.
//  Copyright © 2021 Gregory, Sam (ELS-OXF). All rights reserved.
//

#include <iostream>

char board [3][3] ={{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
enum Player { x, y };
Player p = x;
bool gameOver = false;
int counter = 0;

void drawBoard() {
    std::cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << std::endl;
}

char translateMove(int move) {
    switch (move) {
        case 1:
            return board[0][0];
            break;
        case 2:
            return board[0][1];
            break;
        case 3:
            return board[0][2];
            break;
        case 4:
            return board[1][0];
            break;
        case 5:
            return board[1][1];
            break;
        case 6:
            return board[1][2];
            break;
        case 7:
            return board[2][0];
            break;
        case 8:
            return board[2][1];
            break;
        case 9:
            return board[2][2];
            break;
        default:
            return ' ';
            break;
    }
}

int getInput() {
    int move;
    std::cout << "Where would you like to move?" << std::endl;
    std::cin >> move;
    if (move > 9 || move < 1) {
        move = getInput();
    } else {
        if(translateMove(move) != ' ') {
            move = getInput();
        }
    }
    return move;
}

char getSymbol() {
    return (p == x) ? 'x' : 'o';
}

void takeInput() {
    int move;
    std::cout << "Player: " << p << std::endl;
    move = getInput();
    switch (move) {
        case 1:
            board[0][0] = getSymbol();
            break;
        case 2:
            board[0][1] = getSymbol();
            break;
        case 3:
            board[0][2] = getSymbol();
            break;
        case 4:
            board[1][0] = getSymbol();
            break;
        case 5:
            board[1][1] = getSymbol();
            break;
        case 6:
            board[1][2] = getSymbol();
            break;
        case 7:
            board[2][0] = getSymbol();
            break;
        case 8:
            board[2][1] = getSymbol();
            break;
        case 9:
            board[2][2] = getSymbol();
            break;
        default:
            break;
    }
}

void gameLogic() {
    // check game over
    if (counter == 8) {
        gameOver = true;
        return;
    }
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][1] != ' ') gameOver = true;
    }
    
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') gameOver = true;
    }
    
    // check diagnols
    if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ') gameOver = true;
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') gameOver = true;
    
    
    if(!gameOver) {
        // swap player
        if(p == x) {
            p = y;
        } else {
            p = x;
        }
    }
    
    // increment counter
    counter ++;
}

int main(int argc, const char * argv[]) {
    while(!gameOver) {
        takeInput();
        drawBoard();
        gameLogic();
    }
    std::cout << "Winner is player " << p << std::endl;
    return 0;
}
