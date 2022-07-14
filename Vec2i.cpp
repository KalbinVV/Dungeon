#include "Vec2i.h"
#include <cmath>

Vec2i::Vec2i(){
    x = 0;
    y = 0;
}

Vec2i::Vec2i(Vec2i* anotherVec2i){
    this->x = anotherVec2i->x;
    this->y = anotherVec2i->y;
}

Vec2i::Vec2i(int x, int y){
    this->x = x;
    this->y = y;
}

Vec2i Vec2i::addX(int value){
    Vec2i resultVec(this);
    resultVec.x += value;
    return resultVec;
}

Vec2i Vec2i::addY(int value){
    Vec2i resultVec(this);
    resultVec.y += value;
    return resultVec;
}


int Vec2i::distance(Vec2i anotherVec){
    return std::sqrt(std::pow(anotherVec.x - x, 2) + std::pow(anotherVec.y - y, 2));
}

bool Vec2i::operator==(Vec2i anotherVec){
    return x == anotherVec.x && y == anotherVec.y;
}
