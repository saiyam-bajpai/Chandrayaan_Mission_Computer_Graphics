#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#ifndef GRAY
#define GRAY LIGHTGRAY
#endif

#ifndef ORANGE
#define ORANGE 6
#endif

void drawStar(int x, int y, int col) {
    putpixel(x,   y,   col);
    putpixel(x+1, y,   col);
    putpixel(x,   y+1, col);
    putpixel(x+1, y+1, col);
}

void drawStarField(int n) {
    srand(42);
    for (int i = 0; i < n; i++) {
        int x = rand() % 640;
        int y = rand() % 480;
        int c = (rand() % 2) ? WHITE : LIGHTGRAY;
        drawStar(x, y, c);
    }
}

void fillTriangle(int x1,int y1, int x2,int y2, int x3,int y3, int col) {
    setfillstyle(SOLID_FILL, col);
    int pts[8] = {x1,y1, x2,y2, x3,y3, x1,y1};
    fillpoly(4, pts);
}

void showNum(int x, int y, int n) {
    char buf[16];
    sprintf(buf, "%d", n);
    outtextxy(x, y, buf);
}

void sceneLaunchPad() {
    cleardevice();

    setbkcolor(BLACK);
    cleardevice();

    setfillstyle(SOLID_FILL, DARKGRAY);
    setcolor(DARKGRAY);
    bar(0, 420, 640, 480);

    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(260, 280, 275, 420);
    bar(365, 280, 380, 420);


    setcolor(GRAY);
    line(262, 310, 378, 310);
    line(262, 350, 378, 350);
    line(262, 390, 378, 390);

    setfillstyle(SOLID_FILL, GRAY);
    setcolor(WHITE);
    bar(245, 415, 395, 430);

    setfillstyle(SOLID_FILL, WHITE);
    setcolor(WHITE);
    bar(300, 200, 340, 380);


    fillTriangle(320,150, 300,200, 340,200, WHITE);

    setfillstyle(SOLID_FILL, CYAN);
    setcolor(CYAN);
    circle(320, 230, 10);
    floodfill(320, 230, WHITE);

    fillTriangle(300,350, 280,400, 300,380, LIGHTRED);
    fillTriangle(340,350, 360,400, 340,380, LIGHTRED);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(285, 360, 305, 385);
    bar(335, 360, 355, 385);

    setcolor(BLUE);
    outtextxy(307, 270, "ISRO");

    setcolor(YELLOW);
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(140, 20, "CHANDRAYAAN MISSION");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

    setcolor(YELLOW);
    outtextxy(280, 80, "CGA PROJECT LAUNCH IN:");

    for (int cnt = 10; cnt >= 0; cnt--) {
        setfillstyle(SOLID_FILL, BLACK);
        bar(295, 100, 345, 130);

        setcolor(LIGHTRED);
        settextstyle(BOLD_FONT, HORIZ_DIR, 3);
        showNum(302, 100, cnt);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

        if (cnt <= 5) {
            int r = (6 - cnt) * 5;
            setcolor(DARKGRAY);
            setfillstyle(SOLID_FILL, DARKGRAY);
            for (int s = 0; s < 6; s++) {
                int sx = 310 + (rand()%40 - 20);
                int sy = 390 + (rand()%20);
                circle(sx, sy, r + (rand()%8));
                floodfill(sx, sy, DARKGRAY);
            }
        }

        delay(600);
    }

    setcolor(ORANGE);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(200, 100, "IGNITION!");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    delay(800);
}

void sceneLaunch() {
    int ry = 200;

    for (int frame = 0; frame < 220; frame++) {
        cleardevice();

        int skyBlue = (frame < 110) ? BLUE : (frame < 160) ? DARKGRAY : BLACK;
        setbkcolor(skyBlue);
        cleardevice();

        if (frame > 120) {
            srand(7);
            for (int i = 0; i < 60; i++) {
                putpixel(rand()%640, rand()%480, WHITE);
            }
        }

        if (frame < 140) {
            setcolor(WHITE);
            setfillstyle(SOLID_FILL, WHITE);
            int cy = 300 + frame * 2;
            if (cy < 480) {
                bar(80,  cy,    200, cy+20);
                bar(90,  cy-10, 180, cy);
                bar(400, cy+30, 540, cy+50);
                bar(410, cy+20, 530, cy+30);
            }
        }

        if (frame < 60) {
            setfillstyle(SOLID_FILL, DARKGRAY);
            setcolor(DARKGRAY);
            bar(0, 440 + frame*2, 640, 480);
        }

        ry = 200 - frame * 2;


        int fy = ry + 180;
        setcolor(ORANGE);
        setfillstyle(SOLID_FILL, ORANGE);
        fillTriangle(310, fy, 320, fy+50+(frame%15), 330, fy, ORANGE);
        fillTriangle(305, fy, 320, fy+35+(frame%10), 335, fy, YELLOW);

        fillTriangle(287, ry+165, 295, fy+25+(frame%8), 303, ry+165, ORANGE);
        fillTriangle(337, ry+165, 345, fy+25+(frame%8), 353, ry+165, ORANGE);

        setfillstyle(SOLID_FILL, WHITE);
        setcolor(WHITE);
        bar(300, ry, 340, ry+180);

        fillTriangle(320, ry-50, 300, ry, 340, ry, WHITE);

        setfillstyle(SOLID_FILL, CYAN);
        setcolor(CYAN);
        circle(320, ry+30, 10);
        floodfill(320, ry+30, CYAN);

        fillTriangle(300,ry+150, 280,ry+195, 300,ry+175, LIGHTRED);
        fillTriangle(340,ry+150, 360,ry+195, 340,ry+175, LIGHTRED);

        setfillstyle(SOLID_FILL, LIGHTGRAY);
        setcolor(LIGHTGRAY);
        bar(285, ry+155, 303, ry+180);
        bar(337, ry+155, 355, ry+180);

        setcolor(YELLOW);
        char buf[40];
        sprintf(buf, "Speed: %d km/h", 500 + frame*80);
        outtextxy(10, 10, buf);
        sprintf(buf, "Alt  : %d km",   frame * 5);
        outtextxy(10, 25, buf);

        delay(18);
    }
}

void sceneSpaceTravel() {
    int rx = 280, ry = 400;

    for (int frame = 0; frame < 180; frame++) {
        cleardevice();
        setbkcolor(BLACK);
        cleardevice();

        srand(frame % 3 == 0 ? frame : frame - 1);
        for (int i = 0; i < 150; i++) {
            int sx = rand() % 640;
            int sy = rand() % 480;
            int sc = (rand() % 3 == 0) ? YELLOW : WHITE;
            drawStar(sx, sy, sc);
        }

        if (frame < 120) {
            int ex = 80 - frame/3;
            int ey = 420 - frame/4;
            int er = 90 - frame/5;
            if (er > 5) {
                setcolor(BLUE);
                setfillstyle(SOLID_FILL, BLUE);
                circle(ex, ey, er);
                floodfill(ex, ey, BLUE);
                setfillstyle(SOLID_FILL, GREEN);
                setcolor(GREEN);
                bar(ex-20, ey-15, ex+5,  ey+20);
                bar(ex+10, ey-20, ex+30, ey+5);
            }
        }

        if (frame > 60) {
            int mf = frame - 60;
            int mx = 580 - mf;
            int my = 60  + mf/3;
            int mr = 20  + mf/5;
            setcolor(LIGHTGRAY);
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            circle(mx, my, mr);
            floodfill(mx, my, LIGHTGRAY);
            setfillstyle(SOLID_FILL, DARKGRAY);
            setcolor(DARKGRAY);
            circle(mx-8, my+5, 5);
            floodfill(mx-8, my+5, DARKGRAY);
            circle(mx+6, my-6, 4);
            floodfill(mx+6, my-6, DARKGRAY);
        }


        rx = 280 - frame * 2;
        ry = 400 - frame * 2;
        if (rx < 0) rx = 0;
        if (ry < 0) ry = 0;

        setfillstyle(SOLID_FILL, WHITE);
        setcolor(WHITE);
        bar(rx, ry, rx+30, ry+80);
        fillTriangle(rx+15, ry-25, rx, ry, rx+30, ry, WHITE);

        setcolor(ORANGE);
        setfillstyle(SOLID_FILL, ORANGE);
        fillTriangle(rx+5, ry+80, rx+15, ry+110+(frame%12), rx+25, ry+80, ORANGE);

        setcolor(YELLOW);
        char buf[60];
        sprintf(buf, "Distance from Earth: %d,000 km", frame * 18);
        outtextxy(10, 10, buf);

        delay(20);
    }
}

void drawMoon(int cx, int cy, int r) {
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(LIGHTGRAY);
    circle(cx, cy, r);
    floodfill(cx, cy, LIGHTGRAY);
    int cdata[][3] = {
        {cx-40, cy+20, 15},
        {cx+50, cy-10, 12},
        {cx-10, cy+50, 10},
        {cx+20, cy+40,  8},
        {cx-60, cy-20,  9},
        {cx+35, cy+55, 11}
    };
    for (int i = 0; i < 6; i++) {
        setfillstyle(SOLID_FILL, GRAY);
        setcolor(GRAY);
        circle(cdata[i][0], cdata[i][1], cdata[i][2]);
        floodfill(cdata[i][0], cdata[i][1], GRAY);
    }
}

void drawLander(int x, int y) {
    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(YELLOW);
    bar(x, y, x+40, y+25);
    setcolor(WHITE);
    line(x,    y+25, x-15, y+45);
    line(x+40, y+25, x+55, y+45);
    line(x+10, y+25, x,    y+45);
    line(x+30, y+25, x+40, y+45);

    setcolor(LIGHTGRAY);
    line(x-20, y+45, x+5,  y+45);
    line(x+40, y+45, x+60, y+45);
    setcolor(WHITE);
    line(x+20, y, x+20, y-20);
    circle(x+20, y-23, 4);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(x+5,  y+22, x+15, y+30);
    bar(x+25, y+22, x+35, y+30);
}

void sceneMoonLanding() {
    int lx = 290, ly = 80;

    for (int frame = 0; frame < 160; frame++) {
        cleardevice();
        setbkcolor(BLACK);
        cleardevice();

        srand(99);
        for (int i = 0; i < 120; i++)
            putpixel(rand()%640, rand()%300, WHITE);

        drawMoon(320, 650, 350);


        setcolor(LIGHTGRAY);
        line(0, 380, 640, 380);

        ly = 80 + frame * 2;
        if (ly > 325) ly = 325;


        if (ly < 320) {
            int intensity = (frame % 8) < 4 ? 30 : 20;
            setcolor(ORANGE);
            setfillstyle(SOLID_FILL, ORANGE);
            fillTriangle(lx+12, ly+46, lx+20, ly+46+intensity, lx+28, ly+46, ORANGE);
            fillTriangle(lx+5,  ly+46, lx+10, ly+46+intensity/2, lx+20, ly+46, YELLOW);
            fillTriangle(lx+20, ly+46, lx+30, ly+46+intensity/2, lx+35, ly+46, YELLOW);

            if (ly > 280) {
                setcolor(GRAY);
                for (int d = 0; d < 12; d++) {
                    int dx = lx + 20 + (rand()%80 - 40);
                    int dy = 380 + (rand()%10);
                    putpixel(dx, dy, GRAY);
                    putpixel(dx+1, dy, LIGHTGRAY);
                }
            }
        }

        drawLander(lx, ly);

        setcolor(YELLOW);
        char buf[60];
        int alt = (ly < 325) ? (325 - ly) / 2 : 0;
        sprintf(buf, "Altitude: %d m", alt);
        outtextxy(10, 10, buf);

        if (ly >= 325) {
            setcolor(GREEN);
            settextstyle(BOLD_FONT, HORIZ_DIR, 2);
            outtextxy(170, 40, "100% MARKS ACHIEVED!");
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

            setcolor(GRAY);
            for (int d = 0; d < 20; d++) {
                int dx = lx + 20 + (rand()%120 - 60);
                int dy = 375 + (rand()%15);
                circle(dx, dy, rand()%4);
            }
        } else {
            outtextxy(10, 25, "CGA PROJECT LANDING IN PROGRESS...");
        }

        delay(22);
    }
    delay(1000);
}

void drawIndianFlag(int x, int y) {
    setcolor(WHITE);
    line(x, y, x, y+60);

    setfillstyle(SOLID_FILL, 4);
    setcolor(4);
    bar(x+1, y, x+41, y+20);

    setfillstyle(SOLID_FILL, WHITE);
    setcolor(WHITE);
    bar(x+1, y+20, x+41, y+40);

    setfillstyle(SOLID_FILL, GREEN);
    setcolor(GREEN);
    bar(x+1, y+40, x+41, y+60);

    setcolor(BLUE);
    circle(x+21, y+30, 8);
    for (int i = 0; i < 24; i++) {
        float a = i * 15.0f * 3.14159f / 180.0f;
        line(x+21, y+30,
             x+21 + (int)(8*cos(a)),
             y+30 + (int)(8*sin(a)));
    }
}

void sceneFinal() {
    cleardevice();
    setbkcolor(BLACK);
    cleardevice();

    srand(55);
    for (int i = 0; i < 200; i++)
        putpixel(rand()%640, rand()%480, WHITE);

    setfillstyle(SOLID_FILL, BLUE);
    setcolor(BLUE);
    circle(80, 80, 55);
    floodfill(80, 80, BLUE);
    setfillstyle(SOLID_FILL, GREEN);
    bar(55, 65, 75, 110);
    bar(80, 55, 105, 80);
    setcolor(WHITE);
    outtextxy(50, 145, "EARTH");

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(LIGHTGRAY);
    bar(0, 370, 640, 480);

    int surfaceCraters[][3] = {
        {100,390,18}, {250,400,12}, {450,385,20},
        {560,405,14}, {350,420,10}
    };
    for (int i = 0; i < 5; i++) {
        setfillstyle(SOLID_FILL, GRAY);
        setcolor(GRAY);
        circle(surfaceCraters[i][0],
               surfaceCraters[i][1],
               surfaceCraters[i][2]);
        floodfill(surfaceCraters[i][0],
                  surfaceCraters[i][1], GRAY);
    }

    drawLander(290, 310);

    drawIndianFlag(360, 310);

    setcolor(YELLOW);
    for (int i = 0; i < 30; i++) {
        int sx = 20 + rand()%600;
        int sy = 20 + rand()%180;
        putpixel(sx,   sy,   YELLOW);
        putpixel(sx-1, sy,   YELLOW);
        putpixel(sx+1, sy,   YELLOW);
        putpixel(sx,   sy-1, YELLOW);
        putpixel(sx,   sy+1, YELLOW);
    }

    for (int flash = 0; flash < 6; flash++) {
        setfillstyle(SOLID_FILL, BLACK);
        bar(60, 200, 590, 280);

        if (flash % 2 == 0) {
            setcolor(YELLOW);
            settextstyle(BOLD_FONT, HORIZ_DIR, 4);
            outtextxy(70, 200, "GUIDED BY: MONA MA'AM");
            settextstyle(BOLD_FONT, HORIZ_DIR, 3);
            outtextxy(70, 200, "CGA PROJECT LANDED SUCCESSFULLY!");
            settextstyle(BOLD_FONT, HORIZ_DIR, 1);
            setcolor(CYAN);
            outtextxy(100, 250, "Chandrayaan - Pride of India");
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
        }
        delay(400);
    }

    setcolor(YELLOW);
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(70, 150, "GUIDED BY: MONA MA'AM");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(70, 200, "CGA PROJECT LANDED SUCCESSFULLY!");
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    setcolor(CYAN);
    outtextxy(100, 250, "Chandrayaan - Pride of India");
    setcolor(LIGHTGREEN);
    outtextxy(160, 275, "Jai Hind!  -  ISRO");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

    delay(4000);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

    sceneLaunchPad();
    sceneLaunch();
    sceneSpaceTravel();
    sceneMoonLanding();
    sceneFinal();

    getch();
    closegraph();
    return 0;
}