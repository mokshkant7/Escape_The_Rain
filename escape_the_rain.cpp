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
setcolor(WHITE);
line(x+20,GroundY-120,x+20,GroundY-70);
}


void DrawMan(int x,int ldisp)

{

//head

circle(x,GroundY-90,10);
setfillstyle(SOLID_FILL,WHITE);
setcolor(WHITE);
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


void DrawManinHouse(int x, int ldisp)
{
    circle(x,GroundY-90,10);
    line(x,GroundY-80,x,GroundY-30);
    line(x,GroundY-70,x+10,GroundY-60+x%5);
    line(x,GroundY-70,x-10,GroundY-60+x%5);
    line(x,GroundY-30,x+ldisp,GroundY);
    line(x,GroundY-30,x-ldisp,GroundY);

}
void DrawManSit(int x)
{
    circle(x,GroundY-80,10);
    line(x,GroundY-70,x,GroundY-40);
    line(x,GroundY-60,x+10,GroundY-50);
    line(x,GroundY-60,x-10,GroundY-50);
    //line(x,)

}



void tree(int t,int q)
{
int r=15;
r=15;

rectangle(150+t,410+q,170+t,200+q);


setcolor(GREEN);
setfillstyle(SOLID_FILL, GREEN);
floodfill(151+t,342+q,2);
fillellipse(142+t,147+q,r+50,r+50);
fillellipse(160+t,130+q,r+50,r+50);
fillellipse(175+t,140+q,r+50,r+50);
fillellipse(180+t,150+q,r+50,r+50);
delay(0);
}

void DrawChair(){
 rectangle(440,350,470,383);
 line(460,340,490,340);
 line(460,340,440,350);
 line(490,340,470,350);
 line(490,340,490,GroundY);
}

void DrawMusicPlayer(int music_on,int frame_count){
 rectangle(200,GroundY-50,260,GroundY);
 if(music_on==0){
 circle(220,GroundY-30,15);
 circle(220,GroundY-30,7);
 rectangle(245,GroundY-40,255,GroundY-35);
 }
 else if(music_on == 1 && frame_count%3==0){
    circle(220,GroundY-30,12);
    circle(220,GroundY-30,10);
    rectangle(243,GroundY-25,256,GroundY-23);
    rectangle(243,GroundY-23,250,GroundY-21);
    rectangle(243,GroundY-21,252,GroundY-20);
    rectangle(243,GroundY-25,257,GroundY-23);
    rectangle(243,GroundY-21,245,GroundY-19);
    rectangle(243,GroundY-19,248,GroundY-17);
    rectangle(243,GroundY-17,250,GroundY-15);
    rectangle(243,GroundY-15,247,GroundY-13);
    rectangle(243,GroundY-13,251,GroundY-11);

 }
 else if(music_on==1 && frame_count%3!=0){
    circle(220,GroundY-30,15);
    circle(220,GroundY-30,7);
    rectangle(243,GroundY-19,255,GroundY-17);
    rectangle(243,GroundY-25,251,GroundY-23);
    rectangle(243,GroundY-25,250,GroundY-23);
    rectangle(243,GroundY-21,252,GroundY-19);
    rectangle(243,GroundY-23,245,GroundY-21);
    rectangle(243,GroundY-17,248,GroundY-15);
    rectangle(243,GroundY-15,245,GroundY-13);
    rectangle(243,GroundY-13,258,GroundY-11);
    rectangle(243,GroundY-21,250,GroundY-20);
 }
 circle(245,GroundY-30,1);
 circle(255,GroundY-30,1);
 circle(250,GroundY-30,1);
 rectangle(245,GroundY-40,255,GroundY-35);


}


int main()

{

  int gd=DETECT,gm,x=0;

  //Change BGI directory according to yours

  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

    /* Fill colours */


 int reachtime = 100;
  while(x<380)
  {
    char c[3] ;
    itoa(reachtime,c,2);
    outtextxy(10,10,"Get to the safe house ASAP to avoid getting hit by lightning");
    if(reachtime == 0){
     cleardevice();
     outtextxy(100,100,"Lightning struck you! you died!");
     reachtime = 100;
     x=0;
     delay(2000);

    }
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

   if(GetAsyncKeyState(VK_RIGHT)){
        ldisp=(ldisp+10)%20;
        x=(x+7)%ScreenWidth;
        }


   DrawMan(x,ldisp);
   DrawUmbrella(x,ldisp);

   delay(75);

   cleardevice();



}

setcolor(WHITE);
x=0;
int music_set=0;//to check if music system is on
int frame = 0;
int sit = 0;//to check if the character is sitting or not
while(1){
    if(GetAsyncKeyState('Q')&0x8000){
        break;
    }
    DrawChair();
    frame++;
    line(0,GroundY,ScreenWidth,GroundY);
    if(GetAsyncKeyState(VK_RIGHT)&& sit==0){
        ldisp=(ldisp+10)%20;
        x=(x+7)%ScreenWidth;
        }
    if(GetAsyncKeyState(VK_LEFT)and sit==0){
        ldisp=(ldisp-10)%20;
        x=(x-7)%ScreenWidth;
        }

//    DrawManinHouse(x,ldisp);
    DrawMusicPlayer(music_set,frame);
    //music option
    if(x>200 && x<250 && music_set==0){
        DrawManinHouse(x,ldisp);
        outtextxy(150,180, "Do you want to listen to music.press (P) to play");
        if(GetAsyncKeyState('P')&0x8000){
            music_set=1;
            frame = 0;
        }
    }
    else if(x>200 && x<250 && music_set==1){
        DrawManinHouse(x,ldisp);
        outtextxy(150,190, "Playing XYZ track rn");
        outtextxy(150,170, "Press [S] to stop music");
        if(GetAsyncKeyState('S')&0x8000)
            music_set = 0;
    }
    //sit option
    else if(x>440 && x<490 && sit ==1){
        x = 455;
        DrawManSit(x);
        outtextxy(400,190, "Press [G] to sit on the pouf");
        if(GetAsyncKeyState('G')&0x8000)
            sit = 0;
    }
    else if(x>440 && x<490 && sit ==0){
        DrawManinHouse(x,ldisp);
        outtextxy(400,190, "Press [S] to sit on the pouf");
        if(GetAsyncKeyState('S')&0x8000)
            sit = 1;
    }
    else{
        DrawManinHouse(x,ldisp);
    }
    delay(75);
    cleardevice();
    }
}


