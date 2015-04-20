//
// Created by pablo on 19/04/15.
//

#ifndef VH2015_CONSTANTS_H
#define VH2015_CONSTANTS_H


#include <iosfwd>
#include <fstream>
#include <sys/stat.h>

namespace Constants
{
    // forward declarations only
    extern const std::string homePath;
    extern const std::string projectPath;
    extern const std::string pagesPath;
    extern const std::string dumpsPath;
    extern const std::string logFilePath;
    extern std::ofstream log;
}


#endif //VH2015_CONSTANTS_H
