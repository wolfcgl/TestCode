#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include "region_manager.h"
#include <unistd.h>
using namespace std;
using namespace NS_REGION;

#define BASEROW		0
#define PROMPTROW	20

char self[4][9] = {
    {//North
        '\0', 'A', '\0',
        'A', 'A', 'A',
        'A', 'A', 'A',
    },
    {//South
        'A', 'A', 'A',
        'A', 'A', 'A',
        '\0', 'A', '\0',
    },
    {//East
        'A', 'A', '\0',
        'A', 'A', 'A',
        'A', 'A', '\0',
    },
    {//West
        '\0', 'A', 'A',
        'A', 'A', 'A',
        '\0', 'A', 'A',
    },
};

char enemy[4][9] = {
    {//North
        '\0', 'A', '\0',
        'A', 'A', 'A',
        'A', '\0', 'A',
    },
    {//South
        'A', '\0', 'A',
        'A', 'A', 'A',
        '\0', 'A', '\0',
    },
    {//East
        'A', 'A', '\0',
        '\0', 'A', 'A',
        'A', 'A', '\0',
    },
    {//West
        '\0', 'A', 'A',
        'A', 'A', '\0',
        '\0', 'A', 'A',
    },
};

class Tank
{
public:
    Tank(bool isSelf, Direction _direction = North) : mFlag(isSelf), mDirection(_direction) {};
    Tank(const Tank& _tank) {
        mFlag = _tank.mFlag;
        mDirection  = _tank.mDirection;
    }

    ~Tank() {};
    int setDirection(Direction _direction) { mDirection = _direction;};
    char* getData() {
        if (mFlag) {
            return self[mDirection];
        } else {
            return enemy[mDirection];
        }
    }
private:
    Direction mDirection;
    bool mFlag;
};

int main()
{
    Point p1(0,0);
    Point p2(7,0);
    Point p3(14,0);
    Point p4(21,0);
    Point p5(14,16);

    Point pE(1,0);
    Point pW(-1,0);
    Point pS(0,1);
    Point pN(0,-1);

    map<string, Tank> tankList;
    Tank self(1, North);
    Tank enemy1(0, South);
    Tank enemy2(0, South);
    Tank enemy3(0, South);
    Tank enemy4(0, South);
    tankList.insert(std::make_pair("self", self));
    tankList.insert(std::make_pair("enemy1", enemy1));
    tankList.insert(std::make_pair("enemy2", enemy2));
    tankList.insert(std::make_pair("enemy3", enemy3));
    tankList.insert(std::make_pair("enemy4", enemy4));

    RegionManager rm(28, 18);
    rm.createRegion("enemy1", p1, 3, 3);
    rm.createRegion("enemy2", p2, 3, 3);
    rm.createRegion("enemy3", p3, 3, 3);
    rm.createRegion("enemy4", p4, 3, 3);
    rm.createRegion("self", p5, 3, 3);

    rm.setRegion("enemy1", enemy1.getData(), 3, 3, p1);
    rm.setRegion("enemy2", enemy2.getData(), 3, 3, p1);
    rm.setRegion("enemy3", enemy3.getData(), 3, 3, p1);
    rm.setRegion("enemy4", enemy4.getData(), 3, 3, p1);
    rm.setRegion("self", self.getData(), 3, 3, p1);
    rm.draw();

    sleep(1);
    char c;
    int i = 0;
    while (true) {
        move(PROMPTROW,0);
        printw("Enter 'q' to exit.");
        c = getchar();
        if ('q' == c) {
            break;
        }

        for (auto pair : tankList) {
            Direction dir = Direction(rand() % 4);
            pair.second.setDirection(dir);
            switch(dir) {
                case North:
                    rm.moveRegion(pair.first, pN);
                    break;
                case South:
                    rm.moveRegion(pair.first, pS);
                    break;
                case East:
                    rm.moveRegion(pair.first, pE);
                    break;
                case West:
                    rm.moveRegion(pair.first, pW);
                break;
                default:
                    break;
            }
            rm.setRegion(pair.first, pair.second.getData(), 3, 3, p1);
            //move(PROMPTROW + 1, 0);
            //printw("(%d, %d), %d", rm.getRegion(pair.first)->getPoint().x, rm.getRegion(pair.first)->getPoint().y, dir);
        }
        rm.draw();

        //sleep(1);
    }
    return 0;
}
