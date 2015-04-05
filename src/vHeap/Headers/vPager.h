//
// Created by roberto on 04/04/15.
//

#ifndef VH2015_VPAGER_H
#define VH2015_VPAGER_H

#include <string>
#include <fstream>

class vPager {
    public:
        vPager();
        ~vPager();
        std::string pageDown(void*, int, int);
        void pageUp(std::string, int, void*);
};

#endif //VH2015_VPAGER_H