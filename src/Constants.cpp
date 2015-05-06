//
// Created by pablo on 19/04/15.
//


#include "Constants.h"
namespace Constants
{
    extern char const *const PROJECT_NAME = "VH2015";
    extern char const *const V_HEAP = "vHeap";
    extern char const *const SIZE_STR = "size";
    extern char const *const PAGER_EXTENSION = ".celdmm";
    extern const std::string homePath = getenv("HOME");
    extern const std::string projectPath = homePath + "/vh2015";
    int a = mkdir(Constants::projectPath.c_str(), 0777);
    extern const std::string PAGES_PATH = projectPath +"/pages/";
    int b = mkdir(Constants::PAGES_PATH.c_str(), 0777);
    extern const std::string DUMPS_PATH = projectPath +"/dumps";
    int c = mkdir(Constants::DUMPS_PATH.c_str(), 0777);
    extern const int DEFRAGMENTER_FRECUENCY = 30;
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
}