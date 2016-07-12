/******************************************************************************
  File Name     : region.cpp
  Version       : Initial Draft
  Author        : Wolf
  Created       : 2016/7/4
  Description   : source file
  History       :
  1.Date        : 2016/7/4
    Author      : Wolf
    Modification: Create file.
******************************************************************************/

#include "region.h"

namespace NS_REGION
{

Region::Region(Point& _point, int _width, int _height) : mPoint(_point), mOldPoint(_point), mWidth(_width), mHeight(_height), mUpdate(false), mpData(nullptr)
{
    int size = mWidth * mHeight;
    if (0 < size) {
        mpData  = new char[size];
    }
}

Region::Region(Region& _region) : mPoint(_region.getPoint()), mOldPoint(_region.getOldPoint()), \
                                        mWidth(_region.getWidth()), mHeight(_region.getHeigth()), mUpdate(false), mpData(nullptr)
{
    int size = mWidth * mHeight;
    if (0 < size) {
        mpData  = new char[size];
    }
    memcpy(mpData, _region.getData(), size);
}

int Region::setChar(char _data, Point& _pos)
{
    int ret = -1;
    do {
        if (nullptr == mpData) {
            break;
        }

        if (_pos.x > mWidth || _pos.y > mHeight) {
            break;
        }

        int pos = _pos.x + mWidth * _pos.y;
        mpData[pos] = _data;

        mUpdate = true;
        ret = 0;
    } while (false);

    return ret;
}

int Region::setBitMap(char* pData, int _width, int _height, Point& _pos)
{
    int ret = -1;
    do {
        if (nullptr == mpData) {
            break;
        }

        if ((_pos.x + _width) > mWidth || (_pos.y + _height) > mHeight) {
            break;
        }

        for (int i_h = 0; i_h < _height; i_h++) {
            int pos = _pos.x + mWidth * (_pos.y + i_h);
            for (int i_w = 0; i_w < _width; i_w++) {
                mpData[pos++] = pData[i_w + i_h * _width];
            }
        }

        mUpdate = true;
        ret = 0;
    } while (false);

    return ret;
}

int Region::setDirection(Direction _direction)
{
    return 0;
}

int Region::move(Point& _point)
{
    mOldPoint = mPoint;
    mPoint  = mPoint + _point;
    mUpdate = true;
    return 0;
}

int Region::undoMove()
{
    mPoint  = mOldPoint;
    return 0;
}

int Region::clearData()
{
    int ret = -1;
    do {
        if (nullptr == mpData) {
            break;
        }

        for (int i_h = 0; i_h < mHeight; i_h++) {
            int pos = mWidth * i_h;
            for (int i_w = 0; i_w < mWidth; i_w++) {
                mpData[pos++] = '\0';
            }
        }

        mUpdate = true;
        ret = 0;
    } while (false);

    return ret;
}

bool Region::isUpdate()
{
    return mUpdate;
}

void Region::resetUpdate()
{
    mUpdate = false;
}

char* Region::getData()
{
    return mpData;
}

int Region::getWidth()
{
    return mWidth;
}

int Region::getHeigth()
{
    return mHeight;
}

Point& Region::getPoint()
{
    return mPoint;
}

Point& Region::getOldPoint()
{
    return mOldPoint;
}

bool Region::noCross(const Region& _region1, const Region& _region2)
{
    return ((_region2.mPoint.x - _region1.mPoint.x) >= _region1.mWidth || (_region1.mPoint.x - _region2.mPoint.x) >= _region2.mWidth || \
            (_region2.mPoint.y - _region1.mPoint.y) >= _region1.mHeight || (_region1.mPoint.y - _region2.mPoint.y) >= _region2.mHeight);
}

Region::~Region()
{
    if (nullptr != mpData) {
        delete []mpData;
        mpData  = nullptr;
    }
}

} /* NS_REGION */
