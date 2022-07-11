#ifndef VEC2I_H_INCLUDED
#define VEC2I_H_INCLUDED

class Vec2i{
public:
    int x;
    int y;
    Vec2i();
    Vec2i(Vec2i* anotherVec2i);
    Vec2i(int x, int y);
    Vec2i addX(int value);
    Vec2i addY(int value);
    int distance(Vec2i anotherVec);
};

#endif // VEC2I_H_INCLUDED
