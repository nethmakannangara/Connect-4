#include <graphics.h>
#include <iostream>
#include <string>
#include <sstream>
#include "level_1.h"

using namespace std;

const int ROWS = 7;
const int COLS = 7;
const int CELL_SIZE = 80;
const int RADIUS = 30;

int grid[ROWS][COLS] = {0}; 

string player1 = "Player 1";
string player2 = "Player 2";
int score1 = 0;
int score2 = 0;


void drawBoard() {
    cleardevice();

    
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setbkcolor(WHITE);
    setcolor(BLACK);

//    outtextxy(100, 20, (player1 + " : " + to_string(score1)).c_str());
//    outtextxy(400, 20, (player2 + " : " + to_string(score2)).c_str());

	char scoreText1[50];
	sprintf(scoreText1, "%s : %d", player1.c_str(), score1);
	outtextxy(100, 20, scoreText1);

	char scoreText2[50];
	sprintf(scoreText2, "%s : %d", player2.c_str(), score2);
	outtextxy(400, 20, scoreText2);


    
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


void level01() {
    initwindow(800, 700, "Connect 4 - Level 1");

    drawBoard();


    getch();
    closegraph();
}

