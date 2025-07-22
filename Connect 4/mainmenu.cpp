#include <graphics.h>
#include <iostream>
#include <string>
#include "mainmenu.h"
#include "level_1.h"
using namespace std;

void mainmenu() {
    initwindow(400, 400, "Connect 4 - Main Menu");

    setbkcolor(LIGHTCYAN);
    cleardevice();

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(BLUE);
    outtextxy(100, 50, "CONNECT 4 GAME");

   
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(100, 150, 300, 190);
    rectangle(100, 150, 300, 190);
    setbkcolor(LIGHTGREEN);
    outtextxy(170, 160, "Level 1");

    
    setfillstyle(SOLID_FILL, LIGHTRED);
    bar(100, 230, 300, 270);
    rectangle(100, 230, 300, 270);
    setbkcolor(LIGHTRED);
    outtextxy(180, 240, "Exit");

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if (x >= 100 && x <= 300 && y >= 150 && y <= 190) {
                closegraph();
                level01();
                break;
            }

            if (x >= 100 && x <= 300 && y >= 230 && y <= 270) {
                closegraph();
                exit(0);
            }
        }

        delay(100);
    }
}



