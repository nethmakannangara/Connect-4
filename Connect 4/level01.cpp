#include <graphics.h>
#include "level_1.h"
#include <iostream>
using namespace std;
void level01(){
	initwindow(550,550,"Conncet 4");
	
	int x,y;
	
	for(int i = 1; i < 6; i++){
		for(int j = 1; j < 6; j++){
			circle(i*60,j*60,12);
		}
	}
	
	while(ismouseclick(WM_LBUTTONDOWN)){
//		cout << "mouse click" << endl;
	}
	
	getmouseclick(WM_LBUTTONDOWN,x,y);
	
	char coords[50];
    sprintf(coords, "Clicked at: (%d, %d)", x, y);
    outtextxy(100, 100, coords);
	
	getch();
	closegraph();
}
