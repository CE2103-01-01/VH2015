//
// Created by Pablo Rodriguez Quesada on 3/30/15.
//

#ifndef _VH2015_TESTAPPLICATION_H_
#define _VH2015_TESTAPPLICATION_H_


static char const *const txtPath = "book.txt";

static char const *const readError = "Unable to open file";

#include <iosfwd>
#include <string>
#include <vTypes/Headers/vString.h>
#include <fstream>
#include <sstream>
#include <vTypes/Headers/vDoubleList.h>
#include "vTypes/Headers/vBinaryTree.h"
using namespace std;


int start(string type);

void createVBinaryTree();
void createVDoubleList();
void createVSimpleList();


#endif //_VH2015_TESTAPPLICATION_H_


using namespace std;
int start(string type) {
    if (type == "vBinaryTree") createVBinaryTree();
    if (type == "vDoubleList") createVDoubleList();
    if (type == "vSimpleList") createVSimpleList();
    return 0;
}


void createVBinaryTree() {
    cout<<"Creando Arbol Binario"<<endl;

    vBinaryTree<vString> palabras = vBinaryTree<vString>();
    fstream myFile;
    myFile.open(txtPath);
    string line;

    time_t start,end;
    time (&start);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {

            istringstream iss(line);
            do {
                string sub;
                iss >> sub;
                if (sub!="")palabras.insert(sub);
            } while (iss);
        }
        myFile.close();
        time (&end);
        cout<<"se inserta correctamente el libro"<<endl;
        double dif = difftime (end,start);
        printf ("Tiempo transcurrido %.2lf segundos.", dif );
    }

    else cout << readError;
}


void createVDoubleList() {
    cout<<"Creando Lista Doble"<<endl;

    vDoubleList<vString> palabras = vDoubleList<vString>();
    fstream myFile;
    myFile.open(txtPath);
    string line;

    time_t start,end;
    time (&start);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {

            istringstream iss(line);
            do {
                string sub;
                iss >> sub;
                if (sub!="")palabras.insertBack(sub);
            } while (iss);
        }
        myFile.close();
        time (&end);
        cout<<"se inserta correctamente el libro"<<endl;
        double dif = difftime (end,start);
        printf ("Tiempo transcurrido %.2lf segundos.", dif );
    }

    else cout << readError;
}


void createVSimpleList(){
    cout<<"Creando Lista Simple"<<endl;

    vSimpleList<vString> palabras = vSimpleList<vString>();
    fstream myFile;
    myFile.open(txtPath);
    string line;

    time_t start,end;
    time (&start);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {

            istringstream iss(line);
            do {
                string sub;
                iss >> sub;
                if (sub!="")palabras + sub;
            } while (iss);
        }
        myFile.close();
        time (&end);
        cout<<"se inserta correctamente el libro"<<endl;
        double dif = difftime (end,start);
        printf ("Tiempo transcurrido %.2lf segundos.", dif );
    }

    else cout << readError;
}
