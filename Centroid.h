//
// Created by oreste on 20/10/23.
//

#ifndef K_MEAN_CENTROID_H
#define K_MEAN_CENTROID_H


#include "Position.h"
#include <random>
#include<string>
#include<iostream>


using std::vector;
using std::cout;
using std::endl;
using std::string;

class Centroid : public Position
{
public:
    Centroid();
    Centroid(int maxWidth, int maxHeight );

    Centroid(const Position& position,int maxWidth, int maxHeight);
    int rangeRandom (int min, int max)const;
    virtual ~Centroid();
    void push_back(Position* point);


    const vector<Position *> &getPoints() const;

    void setPoints(const vector<Position *> &points);
    bool operator==(const Centroid&)const;



    void clear();

private:
    //random nber generator from cplusplus.com
    static int getRandomNumber(int min,int max);
    vector<Position*>points;
    void generateNewCentroidPosition();
};


#endif //K_MEAN_CENTROID_H
