//
// Created by roberto on 04/04/15.
//

#ifndef VH2015_VPAGER_H
#define VH2015_VPAGER_H

static char const *const PATH = "../res/vPages/";

static char const *const extension = ".celdmm";

#include <string>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <Constants.h>

class vPager {
public:
        void pageDown(void*, int, int);
        void pageUp(void*, int, int);
        void deletePage(int);
};

#endif //VH2015_VPAGER_H
