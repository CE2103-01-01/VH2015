//
// Created by pablo on 18/04/15.
//

#ifndef VH2015_SHIP_H
#define VH2015_SHIP_H
#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 10;

int maxships = 10;

vArray<vArray<int>> matrix = vArray<vArray<int>>(rows, elements);

void Clear()
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < elements; j++)
        {

            *((*matrix[i])[j]) = 0;
        }
    }
}

void Show(bool gameover)
{
    cout<< "Current sea: "<< endl;
    for(int i=0; i < rows; i++)
    {
        //cout <<"|";
        for(int j=0; j < elements; j++)
        {
            int value = *((*matrix[i])[j]);
            cout<<"|";
            if (value == 0) cout <<" "<< " ";
            if (value == 2) cout <<"X"<< " ";
            if (value == 1) {
                if(gameover)cout <<"~"<< " ";
                else        cout <<" "<< " ";
            }

        }
        cout <<"|"<<endl;
    }
}

int NumberOfShips()
{
    int c = 0;

    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < elements; j++)
        {
            if(*((*matrix[i])[j]) == 1)
                c++;
        }
    }

    return c;
}

void SetShips()
{
    int s = 0;
    cout<<"CheatMode activated"<<endl;
    while(s < maxships)
    {
        int x = rand() % rows;
        int y = rand() % elements;
        cout<<x<<","<<y<<"/";
        if((*((*matrix[x])[y])) != 1)
        {
            s++;
            *((*matrix[x])[y]) = 1;
        }
    }
    cout<<endl;
}

bool Attack(int x,int y)
{
    if( x < elements  &&  y < rows)
    if(*((*matrix[x])[y]) == 1)
    {
        *((*matrix[x])[y]) = 2;
        return true;
    }
    return false;
}

int play() {
    srand(time(NULL));
    Clear();
    SetShips();
    int pos1, pos2;
    char prompt;
    while (prompt!='y') {
        try{
            Show(false);
            cout << "Please input X location";
            cin >> pos1;
            cout << "Please input Y location";
            cin >> pos2;
            if (Attack(pos1, pos2))
                cout << "You got me! :)" << endl;
            else
                cout << "Sorry no ship at that position!" << endl;
            cout << "Number of ships left: " << NumberOfShips() << endl;
            cout << "Do you want to surrender (y/n)? ";
            cin >> prompt;
        }catch(int e){
            cout << "Error " << e << endl;
            continue;
        }
    }
    cout << "Game over!" << endl;
    Show(true);
    return 0;
}

#endif //VH2015_SHIP_H
