#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

int area[80][23]={0};
int tailColumn[500];
int tailLine[500];
int maap[80][23]={0};

void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

void frame(int x1, int y1, int x2, int y2,int tour)
{
    int i;
    for(i=x1; i<=x2;i++)
    {
        area[i][y1] = tour;

        area[i][y2] = tour;

    }
    for(i=y1; i<=y2;i++)
    {
        area[x1][i] = tour;

        area[x2][i] = tour;

    }
}

void screenPress()
{
    int x,y;
    for(x=0;x<80;x++)
    {


        for(y=0;y<23;y++)
        {
        gotoxy(x+1,y+1);
            if(area[x][y]==1)
            {
                printf("%c",219);
            }

            else if(area[x][y]==2)
            {
                printf("%c",176);
            }
            else if(area[x][y]==3)
                printf("%c",88);

        }
    }
}

int k,l;
randomize()
{
    srand(time(NULL));
    k=4+rand()%65;
    l=4+rand()%15;


}
void main()
{
    randomize();
    frame(0,0,79,22,2);
    screenPress();
    int sx=40,sy=12;
    int dy=0,dx=0;
    unsigned char tus;
    int a=0;
    int cont=0;




     do
    {
        if(kbhit())
        {
            tus=getch();
            if(tus==224)
            {
                tus=getch();
                switch(tus)
                {
                    case 72:dy=-1; dx=0;
                        break;
                    case 80:dy=1; dx=0;
                        break;
                    case 77: dx=1; dy=0;
                        break;
                    case 75: dx=-1; dy=0;
                }
            }
        }

        sx=sx+dx;
        sy=sy+dy;
        if(sx>78)
            sx=2;
        if(sx<2)
            sx=78;
        if(sy>22)
            sy=2;
        if(sy<2)
            sy=22;

        tailColumn[0]=sx;
        tailLine[0]=sy;
        int i;


        for(i=1;i<=a;i++)
        {
            if((sx==tailColumn[i] && sy==tailLine[i]))
            {
                gotoxy(sx,sy);printf("--Game Over by Musa Erenberk--");
                getch();
                cont=1;
            }


        }

        gotoxy(sx,sy);printf("*");

        for(i=0;i<=a;i++)
        {
            gotoxy(tailColumn[i],tailLine[i]);printf("*");

        }


        if(sx==k && sy==l)
        {
            randomize();
            a++;
            gotoxy(2,2);printf("Score: %d",a);
        }

        gotoxy(k,l);printf("*");

        Sleep(50);

        gotoxy(sx,sy);printf(" ");


        for(i=0;i<=a;i++)
        {
            gotoxy(tailColumn[i],tailLine[i]);printf(" ");

        }


        for(i=a;i>0;i--)
        {
            tailColumn[i]=tailColumn[i-1];
            tailLine[i]=tailLine[i-1];
        }


    } while (cont==0);


}
