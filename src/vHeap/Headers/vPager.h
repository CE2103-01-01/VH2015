//
// Created by roberto on 04/04/15.
//

#ifndef VH2015_VPAGER_H
#define VH2015_VPAGER_H

#include <Constants.h>
#include <dirent.h>

class vPager {
public:
        void pageDown(void*, int, int);
        void pageUp(void*, int);
        void deletePage(int);
        static void clean();
};

#endif //VH2015_VPAGER_H
