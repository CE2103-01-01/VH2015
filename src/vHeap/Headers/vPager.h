//
// Created by roberto on 04/04/15.
//

#ifndef VH2015_VPAGER_H
#define VH2015_VPAGER_H

#include <Constants.h>

class vPager {
public:
        void pageDown(void*, int, int);
        void pageUp(void*, int);
        void deletePage(int);
};

#endif //VH2015_VPAGER_H
