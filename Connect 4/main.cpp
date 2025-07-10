#include<graphics.h>

int main()
{
	//code is working with project ( 32bit release)
	//creating window
	initwindow(1000,800,"Connect 4",50,50,false,true);
    setbkcolor(WHITE);
    cleardevice();
    
    
    //creating display the name
    setfillstyle(SOLID_FILL,YELLOW);
    bar(200,200,800,400);
    setcolor(GREEN);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
    outtextxy(270,275,(char*)"CONNECT 4");
    
    //next button creation
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(150,700,300,750);
    setcolor(BLACK);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(160,710,(char*)"NEXT--->");
    
    //commanding to next window
    while(!
	ismouseclick(WM_LBUTTONDOWN)){
		delay(10); // avoid using high CPU waiting unless it gets errors
	};
	int mx , my ;
	getmouseclick(WM_LBUTTONDOWN, mx ,my);
	
	if(mx>=150 && mx<=300 && my>=700 && my<=750);
	outtextxy(155,760,(char*)"NEXT CLICKED!");
	
   
     getch();
     closegraph();
     
     return 0;
}


