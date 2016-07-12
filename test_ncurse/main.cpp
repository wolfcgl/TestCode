#include <iostream>
#include <stdio.h>
#include "region_manager.h"
using namespace std;
using namespace NS_REGION;

#define BASEROW		1
#define PROMPTROW	20

char A[91] = {
    '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', 'A', '\0', '\0', '\0',
    '\0', '\0', '\0', 'A', '\0', '\0', '\0',
    '\0', '\0', 'A', '\0', 'A', '\0', '\0',
    '\0', '\0', 'A', '\0', 'A', '\0', '\0',
    '\0', '\0', 'A', '\0', 'A', '\0', '\0',
    '\0', '\0', 'A', 'A', 'A', '\0', '\0',
    '\0', 'A', '\0', '\0', '\0', 'A', '\0',
    '\0', 'A', '\0', '\0', '\0', 'A', '\0',
    'A', 'A', 'A', '\0', 'A', 'A', 'A',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0'
};

char B[91] = {
    '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    'B', 'B', 'B', 'B', 'B', '\0', '\0',
    '\0', 'B', '\0', '\0', '\0', 'B', '\0',
    '\0', 'B', '\0', '\0', '\0', 'B', '\0',
    '\0', 'B', '\0', '\0', '\0', 'B', '\0',
    '\0', 'B', 'B', 'B', 'B', '\0', '\0',
    '\0', 'B', '\0', '\0', '\0', 'B', '\0',
    '\0', 'B', '\0', '\0', '\0', 'B', '\0',
    '\0', 'B', '\0', '\0', '\0', 'B', '\0',
    'B', 'B', 'B', 'B', 'B', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0'
};

char C[91] = {
    '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', 'C', 'C', 'C', 'C', '\0',
    '\0', 'C', '\0', '\0', '\0', 'C', '\0',
    'C', '\0', '\0', '\0', '\0', 'C', '\0',
    'C', '\0', '\0', '\0', '\0', '\0', '\0',
    'C', '\0', '\0', '\0', '\0', '\0', '\0',
    'C', '\0', '\0', '\0', '\0', '\0', '\0',
    'C', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', 'C', '\0', '\0', '\0', 'C', '\0',
    '\0', '\0', 'C', 'C', 'C', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0'
};

char* carray[3] = { A, B, C};



int main()
{
    Point p1(0,0);
    Point p2(7,0);
    Point p3(14,0);
    Point p4(21,0);

    Point pE(1,0);
    Point pW(-1,0);
    Point pS(0,1);
    Point pN(0,-1);

    RegionManager rm(96, 48);
    rm.createRegion("A", p1, 7, 13);
    rm.createRegion("B", p2, 7, 13);
    rm.createRegion("C", p3, 7, 13);
    rm.createRegion("D", p4, 7, 13);

    rm.setRegion("A", A, 7, 13, p1);
    rm.setRegion("B", B, 7, 13, p1);
    rm.setRegion("C", C, 7, 13, p1);
    rm.draw();
    char c;
    int i = 0;
    while (true) {
        move(PROMPTROW,0);
        printw("Enter 'q' to exit.\065");
        c = getchar();
        if ('q' == c) {
            break;
        } else if ('E' == c) {
            rm.moveRegion("D", pE);
            //rm.getRegion("D")->move(pE);
            move(PROMPTROW + 1, 0);
            printw("(%d, %d)", rm.getRegion("D")->getPoint().x, rm.getRegion("D")->getPoint().y);
            refresh();
        } else if ('W' == c) {
            rm.moveRegion("D", pW);
            //rm.getRegion("D")->move(pW);
            move(PROMPTROW + 1, 0);
            printw("(%d, %d)", rm.getRegion("D")->getPoint().x, rm.getRegion("D")->getPoint().y);
            refresh();
        } else if ('N' == c) {
            rm.moveRegion("D", pN);
            //rm.getRegion("D")->move(pN);
            move(PROMPTROW + 1, 0);
            printw("(%d, %d)", rm.getRegion("D")->getPoint().x, rm.getRegion("D")->getPoint().y);
            refresh();
        } else if ('S' == c) {
            rm.moveRegion("D", pS);
            //rm.getRegion("D")->move(pS);
            move(PROMPTROW + 1, 0);
            printw("(%d, %d)", rm.getRegion("D")->getPoint().x, rm.getRegion("D")->getPoint().y);
            refresh();
        }

        rm.setRegion("D", carray[i++%3], 7, 13, p1);
        rm.draw();
    }
    return 0;
}
