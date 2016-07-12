/******************************************************************************
  File Name     : region.h
  Version       : Initial Draft
  Author        : Wolf
  Created       : 2016/7/4
  Description   : Head file
  History       :
  1.Date        : 2016/7/4
    Author      : Wolf
    Modification: Create file.
******************************************************************************/

#ifndef _REGION_H_
#define _REGION_H_

#include<cstring>

namespace NS_REGION
{

class Point {
public:
    int x;
    int y;

public:
    Point() : x(0), y(0) {};
    Point(int _x, int _y) : x(_x), y(_y) {};
    Point(const Point& _point) {
        x = _point.x;
        y = _point.y;
    }

    Point& operator= (const Point& _point) {
        x = _point.x;
        y = _point.y;
        return *this;
    }

    Point& operator+ (const Point& _point) {
        x += _point.x;
        y += _point.y;
        return *this;
    }

    bool operator== (const Point& _point) {
        return (x == _point.x && y == _point.y);
    }

    ~Point() {};
};

enum Direction {
    North    = 0,
    South,
    East,
    West,
};

class Region
{
public:
    Region(Point& _point, int _width, int _height);
    Region(Region& _region);

    virtual int setChar(char _data, Point& _pos);
    virtual int setBitMap(char* pData, int _width, int _height, Point& _pos);
    virtual int setDirection(Direction _direction);
    virtual int clearData();
    virtual int move(Point& _point);
    virtual int undoMove();

    static bool noCross(const Region& _region1, const Region& _region2);

    bool isUpdate();
    void resetUpdate();

    char* getData();
    int getWidth();
    int getHeigth();
    Point& getPoint();
    Point& getOldPoint();

    virtual ~Region();
protected:
    Point   mPoint;
    Point   mOldPoint;
    int     mWidth;
    int     mHeight;

    char*   mpData;
    bool    mUpdate;

    Direction mDirection;
};

} /* NS_REGION */

#endif /* _REGION_H_ */
