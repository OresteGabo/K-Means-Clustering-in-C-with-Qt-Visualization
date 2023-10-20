//
// Created by oreste on 20/10/23.
//

#include "KMean.h"

// Implementation for KMean constructor
KMean::KMean(int populationSize, int numCentroids, int maxCoordinateX, int maxCoordinateY) {
    // Initialize and generate the population and centroids
    points = generateRandomPopulation(populationSize, maxCoordinateX, maxCoordinateY);
    centroids = generateRandomCentroids(3, maxCoordinateX, maxCoordinateY);

    // Distribute the points among the centroids
    //distributePoints();
}
// Implementation for KMean destructor
KMean::~KMean(){}

KMean::KMean():KMean(100, 3, 600, 400){}

// Function to generate a random population of Position objects
vector<Position*> KMean::generateRandomPopulation(int number, int maxWidth, int maxHeight) {
    vector<Position*> population;
    for (int i = 0; i < number; i++) {
        int randomX = rand() % (maxWidth + 1);
        int randomY = rand() % (maxHeight + 1);
        Position* newPoint = new Position(randomX, randomY);
        population.push_back(newPoint);
    }
    return population;
}

vector<Centroid*> KMean::generateRandomCentroids(int number, int maxWidth, int maxHeight) {
    vector<Centroid*> centroids;
    for (int i = 0; i < number; i++) {
        Centroid* newCentroid = new Centroid(maxWidth, maxHeight);
        centroids.push_back(newCentroid);
    }
    return centroids;
}

// Function to distribute points to the closest centroids
void KMean::distributePoints() {
    for (Position* point : points) {
        Centroid* closestCentroid = centroids[0];
        double minDistance = point->distanceTo(*closestCentroid);

        for (Centroid* centroid : centroids) {
            double distance = point->distanceTo(*centroid);
            if (distance < minDistance) {
                minDistance = distance;
                closestCentroid = centroid;
            }
        }
        closestCentroid->push_back(point);
    }
}

const std::vector<Position*>& KMean::getPoints()const{
    return points;
}
const std::vector<Centroid*>& KMean::getCentroids()const{
    return centroids;
}
