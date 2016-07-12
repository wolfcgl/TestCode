/******************************************************************************
  File Name     : Point.h
  Version       : Initial Draft
  Author        : Wolf
  Created       : 2016/7/7
  Description   : Head file
  History       :
  1.Date        : 2016/7/7
    Author      : Wolf
    Modification: Create file.
******************************************************************************/

#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>

namespace NS_GEOMETRIC
{

template<typename Type>
class Point {
public:
    Type x;
    Type y;

public:
    Point() : x(0), y(0) {};
    Point(Type _x, Type _y) : x(_x), y(_y) {};
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

    bool operator!= (const Point& _point) {
        return (x != _point.x || y != _point.y);
    }

    ~Point() {};
};

template<typename Type>
double distance(Point<Type>& _point1, Point<Type>& _point2)
{
    return sqrt(pow((_point1.x - _point2.x), 2) + pow((_point1.y - _point2.y), 2));
}

template<typename Type>
class Point3D {
public:
    Type x;
    Type y;
    Type z;

public:
    Point3D() : x(0), y(0), z(0) {};
    Point3D(Type _x, Type _y, Type _z) : x(_x), y(_y), z(_z) {};
    Point3D(const Point3D& _point) {
        x = _point.x;
        y = _point.y;
        z = _point.z;
    }

    Point3D& operator= (const Point3D& _point) {
        x = _point.x;
        y = _point.y;
        z = _point.z;
        return *this;
    }

    Point3D& operator+ (const Point3D& _point) {
        x += _point.x;
        y += _point.y;
        z += _point.z;
        return *this;
    }

    bool operator== (const Point3D& _point) {
        return (x == _point.x && y == _point.y && z == _point.z);
    }

    bool operator!= (const Point3D& _point) {
        return (x != _point.x || y != _point.y || z != _point.z);
    }

    ~Point3D() {};
};

template<typename Type>
double distance(Point3D<Type>& _point1, Point3D<Type>& _point2)
{
    return sqrt(pow((_point1.x - _point2.x), 2) + pow((_point1.y - _point2.y), 2) + pow((_point1.z - _point2.z), 2));
}

} /* NS_GEOMETRIC */

#endif /* _POINT_H_ */
