//
// Created by oreste on 20/10/23.
//

#include "Centroid.h"
#include "Centroid.h"


int Centroid::nextColor = 1;
// Default constructor
Centroid::Centroid() : Position(generateRandomPosition()) {
    std::cout << "Centroid created with Centroid() " << Position::toString() << std::endl;
    //color=Centroid::nextColor++;
}

// Constructor with specified max width and max height
Centroid::Centroid(int maxWidth, int maxHeight) :
Position(generateRandomPosition( rangeRandom(0,800),
                                 rangeRandom(0,600)))
         {
    std::cout << "Centroid created with Centroid(int maxWidth, int maxHeight)" << Position::toString() << std::endl;

}

// Constructor with a specified position, max width, and max height
Centroid::Centroid(const Position& position, int maxWidth, int maxHeight) : Position(position) {
    // You can add custom logic if needed
    std::cout << "Centroid created with Centroid(const Position& position, int maxWidth, int maxHeight)" << Position::toString() << std::endl;

}

Centroid::~Centroid()
{
    //dtor
}
int Centroid::rangeRandom (int min, int max)const{
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do{
        x = rand();
    }while (x >= RAND_MAX - remainder);
    return min + x % n;
}
void Centroid::generateNewCentroidPosition(){
    int sumX=0,sumY=0;
    for(int i=0;i<points.size();i++){
        sumX+=points[i]->getX();
        sumY+=points[i]->getY();
    }
    Position::setX(sumX/points.size());
    Position::setY(sumY/points.size());
}
int Centroid::getRandomNumber(int min,int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
void Centroid::push_back(Position* point) {
    points.push_back(point);
}

const vector<Position *> &Centroid::getPoints() const {
    return points;
}

void Centroid::setPoints(const vector<Position *> &points) {
    Centroid::points = points;
}
void Centroid::clear(){
    points.clear();
}

