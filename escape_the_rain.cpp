#include<stdio.h>
#include<graphics.h>


#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.80


int ldisp=0;

void DrawUmbrella(int x,int ldisp)
{
setfillstyle(SOLID_FILL, BLUE);
setcolor(BLUE);
pieslice(x+20,GroundY-120,0,180,40);
setcolor(BLUE);
line(x+20,GroundY-120,x+20,GroundY-70);
}


void DrawMan(int x,int ldisp)

{

//head

circle(x,GroundY-90,10);

line(x,GroundY-80,x,GroundY-30);

//hand

line(x,GroundY-70,x+10,GroundY-60);

line(x,GroundY-65,x+10,GroundY-55);

line(x+10,GroundY-60,x+20,GroundY-70);

line(x+10,GroundY-55,x+20,GroundY-70);

//legs

line(x,GroundY-30,x+ldisp,GroundY);

line(x,GroundY-30,x-ldisp,GroundY);

}



void Rain(int x)

{

int i,rx,ry;

for(i=0;i<400;i++)

{

 rx=rand() % ScreenWidth;

 ry=rand() % ScreenHeight;

 if(ry<GroundY-4)

 {

  if(ry<GroundY-120 || (ry>GroundY-120 && (rx<x-20 || rx>x+60)))

  line(rx,ry,rx+0.5,ry+4);

 }

}

}



void tree(int t,int q)
{
int r=15;
r=15;

rectangle(150+t,410+q,170+t,140+q);


setcolor(GREEN);
setfillstyle(SOLID_FILL, GREEN);
floodfill(151+t,342+q,2);
fillellipse(142+t,147+q,r+50,r+50);
fillellipse(160+t,130+q,r+50,r+50);
fillellipse(175+t,140+q,r+50,r+50);
fillellipse(180+t,150+q,r+50,r+50);
delay(0);
}



int main()

{

  int gd=DETECT,gm,x=0;

  //Change BGI directory according to yours

  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

    /* Fill colours */


 int reachtime = 57;
  while(!kbhit() && reachtime>=0)

  {

    reachtime--;
    setcolor(GREEN);
    tree(-28, -28);

    setcolor(WHITE);
    rectangle(350,200,450,383);
    rectangle(450,200,620,383);
    rectangle(380,240,420,383);

    line(400,120,350,200);
    line(400,120,450,200);
    line(400,120,570,120);
    line(570,120,620,200);

   line(0,GroundY,ScreenWidth-270,GroundY);

   Rain(x);

   ldisp=(ldisp+2)%20;

   DrawMan(x,ldisp);
   DrawUmbrella(x,ldisp);

   delay(75);

   cleardevice();

   x=(x+7)%ScreenWidth;

}

setcolor(WHITE);
outtextxy(170,200, "You Reached The House Safe. Congratulations !");

  getch();

}


