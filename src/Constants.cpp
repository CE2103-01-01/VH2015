//
// Created by pablo on 19/04/15.
//

#include <sys/stat.h>
#include "Constants.h"
namespace Constants
{

    extern const std::string homePath = getenv("HOME");
    extern const std::string projectPath = homePath + "/vh2015";
    int a = mkdir(Constants::projectPath.c_str(), 0777);
    extern const std::string pagesPath = projectPath +"/pages";
    int b = mkdir(Constants::pagesPath.c_str(), 0777);
    extern const std::string dumpsPath = projectPath +"/dumps";
    int c = mkdir(Constants::dumpsPath.c_str(), 0777);
    extern const std::string logFilePath = projectPath +"/log.txt";
    extern std::ofstream log(logFilePath, std::ios_base::app | std::ios_base::out);


}