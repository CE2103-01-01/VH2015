//
// Created by Pablo Rodriguez Quesada on 3/30/15.
//


using namespace std;
int start(vString type) {
    if (type == "vBinaryTree") createVList();
    return 0;
}

void createVBinaryTree() {
    vBinaryTree <string> palabras = vBinaryTree<string>();
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