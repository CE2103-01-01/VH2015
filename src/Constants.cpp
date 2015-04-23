//
// Created by pablo on 19/04/15.
//


#include "Constants.h"
namespace Constants
{
    extern const int treeSize = 50;
    extern const std::string homePath = getenv("HOME");
    extern const std::string projectPath = homePath + "/vh2015";
    int a = mkdir(Constants::projectPath.c_str(), 0777);
    extern const std::string pagesPath = projectPath +"/pages/";
    int b = mkdir(Constants::pagesPath.c_str(), 0777);
    extern const std::string dumpsPath = projectPath +"/dumps";
    int c = mkdir(Constants::dumpsPath.c_str(), 0777);
    extern const std::string logsPath = projectPath +"/logs";
    int d = mkdir(Constants::logsPath.c_str(), 0777);
    extern const std::string logFilePath = logsPath +"/log"+currentDateTime()+".txt";
    extern char const *xmlPath ="vHeap.xml";
    extern const std::string currentDateTime() {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);

        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

        return buf;
    }
    extern const int defragmenterFrecuency = 30;
}