//
// Created by Pablo Rodriguez Quesada on 3/30/15.
//


#include <vTypes/Headers/vString.h>
#include <fstream>
#include <sstream>
#include "Test/Headers/TestApplication.h"

using namespace std;
int start(vString type) {
    if (type == "vList") createVList();
    return 0;
}

void createVList() {
    fstream myFile;
    myFile.open("book.txt");
    string line;
    if (myFile.is_open()) {
        while (getline(myFile, line)) {

            istringstream iss(line);
            do {
                string sub;
                iss >> sub;
                cout << sub << endl;
            } while (iss);
        }
        myFile.close();
    }

    else cout << "Unable to open file";
}