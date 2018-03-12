//
// Created by Claudia Feochari on 2018-02-07.
//

#ifndef maps2_H
#define maps2_H

#endif

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class maps2{
private:
    int **connections;
    int **regionStart;
    int **regionEnd;
    bool *visited;
    char *length;
public:
    int hi;
    int n;
    int players;
    explicit maps2(int n);
    maps2();
    void display();
    void display2();
    void displayy();
    void newRegion(int origin, int destin , int i);
    
};