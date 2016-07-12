/******************************************************************************
  File Name     : region_manager.h
  Version       : Initial Draft
  Author        : Wolf
  Created       : 2016/7/4
  Description   : Head file
  History       :
  1.Date        : 2016/7/4
    Author      : Wolf
    Modification: Create file.
******************************************************************************/

#ifndef _REGION_MANAGER_H_
#define _REGION_MANAGER_H_

#include <memory>
#include <string>
#include <map>

#include <ncurses.h>
#include "region.h"

using namespace std;
using namespace NS_REGION;

class RegionManager
{
public:
    RegionManager(int _Width, int _Height);
    int createRegion(std::string _regionName, Point& _point, int _width, int _height);
    std::shared_ptr<Region> getRegion(std::string _regionName);
    int setRegion(std::string _regionName, char _data, Point& _pos);
    int setRegion(std::string _regionName, char* _pdata, int _width, int _height, Point& _pos);
    int draw();

    int moveRegion(std::string _regionName, Point& _point);

    virtual ~RegionManager();
private:
    std::map<std::string, std::shared_ptr<Region>> mCurRegions;
    int     mWidth;
    int     mHeight;
};

#endif /* _REGION_MANAGER_H_ */
