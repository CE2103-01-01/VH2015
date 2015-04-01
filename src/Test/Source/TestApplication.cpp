//
// Created by Pablo Rodriguez Quesada on 3/30/15.
//


#include <vTypes/Headers/vString.h>
#include <fstream>
#include "Test/Headers/TestApplication.h"

int start(vString type) {
    if (type == "vList") createVList();
    return 0;
}

void createVList() {
    std::fstream myFile;
    myFile.open("book.txt");
    std::string line;
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            std::cout << line << '\n';
        }
        myFile.close();
    }

    else std::cout << "Unable to open file";
}