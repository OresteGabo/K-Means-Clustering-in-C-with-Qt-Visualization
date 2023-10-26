//
// Created by oreste on 20/10/23.
//

#ifndef K_MEAN_POSITION_H
#define K_MEAN_POSITION_H

#include<string>
#include<math.h>
#include <random>
#include <QColor>

using std::string;
class Position
{
public:
    Position(int x,int y,const QColor&);
    Position(int x,int y);
    Position();
    virtual ~Position();
    Position(const Position& other);

    int getX() const{ return x; }
    void setX(int val) { x = val; }
    int getY() const{ return y; }
    void setY(int val) { y = val; }

    const QColor &getColor() const;

    void setColor(const QColor &color);

    string toString()const;
    double distanceTo(const Position& other) const;
    static Position generateRandomPosition(int maxWidth=800, int maxHeight=600);
    static int getRandomNumber(int min, int max);
    bool operator==(const Position& other) const;

private:
    int x;
    int y;
    QColor color;
};


#endif //K_MEAN_POSITION_H
