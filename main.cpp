/* Welcome to the Impass Game, a game designed in 2018 by Irina Calin and Bogdan-Mihail Peltea for the Introduction to Programming 1st year Course
University Alexandru Ioan Cuza of Iasi
Faculty of Computer Science
*/

#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <windows.h>
#include <MMSystem.h>
#define MAX 20
#define FUNDAL BLACK
#define PIESA 1
#define SPATIU 0

using namespace std;

POINT CursorPoz;
int stanga,sus,latime,inaltime,latura, numarPatratele=8,i,j;
bool gata;
int player1=1;
int player2=0;
int TablaDeJoc[MAX][MAX];
char Player1[20];
char Player2[20];
char PlayerCalculator[20];
static void ContinuitateModern();
static void Continuitate();
static void Meniu();
static void MeniuModern();
static void rematch1();
static void rematch2();
static void rematch1Modern();
static void rematch2Modern();
DWORD screenWidth= GetSystemMetrics(SM_CXSCREEN);
DWORD screenHeight= GetSystemMetrics(SM_CYSCREEN);

void NumePlayerCalculator(char Nume[50])
{
    clearviewport();
    int done,XX=480,YY=290,i=0;
    char s[0];
    settextstyle(3,0,5);
    outtextxy(120,300,"Player Name: ");

    settextstyle(3,0,7);

    while(1)
    {
        setcolor(WHITE);
        done = getch();

        if(done == 13)
        {
            Nume[i]=NULL;
            break;
        }

        if(done == 8 )
        {
            i--;
            Nume[i]=NULL;
            setfillstyle(SOLID_FILL,BLACK);
            setcolor(BLACK);
            fillellipse(XX-25,YY+25,30,45);
            XX-=100;
        }

        if(('0'<=done && done<='7') || ('9'<=done && done<='123'))
        {
            s[0]=done;
            outtextxy(XX,YY,s);
            Nume[i++]=s[0];
        }

        if(done ==73 || done == 105 || done == 108|| done== 102 || done==108|| done==114||done==116)  // Fac aceasta instructine deoarece litera i este foarte distantata de celelalte litere.
            XX+=30;
        else

            XX+=50;
    }

}

void NumePlayerCalculatorModern(char Nume[50])
{
    setcolor(WHITE);
    clearviewport();
    readimagefile("PlayerVsPlayer.jpg",0,0,1080,720);
    int done,XX=480,YY=290,i=0;
    char s[0];
    settextstyle(10,0,5);
    outtextxy(120,300,"Player Name: ");

    settextstyle(10,0,7);

    while(1)
    {
        setcolor(3);
        done = getch();

        if(done == 13)
        {
            Nume[i]=NULL;
            break;
        }

        if(done == 8 )
        {
            i--;
            Nume[i]=NULL;
            setfillstyle(SOLID_FILL,BLACK);
            setcolor(BLACK);
            fillellipse(XX-25,YY+25,30,45);
            XX-=100;

        }

        if(('0'<=done && done<='7') || ('9'<=done && done<='123'))
        {


            s[0]=done;
            outtextxy(XX,YY,s);
            Nume[i++]=s[0];


        }
        XX+=50;
    }
}

void NumePlayer1(char Nume[50])
{
    clearviewport();
    int done,XX=480,YY=290,i=0;
    char s[0];
    settextstyle(3,0,5);
    outtextxy(120,300,"Player 1 Name: ");
    settextstyle(3,0,7);
    while(1)
    {
        setcolor(WHITE);
        done = getch();

        if(done == 13)
        {
            Nume[i]=NULL;
            break;
        }

        if(done == 8 )
        {
            i--;
            Nume[i]=NULL;
            setfillstyle(SOLID_FILL,BLACK);
            setcolor(BLACK);
            fillellipse(XX-25,YY+25,30,45);
            XX-=100;

        }

        if(('0'<=done && done<='7') || ('9'<=done && done<='123'))
        {
            s[0]=done;
            outtextxy(XX,YY,s);
            Nume[i++]=s[0];
        }
        if(done ==73 || done == 105 || done == 108|| done== 102 || done==108|| done==114||done==116)  // Fac aceasta instructine deoarece litera i este foarte distantata de celelalte litere.
            XX+=30;
        else
            XX+=50;
    }

}

void NumePlayer2(char Nume[50])
{
    setcolor(WHITE);
    clearviewport();
    int done,XX=480,YY=290,i=0;
    char s[0];
    settextstyle(3,0,5);
    outtextxy(120,300,"Player 2 Name: ");
    settextstyle(3,0,7);
    while(1)
    {
        setcolor(WHITE);
        done = getch();

        if(done == 13)
        {
            Nume[i]=NULL;
            break;
        }

        if(done == 8 )
        {
            i--;
            Nume[i]=NULL;
            setfillstyle(SOLID_FILL,BLACK);
            setcolor(BLACK);
            fillellipse(XX-25,YY+25,30,45);
            XX-=100;

        }

        if(('0'<=done && done<='7') || ('9'<=done && done<='123'))
        {
            s[0]=done;
            outtextxy(XX,YY,s);
            Nume[i++]=s[0];
        }

        if(done ==73 || done == 105 || done == 108|| done== 102 || done==108|| done==114||done==116)  // litera i este foarte distantata de celelalte litere.
            XX+=30;
        else

            XX+=50;
    }

}

void NumePlayer1Modern(char Nume[50])
{
    setcolor(WHITE);
    clearviewport();
    readimagefile("PlayerVsPlayer.jpg",0,0,1080,720);
    int done,XX=480,YY=290,i=0;
    char s[0];
    settextstyle(10,0,5);
    outtextxy(120,300,"Player 1 Name: ");
    settextstyle(10,0,7);
    while(1)
    {
        setcolor(3);
        done = getch();

        if(done == 13)
        {
            Nume[i]=NULL;
            break;
        }

        if(done == 8 )
        {
            i--;
            Nume[i]=NULL;
            setfillstyle(SOLID_FILL,BLACK);
            setcolor(BLACK);
            fillellipse(XX-25,YY+25,30,45);
            XX-=100;

        }

        if(('0'<=done && done<='7') || ('9'<=done && done<='123'))
        {


            s[0]=done;
            outtextxy(XX,YY,s);
            Nume[i++]=s[0];


        }
        XX+=50;
    }

}

void NumePlayer2Modern(char Nume[50])
{
    setcolor(WHITE);
    clearviewport();
    readimagefile("PlayerVsPlayer.jpg",0,0,1080,720);
    int done,XX=480,YY=290,i=0;
    char s[0];
    setcolor(WHITE);
    settextstyle(10,0,5);
    outtextxy(120,300,"Player 2 Name: ");
    settextstyle(10,0,7);
    while(1)
    {
        setcolor(3);
        done = getch();

        if(done == 13)
        {
            Nume[i]=NULL;
            break;
        }

        if(done == 8 )
        {
            i--;
            Nume[i]=NULL;
            setfillstyle(SOLID_FILL,BLACK);
            setcolor(BLACK);
            fillellipse(XX-25,YY+25,30,45);
            XX-=100;
        }

        if(('0'<=done && done<='7') || ('9'<=done && done<='123'))
        {
            s[0]=done;
            outtextxy(XX,YY,s);
            Nume[i++]=s[0];
        }
        XX+=50;
    }

}

void stergePiesa(int linia, int coloana)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    setcolor(BLUE);
    rectangle(x1,y1,x2,y2);
    setcolor(FUNDAL);
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
}

void deseneazaPiesa(int linia, int coloana, int codPiesa)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    setcolor(BLUE);
    rectangle(x1,y1,x2,y2);
    setcolor(FUNDAL);
    setfillstyle(SOLID_FILL,FUNDAL);
    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
    setcolor(CYAN);
    setfillstyle(SOLID_FILL,MAGENTA);
    fillellipse(xmijloc,ymijloc,18,18);
}

bool inInterior(int x, int y, int x1, int y1, int x2, int y2)
{
    return x1<=x && x<=x2 && y1<=y && y<=y2;
}

void initTabla()
{
    int linia, coloana;
    for (linia=1; linia<=numarPatratele; linia++)
        for (coloana=1; coloana<=numarPatratele; coloana++)
            if (linia>=5 && coloana<=4)//5,4//3,2
                TablaDeJoc[linia][coloana]=PIESA;
            else
                TablaDeJoc[linia][coloana]=SPATIU;
}

void initializariDimensiuni()
{
    latime=500;
    inaltime=500;
    latura=latime/numarPatratele;
    sus=(getmaxy()-latime)/2;
    stanga=(getmaxx()-inaltime)/2;
}

void creareTabla()
{
    initializariDimensiuni();
    setbkcolor(BLACK);
    clearviewport();

    int linia,coloana;
    for (linia=1; linia<=numarPatratele; linia++)
        for (coloana=1; coloana<=numarPatratele; coloana++)
        {
            if (TablaDeJoc[linia][coloana]==SPATIU)
                stergePiesa(linia,coloana);
            else
                deseneazaPiesa(linia,coloana,TablaDeJoc[linia][coloana]);
        }
    settextstyle(3,0,4);
    setcolor(YELLOW);
    outtextxy(80,100,Player1);
    setcolor(CYAN);
    outtextxy(80,140,Player2);
}

void creareTabla2()
{
    initializariDimensiuni();
    setbkcolor(BLACK);
    clearviewport();
    int linia,coloana;
    for (linia=1; linia<=numarPatratele; linia++)
        for (coloana=1; coloana<=numarPatratele; coloana++)
        {
            if (TablaDeJoc[linia][coloana]==SPATIU)
                stergePiesa(linia,coloana);
            else
                deseneazaPiesa(linia,coloana,TablaDeJoc[linia][coloana]);
        }
    settextstyle(3,0,4);
    setcolor(YELLOW);
    outtextxy(80,100,PlayerCalculator);
    setcolor(CYAN);
    outtextxy(80,130,"Computer");
}

void ButonBack()
{
    setcolor(WHITE);
    settextstyle( 3,0,4);
    outtextxy(880,640,"Back");
}

void Tutorial()
{
    clearviewport();
    settextstyle(3,0,4);
    outtextxy(50,50,"The rules of the game are easy!");
    outtextxy(50,100,"Here is what you have to do:");
    outtextxy(50,150,"There are 16 tokens on the Board.");
    outtextxy(50,200,"One of the players shall move any of the available tokens");
    outtextxy(50,250,"only to the right as many (empty) spaces as wanted,");
    outtextxy(50,500,"while the second one should only move them up.");
    outtextxy(50,550,"The game is over when one of the players");
    outtextxy(50,600,"is out of moves.");
    setcolor(CYAN);
    outtextxy(50,650,"Good luck!");
    settextstyle(3,0,4);
    outtextxy(350, 385, "Take me to the demo");
    rectangle(340,350,740,450); // P vs P
}

void mutarePiesa(int codPiesa)
{
    settextstyle(3,0,4);
    int linia1,coloana1,linia2,coloana2,x,y,test;
    initializariDimensiuni();
    bool mutareCorecta;
label:
    do
    {
        mutareCorecta=true;
        if (inInterior(mousex(),mousey(),840,600,980,680) && ismouseclick(WM_LBUTTONDOWN)) //butonul back
        {
            clearviewport();
            setcolor(WHITE);
            Meniu();
            Continuitate();
            break;
        }
        else if (inInterior(x=mousex(),y=mousey(),stanga,sus,stanga+latime,sus+inaltime) && ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            linia1=(y-sus)/latura+1;
            coloana1=(x-stanga)/latura+1;

            if (TablaDeJoc[linia1][coloana1]==codPiesa)
            {
                do
                {
                    getmouseclick(WM_LBUTTONDOWN,x,y);
                    if(inInterior(x,y,stanga,sus,stanga+latime,sus+inaltime)&& ismouseclick(WM_LBUTTONUP))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        linia2=(y-sus)/latura+1;
                        coloana2=(x-stanga)/latura+1;

                        if(player1==1 && coloana1==coloana2 && linia2<linia1)
                        {
                            int ok1=0;

                            for (int i=1; i<=linia1-linia2; i++) // Conditia pentru a nu putea sari peste pioni
                                if (TablaDeJoc[linia1-i][coloana2]!=SPATIU)
                                    ok1=1;

                            if (TablaDeJoc[linia2][coloana2]==SPATIU && ok1==0)
                            {
                                player1=0;
                                setcolor(CYAN);
                                outtextxy(80,100,Player1);
                                setcolor(YELLOW);
                                outtextxy(80,140,Player2);
                                mutareCorecta=false;
                                TablaDeJoc[linia1][coloana1]=SPATIU;
                                TablaDeJoc[linia2][coloana2]=codPiesa;
                                stergePiesa(linia1,coloana1);
                                deseneazaPiesa(linia2,coloana2,codPiesa);
                                test=1;
                                for (i=1; i<=numarPatratele; i++) //AICI
                                    for (j=1; j<numarPatratele; j++)
                                    {
                                        if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i][j+1]!=PIESA)
                                            test=0;
                                    }
                                if (test==1)
                                {
                                    PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                    clearviewport();
                                    settextstyle(3,0,7);
                                    setcolor(RED);
                                    outtextxy(370,230,"Game Over");
                                    settextstyle(3,0,5);
                                    setcolor(WHITE);
                                    outtextxy(460,310,Player1);
                                    outtextxy(480,360,"WON");
                                    rematch1();
                                    break;
                                }
                            }
                            else
                                goto label;

                        }

                        else if(player1==0 && linia1==linia2 && coloana2>coloana1)
                        {
                            int ok2=0;

                            for (int i=1; i<=coloana2-coloana1; i++) //Conditie sa nu se poata sari peste pioni
                                if (TablaDeJoc[linia2][coloana1+i]!=SPATIU)
                                    ok2=1;
                            if (TablaDeJoc[linia2][coloana2]==SPATIU && ok2==0)
                            {
                                player1=1;
                                setcolor(CYAN);
                                outtextxy(80,140,Player2);
                                setcolor(YELLOW);
                                outtextxy(80,100,Player1);
                                mutareCorecta=false;
                                TablaDeJoc[linia1][coloana1]=SPATIU;
                                TablaDeJoc[linia2][coloana2]=codPiesa;
                                stergePiesa(linia1,coloana1);
                                deseneazaPiesa(linia2,coloana2,codPiesa);
                                test=1;
                                for (j=1; j<=numarPatratele; j++)
                                    for (i=numarPatratele; i>1; i--) //AICI
                                        if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                            test=0;
                                if (test==1)
                                {
                                    PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                    clearviewport();
                                    settextstyle(3,0,7);
                                    setcolor(RED);
                                    outtextxy(370,230,"Game Over");
                                    settextstyle(3,0,5);
                                    setcolor(WHITE);
                                    outtextxy(460,310,Player2);
                                    outtextxy(480,360,"WON");
                                    rematch1();
                                    break;
                                }
                            }
                            else
                                goto label;
                        }
                    }

                }
                while (mutareCorecta);
            }
        }
        else
            goto label;
    }
    while (mutareCorecta);
}

void stergePiesaModern(int linia, int coloana)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
}

void deseneazaPiesaModern(int linia, int coloana, int codPiesa)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
    setcolor(BLUE);
    //setfillstyle(SOLID_FILL,0);
    readimagefile("Pion.jpg",xmijloc+19-38,ymijloc+18-38,xmijloc+19,ymijloc+18);//38 de pixeli are piesa;
}

bool numarParMutari ()
{
    int i,j,k=0,nr=0;
    for (i=1; i<=numarPatratele; i++)
        for(j=1; j<=numarPatratele; j++)

            if(TablaDeJoc[i][j]==PIESA)
            {
                nr+=i-k-1;
                k=i;
            }
    return (nr%2==0);
}

void joculCalculatoruluiModern(int codPiesa)
{
    int linia1,coloana1,linia2,coloana2,x,y,test;
    initializariDimensiuni();
    bool mutareCorecta;
label:
    do
    {
        mutareCorecta=true;
        if (inInterior(mousex(),mousey(),840,600,920,680) && ismouseclick(WM_LBUTTONDOWN)) //butonul back
        {
            clearviewport();

            MeniuModern();
            ContinuitateModern();
            break;
        }
        else if (inInterior(x=mousex(),y=mousey(),stanga,sus,stanga+latime,sus+inaltime) && ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            linia1=(y-sus)/latura+1;
            coloana1=(x-stanga)/latura+1;

            if (TablaDeJoc[linia1][coloana1]==codPiesa)
            {
                do
                {
                    getmouseclick(WM_LBUTTONDOWN,x,y);
                    if(inInterior(x,y,stanga,sus,stanga+latime,sus+inaltime)&& ismouseclick(WM_LBUTTONUP))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        linia2=(y-sus)/latura+1;
                        coloana2=(x-stanga)/latura+1;

                        if(coloana1==coloana2 && linia2<linia1)
                        {
                            int ok1=0;
                            for (int i=1; i<=linia1-linia2; i++)
                                if (TablaDeJoc[linia1-i][coloana2]!=SPATIU)
                                    ok1=1;
                            if (TablaDeJoc[linia2][coloana2]==SPATIU && ok1==0)
                            {
                                setcolor(BLUE);
                                outtextxy(80,100,PlayerCalculator);
                                setcolor(YELLOW);
                                outtextxy(80,140,"Computer");
                                mutareCorecta=false;
                                TablaDeJoc[linia1][coloana1]=SPATIU;
                                TablaDeJoc[linia2][coloana2]=codPiesa;
                                stergePiesaModern(linia1,coloana1);
                                deseneazaPiesaModern(linia2,coloana2,codPiesa);

                                test=1;
                                for (i=1; i<=numarPatratele; i++)
                                    for (j=1; j<numarPatratele; j++)
                                        if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i][j+1]!=PIESA)
                                            test=0;
                                if (test==1)
                                {
                                    //PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                    clearviewport();
                                    setcolor(WHITE);
                                    clearviewport();

                                    readimagefile("gameovermodernplayer.jpg",0,0,1080,720);
                                    rematch2Modern();
                                }

                                delay(300);
                                int ok2=0;
                                for (int i=numarPatratele; i>=2; i--)
                                    for(j=1; j<=numarPatratele; j++)
                                        if (TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]==SPATIU && ok2==0)
                                        {
                                            for(int k=j-1; k>=1; k--)
                                                if(TablaDeJoc[i-1][k]==PIESA && ok2==0)
                                                {
                                                    player1=1;
                                                    ok2=1;
                                                    setcolor(BLUE);
                                                    outtextxy(80,140,"Computer");
                                                    setcolor(YELLOW);
                                                    outtextxy(80,100,PlayerCalculator);
                                                    mutareCorecta=false;
                                                    TablaDeJoc[i-1][k]=SPATIU;
                                                    TablaDeJoc[i-1][j]=PIESA;
                                                    stergePiesaModern(i-1,k);
                                                    deseneazaPiesaModern(i-1,j,PIESA);
                                                    delay(300);
                                                    test=1;
                                                    for (j=1; j<=numarPatratele; j++)
                                                        for (i=numarPatratele; i>1; i--) //AICI
                                                            if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                                                test=0;
                                                    if (test==1)
                                                    {
                                                        clearviewport();

                                                        readimagefile("gameovermoderncalculator.jpg",0,0,1080,720);
                                                        rematch2Modern();

                                                    }
                                                }

                                        }
                                int ok4=0;
                                if (ok2==0)
                                {
                                    for (i=1; i<=numarPatratele; i++)
                                        for(j=1; j<=numarPatratele; j++)
                                            if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i+1][j]==SPATIU && ok4==0)
                                            {
                                                for(int k=j-1; k>=1; k--)
                                                    if(TablaDeJoc[i+1][k]==PIESA && ok4==0)
                                                    {
                                                        player1=1;
                                                        ok4=1;
                                                        setcolor(BLUE);
                                                        outtextxy(80,140,"Computer");
                                                        setcolor(YELLOW);
                                                        outtextxy(80,100,PlayerCalculator);
                                                        mutareCorecta=false;
                                                        TablaDeJoc[i+1][k]=SPATIU;
                                                        TablaDeJoc[i+1][j]=PIESA;
                                                        stergePiesaModern(i+1,k);
                                                        deseneazaPiesaModern(i+1,j,PIESA);
                                                        delay(300);
                                                        test=1;
                                                        for (j=1; j<=numarPatratele; j++)
                                                            for (i=numarPatratele; i>1; i--) //AICI
                                                                if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                                                    test=0;
                                                        if (test==1)
                                                        {
                                                            clearviewport();

                                                            readimagefile("gameovermoderncalculator.jpg",0,0,1080,720);
                                                            rematch2Modern();
                                                        }
                                                    }

                                            }
                                }
                                int ok3=0;
                                if (ok4==0 && ok2==0)
                                {
                                    for (i=numarPatratele; i>=1; i--)
                                        for(j=numarPatratele; j>=1; j--)
                                            if(TablaDeJoc[i][j]==PIESA && ok3==0)
                                            {
                                                for(int k=numarPatratele; k>j; k--)
                                                    if((TablaDeJoc[i][k]==SPATIU && ok3==0 && numarParMutari()==FALSE)|| (TablaDeJoc[i][k]==SPATIU && ok3==0 && j==numarPatratele-1))
                                                    {
                                                        ok3=1;
                                                        setcolor(BLUE);
                                                        outtextxy(80,140,"Computer");
                                                        setcolor(YELLOW);
                                                        outtextxy(80,100,PlayerCalculator);
                                                        mutareCorecta=false;
                                                        TablaDeJoc[i][j]=SPATIU;
                                                        TablaDeJoc[i][k]=PIESA;
                                                        stergePiesaModern(i,j);
                                                        deseneazaPiesaModern(i,k,PIESA);
                                                        delay(300);
                                                        test=1;
                                                        for (j=1; j<=numarPatratele; j++)
                                                            for (i=numarPatratele; i>1; i--) //AICI
                                                                if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                                                    test=0;
                                                        if (test==1)
                                                        {
                                                            //PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                                            clearviewport();

                                                            readimagefile("gameovermoderncalculator.jpg",0,0,1080,720);
                                                            rematch2Modern();
                                                        }

                                                    }
                                                    else if(TablaDeJoc[i][k-1]==SPATIU && ok3==0 && numarParMutari()==TRUE)
                                                    {
                                                        ok3=1;
                                                        setcolor(BLUE);
                                                        outtextxy(80,140,"Computer");
                                                        setcolor(YELLOW);
                                                        outtextxy(80,100,PlayerCalculator);
                                                        mutareCorecta=false;
                                                        TablaDeJoc[i][j]=SPATIU;
                                                        TablaDeJoc[i][k-1]=PIESA;
                                                        stergePiesaModern(i,j);
                                                        deseneazaPiesaModern(i,k-1,PIESA);
                                                        delay(300);
                                                        test=1;
                                                        for (j=1; j<=numarPatratele; j++)
                                                            for (i=numarPatratele; i>1; i--) //AICI
                                                                if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                                                    test=0;
                                                        if (test==1)
                                                        {
                                                            clearviewport();
                                                            readimagefile("gameovermoderncalculator.jpg",0,0,1080,720);
                                                            //settextstyle(10,0,5);
                                                            //setcolor(WHITE);
                                                            rematch2Modern();
                                                        }

                                                    }
                                            }
                                }
                            }
                            else
                                goto label;

                        }
                    }

                }
                while (mutareCorecta);
            }
        }
        else
            goto label;
    }
    while (mutareCorecta);
}

void joculCalculatorului(int codPiesa)
{
    int linia1,coloana1,linia2,coloana2,x,y,test;
    initializariDimensiuni();
    bool mutareCorecta;
label:
    do
    {
        mutareCorecta=true;
        if (inInterior(mousex(),mousey(),840,600,920,680) && ismouseclick(WM_LBUTTONDOWN)) //butonul back
        {
            clearviewport();
            setcolor(WHITE);
            Meniu();
            Continuitate();
            break;
        }
        else if (inInterior(x=mousex(),y=mousey(),stanga,sus,stanga+latime,sus+inaltime) && ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            linia1=(y-sus)/latura+1;
            coloana1=(x-stanga)/latura+1;

            if (TablaDeJoc[linia1][coloana1]==codPiesa)
            {
                do
                {
                    getmouseclick(WM_LBUTTONDOWN,x,y);
                    if(inInterior(x,y,stanga,sus,stanga+latime,sus+inaltime)&& ismouseclick(WM_LBUTTONUP))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        linia2=(y-sus)/latura+1;
                        coloana2=(x-stanga)/latura+1;

                        if(coloana1==coloana2 && linia2<linia1) //cand jucatorul muta
                        {
                            int ok1=0;
                            for (int i=1; i<=linia1-linia2; i++)
                                if (TablaDeJoc[linia1-i][coloana2]!=SPATIU)
                                    ok1=1;
                            if (TablaDeJoc[linia2][coloana2]==SPATIU && ok1==0)
                            {
                                setcolor(CYAN);
                                outtextxy(80,100,PlayerCalculator);
                                setcolor(YELLOW);
                                outtextxy(80,130,"Computer");
                                mutareCorecta=false;
                                TablaDeJoc[linia1][coloana1]=SPATIU;
                                TablaDeJoc[linia2][coloana2]=codPiesa;
                                stergePiesa(linia1,coloana1);
                                deseneazaPiesa(linia2,coloana2,codPiesa);

                                test=1;
                                for (i=1; i<=numarPatratele; i++)
                                    for (j=1; j<numarPatratele; j++)
                                        if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i][j+1]!=PIESA)
                                            test=0;
                                if (test==1)
                                {
                                    PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                    clearviewport();
                                    setcolor(WHITE);
                                    settextstyle(3,0,5);
                                    outtextxy(200,350,"GAME OVER. YOU WON.");
                                    rematch2();
                                }

                                delay(300); //dupa ce jucatorul a mutat, urmeaza calculatorul
                                int ok2=0; //cazul 1
                                for (int i=numarPatratele; i>=2; i--)
                                    for(j=1; j<=numarPatratele; j++)
                                        if (TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]==SPATIU && ok2==0) //daca exista o piesa care are deasupra spatiu
                                        {
                                            for(int k=j-1; k>=1; k--)
                                                if(TablaDeJoc[i-1][k]==PIESA && ok2==0) //daca exista o piesa pe randul de deasupra, se muta peste cea initiala daca este posibil
                                                {
                                                    player1=1;
                                                    ok2=1;
                                                    setcolor(CYAN);
                                                    outtextxy(80,130,"Computer");
                                                    setcolor(YELLOW);
                                                    outtextxy(80,100,PlayerCalculator);
                                                    mutareCorecta=false;
                                                    TablaDeJoc[i-1][k]=SPATIU;
                                                    TablaDeJoc[i-1][j]=PIESA;
                                                    stergePiesa(i-1,k);
                                                    deseneazaPiesa(i-1,j,PIESA);
                                                    delay(300);
                                                    test=1;
                                                    for (j=1; j<=numarPatratele; j++)
                                                        for (i=numarPatratele; i>1; i--) //se testeaza daca exista piesa care sa nu mai poata fi mutata in sus
                                                            if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                                                test=0;
                                                    if (test==1)
                                                    {
                                                        PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                                        clearviewport();
                                                        setcolor(WHITE);
                                                        settextstyle(3,0,5);
                                                        outtextxy(200,350,"GAME OVER. COMPUTER WON.");
                                                        rematch2();
                                                    }
                                                }

                                        }
                                // a doua situatie, analog cu prima
                                int ok4=0;
                                if (ok2==0) //cazul 2
                                {
                                    for (i=1; i<=numarPatratele; i++)
                                        for(j=1; j<=numarPatratele; j++)
                                            if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i+1][j]==SPATIU && ok4==0) //daca exista o piesa care are spatiu dedesubt
                                            {
                                                for(int k=j-1; k>=1; k--)
                                                    if(TablaDeJoc[i+1][k]==PIESA && ok4==0) //daca exista o piesa pe randul de dedesubt, se muta sub piesa initiala daca este posibil
                                                    {
                                                        player1=1;
                                                        ok4=1;
                                                        setcolor(CYAN);
                                                        outtextxy(80,130,"Computer");
                                                        setcolor(YELLOW);
                                                        outtextxy(80,100,PlayerCalculator);
                                                        mutareCorecta=false;
                                                        TablaDeJoc[i+1][k]=SPATIU;
                                                        TablaDeJoc[i+1][j]=PIESA;
                                                        stergePiesa(i+1,k);
                                                        deseneazaPiesa(i+1,j,PIESA);
                                                        delay(300);
                                                        test=1;
                                                        for (j=1; j<=numarPatratele; j++)
                                                            for (i=numarPatratele; i>1; i--) //AICI
                                                                if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                                                    test=0;
                                                        if (test==1)
                                                        {
                                                            PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                                            clearviewport();
                                                            setcolor(WHITE);
                                                            settextstyle(3,0,5);
                                                            outtextxy(200,350,"GAME OVER. COMPUTER WON.");
                                                            rematch2();
                                                        }
                                                    }

                                            }
                                }
                                int ok3=0; //cazul 3
                                if (ok4==0 && ok2==0)  //daca nu se poate aplica vreunul din cazurile 1 si 2
                                {
                                    for (i=numarPatratele; i>=1; i--)
                                        for(j=numarPatratele; j>=1; j--)
                                            if(TablaDeJoc[i][j]==PIESA && ok3==0)
                                            {
                                                for(int k=numarPatratele; k>j; k--) //se ia piesa de pe randul cel mai de jos si se muta in capat daca numarul total de mutari ale jucatorului este impar
                                                    if((TablaDeJoc[i][k]==SPATIU && ok3==0 && numarParMutari()==FALSE)|| (TablaDeJoc[i][k]==SPATIU && ok3==0 && j==numarPatratele-1)) //sau daca singura piesa care mai poate fi mutata se afla pe penultimul rand
                                                    {
                                                        ok3=1;
                                                        setcolor(CYAN);
                                                        outtextxy(80,130,"Computer");
                                                        setcolor(YELLOW);
                                                        outtextxy(80,100,PlayerCalculator);
                                                        mutareCorecta=false;
                                                        TablaDeJoc[i][j]=SPATIU;
                                                        TablaDeJoc[i][k]=PIESA;
                                                        stergePiesa(i,j);
                                                        deseneazaPiesa(i,k,PIESA);
                                                        delay(300);
                                                        test=1;
                                                        for (j=1; j<=numarPatratele; j++)
                                                            for (i=numarPatratele; i>1; i--) //AICI
                                                                if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                                                    test=0;
                                                        if (test==1)
                                                        {
                                                            PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                                            clearviewport();
                                                            setcolor(WHITE);
                                                            settextstyle(3,0,5);
                                                            outtextxy(200,350,"GAME OVER. COMPUTER WON.");
                                                            rematch2();
                                                        }

                                                    }
                                                    else if(TablaDeJoc[i][k-1]==SPATIU && ok3==0 && numarParMutari()==TRUE) //se ia piesa de pe randul cel mai de jos si se muta pe penultima coloana daca numarul total de mutari ale jucatorului este par
                                                    {
                                                        ok3=1;
                                                        setcolor(CYAN);
                                                        outtextxy(80,130,"Computer");
                                                        setcolor(YELLOW);
                                                        outtextxy(80,100,PlayerCalculator);
                                                        mutareCorecta=false;
                                                        TablaDeJoc[i][j]=SPATIU;
                                                        TablaDeJoc[i][k-1]=PIESA;
                                                        stergePiesa(i,j);
                                                        deseneazaPiesa(i,k-1,PIESA);
                                                        delay(300);
                                                        test=1;
                                                        for (j=1; j<=numarPatratele; j++)
                                                            for (i=numarPatratele; i>1; i--)
                                                                if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                                                    test=0;
                                                        if (test==1)
                                                        {
                                                            PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                                            clearviewport();
                                                            setcolor(WHITE);
                                                            settextstyle(3,0,5);
                                                            outtextxy(200,350,"GAME OVER. COMPUTER WON.");
                                                            rematch2();
                                                        }

                                                    }
                                            }
                                }
                            }
                            else
                                goto label;

                        }
                    }

                }
                while (mutareCorecta);
            }
        }
        else
            goto label;
    }
    while (mutareCorecta);
}

void rematch1 ()  //players vs player
{
    int x,y;
    outtextxy(440,535,"Play again");
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONUP,x,y);
            if (x>=340 && x<=710 && y>=500&&y<=600)
            {
                PlaySound("background.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
                clearviewport();
                initTabla();
                creareTabla();
                ButonBack();
                do
                {
                    mutarePiesa(PIESA);
                }
                while(1);
            }
        }
    }
    while(1);
}

void rematch2 () //player vs computer
{
    int x,y;
    outtextxy(390,535,"Play again");
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONUP,x,y);
            if (x>=340 && x<=710 && y>=500 && y<=600)
            {
                PlaySound("background.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
                clearviewport();
                initTabla();
                creareTabla2();
                ButonBack();
                do
                {
                    joculCalculatorului(PIESA);
                }
                while(1);
            }
        }
    }
    while (1);
}

void Continuitate()//In meniu, daca apasam back
{
    delay(2000);//Acest delay este pentru a nu apasa click pe tema si a se redirectiona direct in modul de joc P v P pentru ca unele coordonate sunt aceleasi.
    int x,y;

    if(ismouseclick(WM_LBUTTONUP))
        do
        {

            if(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONUP,x,y);
                if(x>=70 && x<=250 && y>=630 && y<=685)//Buton Inchidere
                {
                    closegraph();
                    exit(1);
                }
                if (x>=340 && x<=710 && y>=200 && y<=300) //Tutorial
                {

                    Tutorial();
                    ButonBack();
                }
                if (x>=340 && x<=710 && y>=350&&y<=450) //Player vs player
                {

                    NumePlayer1(Player1);
                    NumePlayer2(Player2);
                    initTabla();
                    creareTabla();
                    ButonBack();
                    do
                    {
                        mutarePiesa(PIESA);
                    }
                    while(1);
                }
                if (x>=340 && x<=710 && y>=500&&y<=600)  //Player vs computer
                {
                    NumePlayerCalculator(PlayerCalculator);
                    initTabla();
                    creareTabla2();
                    ButonBack();
                    do
                    {
                        joculCalculatorului(PIESA);
                    }
                    while(1);
                }
                if(x>=870&&x<=980&&y>=630&&y<=680)//Coordonatele butonului de back cu instructiunea asta - merge butonul de back din interiorul tutorialului;
                {
                    clearviewport();
                    Meniu();
                }
            }
        }
        while(1);
}

void Meniu()
{
    int ok=0;
    clearviewport();
    settextstyle(3,0,8 );
    outtextxy(435, 80, "MENU");
    settextstyle(3,0,4);
    outtextxy(115,640,"EXIT");
    settextstyle(3,0,5);
    outtextxy(410, 230, "How to play");
    settextstyle(3,0,4);
    outtextxy(380, 385, "Player Vs Player");
    settextstyle(3,0,4);
    outtextxy(348,535,"Player Vs Computer");
    rectangle(340,200,710,300); // Tutorial
    rectangle(340,350,710,450); // P vs P
    rectangle(340,500,710,600); //  P vs C
    Continuitate();
}

int loadingScreen()
{
    int ok=0;

    settextstyle(3,HORIZ_DIR,30);
    outtextxy(310, 200,"IMPASS GAME");
    settextstyle(3,0,6);
    outtextxy(420,500, "loading...");
    for(j=i; j<=410/2; j++)
    {
        setcolor(DARKGRAY);
        setfillstyle(SOLID_FILL,DARKGRAY);
        fillellipse(120+j*4,600,20,20);
    }
    setcolor(WHITE);
    for(i=1; i<=410/2; i++)
    {
        setfillstyle(SOLID_FILL,WHITE);
        fillellipse(120+i*4,600,20,20);
        delay(1);//1

    }
    ok=1;
    return ok;

}

void fereastraInceput()

{
    setcolor(WHITE); //intai am facut fundalul, apoi am pus si restul elementelor pe el
    settextstyle(3,HORIZ_DIR,30);
    outtextxy(310, 200,"IMPASS GAME");
    delay(800);
    settextstyle(3,HORIZ_DIR,5);
    outtextxy(260, 400,"Press any key to continue"); //generic

}

void creareTabla2Modern()
{
    initializariDimensiuni();
    clearviewport();
    readimagefile("Tabla1.jpg",0,0,1080,720);
    int linia,coloana;
    for (linia=1; linia<=numarPatratele; linia++)
        for (coloana=1; coloana<=numarPatratele; coloana++)
        {
            if (TablaDeJoc[linia][coloana]==SPATIU)
                stergePiesaModern(linia,coloana);
            else
                deseneazaPiesaModern(linia,coloana,TablaDeJoc[linia][coloana]);
        }
    settextstyle(10,0,4);
    setcolor(YELLOW);
    outtextxy(80,100,PlayerCalculator);
    setcolor(BLUE);
    outtextxy(80,140,"Computer");
}

void creareTablaModern()
{
    initializariDimensiuni();
    clearviewport();
    readimagefile("Tabla1.jpg",0,0,1080,720);
    int linia,coloana;
    for (linia=1; linia<=numarPatratele; linia++)
        for (coloana=1; coloana<=numarPatratele; coloana++)
        {
            if (TablaDeJoc[linia][coloana]==SPATIU)
                stergePiesaModern(linia,coloana);
            else
                deseneazaPiesaModern(linia,coloana,TablaDeJoc[linia][coloana]);
        }
    settextstyle(10,0,4);
    setcolor(YELLOW);
    outtextxy(80,100,Player1);
    setcolor(BLUE);
    outtextxy(80,140,Player2);
}

void TutorialModern()
{
    int xx;
    int yy;
    int i;
    clearviewport();
    for(i=1; i<=16; i++)
    {
        if(i==1)
            readimagefile("Tutorial1.jpg",0,0,1080,720);
        if(i==2)
            readimagefile("Tutorial2.jpg",0,0,1080,720);
        if(i==3)
            readimagefile("Tutorial3.jpg",0,0,1080,720);
        if(i==4)
            readimagefile("Tutorial4.jpg",0,0,1080,720);
        if(i==5)
            readimagefile("Tutorial5.jpg",0,0,1080,720);
        if(i==6)
            readimagefile("Tutorial6.jpg",0,0,1080,720);
        if(i==7)
            readimagefile("Tutorial7.jpg",0,0,1080,720);
        if(i==8)
            readimagefile("Tutorial8.jpg",0,0,1080,720);
        if(i==9)
            readimagefile("Tutorial9.jpg",0,0,1080,720);
        if(i==10)
            readimagefile("Tutorial10.jpg",0,0,1080,720);
        if(i==11)
            readimagefile("Tutorial11.jpg",0,0,1080,720);
        if(i==12)
            readimagefile("Tutorial12.jpg",0,0,1080,720);
        if(i==13)
            readimagefile("Tutorial13.jpg",0,0,1080,720);
        if(i==14)
            readimagefile("Tutorial14.jpg",0,0,1080,720);
        if(i==15)
            readimagefile("Tutorial15.jpg",0,0,1080,720);
        if(i==16)
            readimagefile("Tutorial16.jpg",0,0,1080,720);

        delay(10);
    }
    /*rectangle((screenWidth-1080)/2,(screenHeight-720)/2+200,(screenWidth-1080)/2+300,(screenHeight-720)/2+400);

       if(ismouseclick(WM_LBUTTONDOWN))
           {

            getmouseclick(WM_LBUTTONDOWN, xx, yy);
        //clearmouseclick(WM_LBUTTONDOWN);
        if(xx>=(screenWidth-1080)/2 && xx<=(screenWidth-1080)/2+300 && yy>=(screenHeight-720)/2+200 && yy<=(screenHeight-720)/2+400)
                {closegraph();
                exit(1);}
           }


    */
}

void MeniuModern()

{
    int ok=1;
    clearmouseclick(WM_LBUTTONDOWN);// Am pus clearmouseclick pentru ca altfel se bloca meniul
    readimagefile("Meniu.jpg",0,0,1080,720);

    while(ok==1)
    {
        GetCursorPos(&CursorPoz);

        if(CursorPoz.x>=(screenWidth-1080)/2+115 && CursorPoz.x<=(screenWidth-1080)/2+205 && CursorPoz.y>=(screenHeight-720)/2+610 && CursorPoz.y<=(screenHeight-720)/2+685) // Am pus astea ca ramaneau coordonatele din colt si nu se mai intampla nimic nu stiu de ce.
            readimagefile("ExitButon.jpg",0,0,1080,720);
        else if(CursorPoz.x>=(screenWidth-1080)/2+340 && CursorPoz.x<=(screenWidth-1080)/2+710 && CursorPoz.y>=(screenHeight-720)/2+200 && CursorPoz.y<=(screenHeight-720)/2+300)
            readimagefile("Buton1Inchis.jpg",0,0,1080,720);
        else if(CursorPoz.x>=(screenWidth-1080)/2+340 && CursorPoz.x<=(screenWidth-1080)/2+710 && CursorPoz.y>=(screenHeight-720)/2+350 && CursorPoz.y<=(screenHeight-720)/2+450)
            readimagefile("Buton2Inchis.jpg",0,0,1080,720);
        else if(CursorPoz.x>=(screenWidth-1080)/2+340 && CursorPoz.x<=(screenWidth-1080)/2+710 && CursorPoz.y>=(screenHeight-720)/2+500 && CursorPoz.y<=(screenHeight-720)/2+600)
            readimagefile("Buton3Inchis.jpg",0,0,1080,720);
        else
            readimagefile("Meniu.jpg",0,0,1080,720);
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            if((CursorPoz.x>=(screenWidth-1080)/2+70 && CursorPoz.x<=(screenWidth-1080)/2+250 && CursorPoz.y>=(screenHeight-720)/2+630 && CursorPoz.y<=(screenHeight-720)/2+685 )|| (CursorPoz.x>=(screenWidth-1080)/2+340 && CursorPoz.x<=(screenWidth-1080)/2+710 && CursorPoz.y>=(screenHeight-720)/2+200 && CursorPoz.y<=(screenHeight-720)/2+300)||(CursorPoz.x>=(screenWidth-1080)/2+340 && CursorPoz.x<=(screenWidth-1080)/2+710 && CursorPoz.y>=(screenHeight-720)/2+350 && CursorPoz.y<=(screenHeight-720)/2+450)||(CursorPoz.x>=(screenWidth-1080)/2+340 && CursorPoz.x<=(screenWidth-1080)/2+710 && CursorPoz.y>=(screenHeight-720)/2+500 && CursorPoz.y<=(screenHeight-720)/2+600)) //Coordonatele Butoanelor din meniu
            {
                ok=0;
                ContinuitateModern();
            }
        }

    }
    clearmouseclick(WM_LBUTTONDOWN);
}

void mutarePiesaModern(int codPiesa)
{
    settextstyle(10,0,4);
    int linia1,coloana1,linia2,coloana2,x,y,test;
    initializariDimensiuni();
    bool mutareCorecta;
label:
    do
    {
        mutareCorecta=true;
        if (inInterior(mousex(),mousey(),840,600,980,680) && ismouseclick(WM_LBUTTONDOWN)) //butonul back
        {
            clearviewport();
            setcolor(WHITE);
            MeniuModern();
            ContinuitateModern();
            break;
        }
        else if (inInterior(x=mousex(),y=mousey(),stanga,sus,stanga+latime,sus+inaltime) && ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            linia1=(y-sus)/latura+1;
            coloana1=(x-stanga)/latura+1;

            if (TablaDeJoc[linia1][coloana1]==codPiesa)
            {
                do
                {
                    getmouseclick(WM_LBUTTONDOWN,x,y);
                    if(inInterior(x,y,stanga,sus,stanga+latime,sus+inaltime)&& ismouseclick(WM_LBUTTONUP))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        linia2=(y-sus)/latura+1;
                        coloana2=(x-stanga)/latura+1;

                        if(player1==1 && coloana1==coloana2 && linia2<linia1)
                        {
                            int ok1=0;

                            for (int i=1; i<=linia1-linia2; i++) // Conditia pentru a nu putea sari peste pioni.
                                if (TablaDeJoc[linia1-i][coloana2]!=SPATIU)
                                    ok1=1;

                            if (TablaDeJoc[linia2][coloana2]==SPATIU && ok1==0)
                            {
                                player1=0;
                                setcolor(BLUE);
                                outtextxy(80,100,Player1);
                                setcolor(YELLOW);
                                outtextxy(80,140,Player2);
                                mutareCorecta=false;
                                TablaDeJoc[linia1][coloana1]=SPATIU;
                                TablaDeJoc[linia2][coloana2]=codPiesa;
                                stergePiesaModern(linia1,coloana1);
                                deseneazaPiesaModern(linia2,coloana2,codPiesa);
                                test=1;
                                for (i=1; i<=numarPatratele; i++) //AICI
                                    for (j=1; j<numarPatratele; j++)
                                    {
                                        if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i][j+1]!=PIESA)
                                            test=0;
                                    }
                                if (test==1)
                                {
                                    // PlaySound("gameo.wav", NULL, SND_FILENAME | SND_ASYNC);
                                    clearviewport();
                                    readimagefile("gameovermodern.jpg",0,0,1080,720);
                                    settextstyle(10,0,5);
                                    setcolor(WHITE);
                                    outtextxy(460,310,Player1);
                                    rematch1Modern();

                                    break;
                                }
                            }
                            else
                                goto label;

                        }

                        else if(player1==0 && linia1==linia2 && coloana2>coloana1)
                        {
                            int ok2=0;

                            for (int i=1; i<=coloana2-coloana1; i++)//Conditie sa nu se poata sari peste pioni
                                if (TablaDeJoc[linia2][coloana1+i]!=SPATIU)
                                    ok2=1;
                            if (TablaDeJoc[linia2][coloana2]==SPATIU && ok2==0)
                            {
                                player1=1;
                                setcolor(BLUE);
                                outtextxy(80,140,Player2);
                                setcolor(YELLOW);
                                outtextxy(80,100,Player1);
                                mutareCorecta=false;
                                TablaDeJoc[linia1][coloana1]=SPATIU;
                                TablaDeJoc[linia2][coloana2]=codPiesa;
                                stergePiesaModern(linia1,coloana1);
                                deseneazaPiesaModern(linia2,coloana2,codPiesa);
                                test=1;
                                for (j=1; j<=numarPatratele; j++)
                                    for (i=numarPatratele; i>1; i--) //AICI
                                        if(TablaDeJoc[i][j]==PIESA && TablaDeJoc[i-1][j]!=PIESA)
                                            test=0;
                                if (test==1)
                                {
                                    clearviewport();
                                    readimagefile("gameovermodern.jpg",0,0,1080,720);
                                    settextstyle(10,0,5);
                                    setcolor(WHITE);
                                    outtextxy(460,310,Player2);
                                    rematch1Modern();
                                    break;
                                }
                            }
                            else
                                goto label;
                        }
                    }

                }
                while (mutareCorecta);
            }
        }
        else
            goto label;
    }
    while (mutareCorecta);
}


void ContinuitateModern()
{

    int x,y,xx,yy;
    do
    {

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONUP,x,y);

            if(x>=70 && x<=250 && y>=630 && y<=685)//Buton Inchidere
            {
                closegraph();
                exit(1);
            }

            if (x>=340 && x<=710 && y>=200 && y<=300) //Tutorial
            {
                TutorialModern();

            }

            if (x>=340 && x<=710 && y>=350&&y<=450) //player vs player
            {

                NumePlayer1Modern(Player1);
                NumePlayer2Modern(Player2);
                creareTablaModern();


                do
                {
                    mutarePiesaModern(PIESA);
                }
                while(1);

            }

            if (x>=340 && x<=710 && y>=500&&y<=600)  //player vs computer
            {
                NumePlayerCalculatorModern(PlayerCalculator);
                initTabla();
                creareTabla2Modern();

                do
                {
                    joculCalculatoruluiModern(PIESA);
                }
                while(1);


            }

            if(x>=870&&x<=980&&y>=630&&y<=680)//Coordonatele butonului de back cu instructiunea asta - merge butonul de back din interiorul tutorialului;
            {
                clearviewport();
                MeniuModern();
            }
        }
    }
    while(1);
}

int AlegereTema()
{
    int x3,y3;
    int ok=5;//0 pentru tema veche 1 pentru tema frumoasa

    readimagefile("Tema.jpg",0,0,1080,720);
    /* setcolor(WHITE);
    settextstyle(3,0,8);
    outtextxy(300,170,"Pick a theme");
    rectangle(150,350,480,450);
    settextstyle(3,0,5);
    outtextxy(175,378,"1981 Theme");
    rectangle(550,350,920,450); Coordonatele butonului frumos
    */
    while(ok==5)
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN,x3,y3);

            if(x3>=550&&x3<=920&&y3>=350&&y3<=450)
            {
                PlaySound("backgroundModern.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
                ok=1;
            }
            else if(x3>=150&&x3<=480&&y3>=350&&y3<=450)
                ok=0;
        }
    return ok;
}

void rematch1Modern ()  //players vs player
{
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONUP,x,y);
            if (x>=340 && x<=710 && y>=500&&y<=600)
            {
                //PlaySound("backgroundModern.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
                clearviewport();
                initTabla();
                creareTablaModern();
                do
                {
                    mutarePiesaModern(PIESA);
                }
                while(1);
            }
        }
    }
    while(1);
}
void rematch2Modern () //player vs computer
{
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONUP,x,y);
            if (x>=340 && x<=710 && y>=500 && y<=600)
            {
                //PlaySound("backgroundModern.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
                clearviewport();
                initTabla();
                creareTabla2Modern();
                do
                {
                    joculCalculatoruluiModern(PIESA);
                }
                while(1);
            }
        }
    }
    while (1);
}
int IntroJoc()
{
    PlaySound("introSound.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    int ok=0;
    int xx;
    int yy;

    int i;
    clearviewport();
    for(i=1; i<=24; i++)
    {

        if(i==1)
        {
            readimagefile("Intro1.jpg",0,0,1080,720);
            delay(3000);
        }
        if(i==2)
            readimagefile("Intro2.jpg",0,0,1080,720);
        if(i==3)
            readimagefile("Intro3.jpg",0,0,1080,720);
        if(i==4)
            readimagefile("Intro4.jpg",0,0,1080,720);
        if(i==5)
            readimagefile("Intro5.jpg",0,0,1080,720);
        if(i==6)
        {
            readimagefile("Intro6.jpg",0,0,1080,720);//
            delay(6000);
        }
        if(i==7)
            readimagefile("Intro6.jpg",0,0,1080,720);
        if(i==8)
            readimagefile("Intro5.jpg",0,0,1080,720);
        if(i==9)
            readimagefile("Intro4.jpg",0,0,1080,720);
        if(i==10)
            readimagefile("Intro3.jpg",0,0,1080,720);
        if(i==11)
            readimagefile("Intro2.jpg",0,0,1080,720);
        if(i==12)
        {
            readimagefile("Intro1.jpg",0,0,1080,720);//
            delay(1000);
        }
        if(i==13)
            readimagefile("Intro7.jpg",0,0,1080,720);
        if(i==14)
            readimagefile("Intro8.jpg",0,0,1080,720);
        if(i==15)
            readimagefile("Intro9.jpg",0,0,1080,720);
        if(i==16)
            readimagefile("Intro10.jpg",0,0,1080,720);
        if(i==17)
            readimagefile("Intro11.jpg",0,0,1080,720);
        if(i==18)
        {
            readimagefile("Intro12.jpg",0,0,1080,720);
            delay(6000);
        }
        if(i==19)
            readimagefile("Intro12.jpg",0,0,1080,720);
        if(i==20)
            readimagefile("Intro11.jpg",0,0,1080,720);
        if(i==21)
            readimagefile("Intro10.jpg",0,0,1080,720);
        if(i==22)
            readimagefile("Intro9.jpg",0,0,1080,720);
        if(i==23)
            readimagefile("Intro8.jpg",0,0,1080,720);
        if(i==24)
        {
            readimagefile("Intro7.jpg",0,0,1080,720);
            delay(3000);
        }

        delay(50);
    }
    ok=1;
    return ok;
}



int main()
{
    initTabla();
    initwindow(1080,720,"",(screenWidth-1080)/2,(screenHeight-720)/2);
    if(IntroJoc()==1)
    {
        if(AlegereTema()==0)
        {
            clearviewport();
            fereastraInceput();
            if (getch())
            {
                clearviewport();
                loadingScreen();
                if(loadingScreen()==1)
                {
                    PlaySound("background.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
                    clearviewport();
                    Meniu();
                }
            }
        }

        else if(AlegereTema()==1)
        {
            clearviewport();
            MeniuModern();
        }
        return 0;

    }
}
