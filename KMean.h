//
// Created by oreste on 20/10/23.
//

#ifndef K_MEAN_KMEAN_H
#define K_MEAN_KMEAN_H


#include<iostream>
#include<vector>
#include "Position.h"
#include "Centroid.h"

using std::vector;
using std::cout;
using std::endl;
class KMean
{
public:
    KMean();
    KMean(int populationSize, int numCentroids, int maxCoordinateX, int maxCoordinateY);
    virtual ~KMean();
    const std::vector<Position*>& getPoints()const;
    const std::vector<Centroid*>& getCentroids()const;
    void init();


protected:

private:
    //points represente les habitants
    vector<Position*>points;
    vector<Centroid*>centroids;
    //vector<QColor> colors;
    void emptyCentroids();
    void emptyPoints();
    void regenerateCentroids();
    void regeneratePoints();

    int initialCentroidsSize;
    int initialPopulationSize;
    int maxCoordinateX;
    int maxCoordinateY;


    //In this function we will generate a random population of size number, where each Position(point) has values between maxWidth, maxHeight
    vector<Position*> generateRandomPopulation(int number, int maxWidth,int maxHeight);
    //In this function we will generate number random centroids with empty vector of poits, it will only generate the points of the super class
    //vector<Centroid*> generateRandomCentroids(int number);
    vector<Centroid*> generateRandomCentroids(int number, int maxWidth, int maxHeight);

    //this function will take all the generated centroids, and in their points vector, add generated random population
    //it will add a point in a centroid if that centroid is the closest to that point
    void distributePoints();
    std::vector<QColor> generateColors();
public:
    void setCentroidsPositionToMean();
private:
    void setCentroidPositionToMean(Centroid*);
};


#endif //K_MEAN_KMEAN_H
