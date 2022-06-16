#include "Vec2i.h"

Vec2i::Vec2i(){
    x = 0;
    y = 0;
}

Vec2i::Vec2i(Vec2i* anotherVec2i){
    this->x = anotherVec2i->x;
    this->y = anotherVec2i->y;
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
