//
// Created by Claudia Feochari on 2018-02-07.
//

#include "maps2.h"

void maps2::displayy()
{
    cout << "ANDREA:"<< endl;
    /*cin >> players ;
    cout << players + 4 << endl;*/
}
maps2::maps2()
{

};
maps2::maps2(int n)
{
    this->n = n;
    visited = new bool [n];
    connections = new int* [n];
    regionStart = new int* [n];
    for (int i = 0; i < n; i++)
    {
        connections[i] = new int [n];
        regionStart[i] = new int [n];
        for(int j = 0; j < n; j++)
        {
            connections[i][j] = 0;
            //regionStart[i][j] = 4;

        }
    }
};
void maps2::newRegion(int origin, int destin , int i)
{
    if(origin > n || destin > n || origin < 0 || destin < 0)
    {
        cout<<"Invalid edge!\n";
    }
    else
    {
        connections[origin - 1][destin - 1] = 1;
        regionStart[i][i] = origin;
    }
};

void maps2::display()
{
    //length = sizeof(regionStart)/sizeof(regionStart[0]);
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = 0; j < n; j++)
            cout<<connections[i][j]<<"  ";
        cout<<endl;
    }

    //cout<<sizeof(connections)/sizeof(connections[0])<<"  ";
}

void maps2::display2()
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = 0; j < n; j++)
            cout<<regionStart[i][j]<<"  ";
        cout<<endl;
    }

}

