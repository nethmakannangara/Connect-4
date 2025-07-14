#include "level_1.h"
#include <iostream>
#include <graphics.h>

void levelwindow(){
	initwindow(500,500,"Connect 4");
	
	for(int i = 1; i < 6; i++){
		for(int j = 1; j < 6; j++){
			circle(i*60, j*60, 12);
		}
	}
	
	getch();
	closegraph();
}
