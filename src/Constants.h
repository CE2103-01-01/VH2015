//
// Created by pablo on 19/04/15.
//

#ifndef VH2015_CONSTANTS_H
#define VH2015_CONSTANTS_H

#define TREE_SIZE 50

#include <iosfwd>
#include <fstream>
#include <sys/stat.h>


namespace Constants
{
    // forward declarations only
    extern char const* const PROJECT_NAME;
    extern char const* const V_HEAP;
    extern char const* const SIZE_STR;
    extern char const* const PAGER_EXTENSION;
    extern const std::string PAGES_PATH;
    extern const std::string DUMPS_PATH;
    extern const int DEFRAGMENTER_FRECUENCY;
    extern const std::string homePath;
    extern const std::string projectPath;
    extern const std::string logsPath;
    extern const std::string logFilePath;
    extern char const* xmlPath;
    extern const std::string currentDateTime();
}


#endif //VH2015_CONSTANTS_H
