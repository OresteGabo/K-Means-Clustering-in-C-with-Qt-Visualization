//
// Created by oreste on 20/10/23.
//

#include "Position.h"

Position::Position(int x,int y,const QColor&c):x{x},y{y},color{c}
{
    //ctor
}
Position::Position(int x,int y):Position(x,y,Qt::black)
{
    //ctor
}
Position::Position(): Position(0,0,Qt::black)
{
    //ctor
}

Position::~Position()
{
    //dtor
}

Position::Position(const Position& other)
{
    //copy ctor
}
std::string Position::toString() const {
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}
double Position::distanceTo(const Position& other) const {
    int deltaX = x - other.x;
    int deltaY = y - other.y;
    return std::sqrt(static_cast<double>(deltaX * deltaX + deltaY * deltaY));
}
Position Position::generateRandomPosition(int maxWidth, int maxHeight) {
    int randomX = getRandomNumber(0, maxWidth);
    int randomY = getRandomNumber(0, maxHeight);
    return Position(randomX, randomY);
}
int Position::getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

const QColor &Position::getColor() const {
    return color;
}

void Position::setColor(const QColor &color) {
    Position::color = color;
}
bool Position::operator==(const Position& other) const {
    return (x == other.x) && (y == other.y);
}
