#include <graphics.h>
#include <iostream>
#include <string>
#include <cstdio>
#include "level_2.h"

using namespace std;

const int ROWS = 5;
const int COLS = 5;
const int CELL_SIZE = 80;
const int RADIUS = 20;

int grid[ROWS][COLS] = {0}; 

string player1 = "Player 1";
string player2 = "Player 2";
int score1 = 0;
int score2 = 0;

int currentPlayer = 1;

void drawBoard() {
    cleardevice();

    
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
//    setbkcolor(WHITE);
//    setcolor(BLACK);

    char scoreText1[50];
    sprintf(scoreText1, "%s : %d", player1.c_str(), score1);
    outtextxy(100, 20, scoreText1);

    char scoreText2[50];
    sprintf(scoreText2, "%s : %d", player2.c_str(), score2);
    outtextxy(400, 20, scoreText2);

    // Draw 7x7 grid
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int x = 100 + col * CELL_SIZE;
            int y = 100 + row * CELL_SIZE;

            setcolor(BLUE);
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            fillellipse(x, y, RADIUS, RADIUS);

            if (grid[row][col] == 1) {
                setfillstyle(SOLID_FILL, RED);
                fillellipse(x, y, RADIUS - 2, RADIUS - 2);
            } else if (grid[row][col] == 2) {
                setfillstyle(SOLID_FILL, YELLOW);
                fillellipse(x, y, RADIUS - 2, RADIUS - 2);
            }
        }
    }
}

bool checkWin(int player) {
    // Horizontal
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (grid[r][c] == player && grid[r][c + 1] == player && grid[r][c + 2] == player && grid[r][c + 3] == player)
                return true;
        }
    }

    // Vertical
    for (int r = 0; r <= ROWS - 4; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == player && grid[r + 1][c] == player && grid[r + 2][c] == player && grid[r + 3][c] == player)
                return true;
        }
    }

    // Diagonal (down-right)
    for (int r = 0; r <= ROWS - 4; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (grid[r][c] == player && grid[r + 1][c + 1] == player && grid[r + 2][c + 2] == player && grid[r + 3][c + 3] == player)
                return true;
        }
    }

    // Diagonal (up-right)
    for (int r = 3; r < ROWS; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (grid[r][c] == player && grid[r - 1][c + 1] == player && grid[r - 2][c + 2] == player && grid[r - 3][c + 3] == player)
                return true;
        }
    }

    return false;
}

bool dropPiece(int col, int player) {
    for (int row = ROWS - 1; row >= 0; row--) {
        if (grid[row][col] == 0) {
            grid[row][col] = player;
            return true;
        }
    }
    return false; 
}

void level02() {
    initwindow(800, 700, "Connect 4 - Level 1");
    

    drawBoard();

    while (true) {

        // Mouse click
        if (ismouseclick(WM_LBUTTONDOWN)) {
        	
            int x, y;
            
            getmouseclick(WM_LBUTTONDOWN, x, y);

            int colClicked = (x - 100) / CELL_SIZE;
            
            if (colClicked >= 0 && colClicked < COLS) {
                if (dropPiece(colClicked, currentPlayer)) {
                    drawBoard();

                    if (checkWin(currentPlayer)) {
                        
						settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
                        setcolor(GREEN);

                        char winText[50];
                        if (currentPlayer == 1) {
                            score1++;
                            sprintf(winText, "%s Wins!", player1.c_str());
                        } else {
                            score2++;
                            sprintf(winText, "%s Wins!", player2.c_str());
                        }

                        outtextxy(250, 670, winText);
                        drawBoard(); 
                        delay(2000);

                        memset(grid, 0, sizeof(grid));
                        currentPlayer = 1;
                        drawBoard();
                        continue;
                    }

                    currentPlayer = (currentPlayer == 1) ? 2 : 1;
                }
            }
        }

        delay(100);
    }

    closegraph();
}

