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
    vList<string> palabras = vList<string>();
    fstream myFile;
    myFile.open(txtPath);
    string line;
    if (myFile.is_open()) {
        while (getline(myFile, line)) {

            istringstream iss(line);
            do {
                string sub;
                iss >> sub;
                palabras.append(sub);
            } while (iss);
        }
        myFile.close();
    }

    else cout << readError;
}