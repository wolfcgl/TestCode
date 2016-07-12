/******************************************************************************
  File Name     : region_manager.cpp
  Version       : Initial Draft
  Author        : Wolf
  Created       : 2016/7/4
  Description   : source file
  History       :
  1.Date        : 2016/7/4
    Author      : Wolf
    Modification: Create file.
******************************************************************************/

#include "region_manager.h"

RegionManager::RegionManager(int _Width, int _Height) : mWidth(_Width), mHeight(_Height)
{
    initscr();
    echo();
    //keypad();
    clear();
}

int RegionManager::createRegion(std::string _regionName, Point& _point, int _width, int _height)
{
    int ret = -1;
    do {
        if ((_point.x + _width) > mWidth || (_point.y + _height) > mHeight) {
            break;
        }

        std::shared_ptr<Region> pRegion  = std::make_shared<Region>(_point, _width, _height);
        bool isBlank = true;
        for (auto pair : mCurRegions) {
            if (!Region::noCross(*pRegion, *(pair.second))) {
                isBlank = false;
                break;
            }
        }

        if (!isBlank) {
            break;
        }

        mCurRegions.insert(std::make_pair(_regionName, pRegion));
        ret = 0;
    } while (false);

    return 0;
}

std::shared_ptr<Region> RegionManager::getRegion(std::string _regionName)
{
    auto it = mCurRegions.find(_regionName);
    if (it != mCurRegions.end())
    {
        return it->second;
    } else {
        return nullptr;
    }
}

int RegionManager::setRegion(std::string _regionName, char _data, Point& _pos)
{
    int ret = -1;
    do {
        auto it = mCurRegions.find(_regionName);
        if (it == mCurRegions.end()) {
            break;
        }

        it->second->setChar(_data, _pos);
        ret = 0;
    } while (false);

    return ret;
}

int RegionManager::setRegion(std::string _regionName, char* _pdata, int _width, int _height, Point& _pos)
{
    int ret = -1;
    do {
        auto it = mCurRegions.find(_regionName);
        if (it == mCurRegions.end()) {
            break;
        }

        it->second->setBitMap(_pdata, _width, _height, _pos);
        ret = 0;
    } while (false);

    return ret;
}

int RegionManager::draw()
{
    for (auto pair : mCurRegions) {
        if (pair.second->isUpdate()) {
            pair.second->resetUpdate();
            char* pData = pair.second->getData();
            if (nullptr == pData) {
                break;
            }

            int i, j;
            int width = pair.second->getWidth();
            int height = pair.second->getHeigth();
            Point p = pair.second->getPoint();
            Point pOld = pair.second->getOldPoint();

            if (!(p == pOld)) { //Clear first
                for (i = 0; i < height; i++) {
                    move(pOld.y + i, pOld.x);
                    for (j = 0; j < width; j++) {
                        printw(" ");
                    }
                }
            }

            for (i = 0; i < height; i++) {
                move(p.y + i, p.x);
                for (j = 0; j < width; j++) {
                    printw("%c", pData[j + i * width] == '\0'? ' ' : pData[j + i * width]);
                }
            }
        }
    }
    refresh();
}

int RegionManager::moveRegion(std::string _regionName, Point& _point)
{
    int ret = -1;
    do {
        auto it = mCurRegions.find(_regionName);
        if (it == mCurRegions.end()) {
            break;
        }

        it->second->move(_point);

        bool isExceed = false;
        if (it->second->getPoint().x < 0 || it->second->getPoint().y < 0 || (it->second->getPoint().x + it->second->getWidth()) > mWidth || (it->second->getPoint().y + it->second->getHeigth()) > mHeight ) {
            isExceed = true;
        }
        if (isExceed) { //confilct
            it->second->undoMove();
            break;
        }

        bool isBlank = true;
        for (auto pair : mCurRegions) {
            if (it->first != pair.first && !Region::noCross(*(it->second), *(pair.second))) {
                isBlank = false;
                break;
            }
        }

        if (!isBlank) { //confilct
            it->second->undoMove();
            break;
        }

        ret = 0;
    } while (false);

    return ret;
}

RegionManager::~RegionManager()
{
    endwin();
}
